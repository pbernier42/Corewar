/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:18 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/08 20:40:47 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		find_ind_lldi(t_corewar *d, t_reg *reg, int param)
{
	if (param > 65536 / 2)
		param -= 65536;
	param = find_hexa(d->map, reg->pc + param, 2);
	return (param);
}

void	lldi_norm(int tpc[2], t_reg *reg, int r[2], t_corewar *d)
{
	tpc[0] = reg->pc + (r[0] + r[1]);
	true_pc(&tpc[0]);
	reg->carry = 0;
	if (r[2] >= 1 && r[2] <= 16)
	{
		reg->r[r[2] - 1] = find_hexa(d->map, tpc[0], 4);
		reg->carry = !reg->r[r[2] - 1] ? 1 : 0;
	}
	jump_to_next(reg, tpc[1] - reg->pc);
}

int		lldi_norm2(t_corewar *d, t_reg *reg, t_need_norm *n)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		n->tpc[0] = n->ocp.p[i] == O_REG ? 1 : 2;
		n->r[i] = find_hexa(d->map, n->tpc[1], n->tpc[0]);
		if (i < 2 && n->ocp.p[i] == O_REG && n->r[i] >= 1 && n->r[i] <= 16)
			n->r[i] = reg->r[n->r[i] - 1];
		else if (i < 2 && n->ocp.p[i] == O_REG && (false_cmd(d, reg, true)))
			return (-1);
		else if (n->ocp.p[i] == O_IND)
			n->r[i] = find_ind_lldi(d, reg, n->r[i]);
		else if (n->ocp.p[i] == O_DIR && n->r[i] > 65536 / 2)
			n->r[i] -= 65536;
		(n->tpc[1] += n->tpc[0]) >= MEM_SIZE ?
			n->tpc[1] -= MEM_SIZE : n->tpc[1];
	}
	return (0);
}

void	op_lldi(t_corewar *d, t_reg *reg)
{
	int				i;
	int				tpc[2];
	int				r[3];
	t_ocp			ocp;
	t_need_norm		n;

	if (++reg->cycle == 25 && !(reg->cycle = 0))
	{
		i = -1;
		(tpc[1] = reg->pc + 1) >= MEM_SIZE ? tpc[1] -= MEM_SIZE : tpc[1];
		if (!(find_ocp(&ocp, d->map[reg->pc], d->map[tpc[1]])) &&
				(false_cmd(d, reg, true)))
			return ;
		(++tpc[1]) >= MEM_SIZE ? tpc[1] -= MEM_SIZE : tpc[1];
		ft_memcpy(n.r, r, 3 * sizeof(int));
		ft_memcpy(n.tpc, tpc, 2 * sizeof(int));
		ft_memcpy(n.ocp.p, ocp.p, 3 * sizeof(int));
		if (!(lldi_norm2(d, reg, &n)))
			lldi_norm(n.tpc, reg, n.r, d);
	}
}
