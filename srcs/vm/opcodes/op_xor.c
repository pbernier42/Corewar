/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:45:37 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/15 19:18:30 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_xor_loop(t_corewar *d, t_reg *reg, t_ocp o, int pc)
{
	int		i;
	int		r[3];
	int		len[2];

	i = -1;
	len[1] = 0;
	while (++i < 3)
	{
		len[0] = 1;
		if (o.p[i] == O_DIR && (len[0] = 4))
			r[i] = find_hexa(d->map, pc, len[0]);
		else if (o.p[i] == O_IND && (len[0] = 2))
		{
			if ((r[i] = find_hexa(d->map, pc, len[0])) > 65535 / 2)
				r[i] -= 65535;
			r[i] = find_hexa(d->map, pc + r[i] - len[0] - 1, len[0] + 2);
		}
		else
			r[i] = d->map[pc] - 1;
		(pc += len[0]) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		len[1] += len[0];
	}
	reg->r[r[2]] = r[0] ^ r[1];
	jump_to_next(d, reg, len[1] + 2, false);
}

void	op_xor(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		pc;
	t_ocp	o;

	(void)champs;
	if (++reg->cycle == 8)
	{
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		o = find_ocp(d->map[pc]);
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		op_xor_loop(d, reg, o, pc);
		reg->carry = 1;
		reg->cycle = 0;
	}
}