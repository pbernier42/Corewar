/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 04:14:13 by rlecart           #+#    #+#             */
/*   Updated: 2018/03/10 08:54:52 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

bool	false_command(t_corewar *d, t_reg *reg, bool carry)
{
	jump_to_next(d, reg, 1, false);
	if (carry)
		reg->carry = 0;
	return (true);
}

bool	valid_ocp(t_ocp *ocp, unsigned char op)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = 0;
	while (++i < 3)
	{
		if (ocp->p[i] == O_NONE)
			tmp++;
		if ((g_op_tab[op].type[i] & ocp->p[i]) != ocp->p[i])
			return (false);
	}
	if (tmp != 3 - g_op_tab[op].nb_params)
		return (false);
	return (true);
}

void	true_pc(int *pc)
{
	while (*pc >= MEM_SIZE || *pc < 0)
	{
		if (*pc >= MEM_SIZE)
			*pc -= MEM_SIZE;
		else
			*pc += MEM_SIZE;
	}
}

void	put_hexa(t_corewar *d, int nbc, int pc, int value)
{
	int		i;
	int		len;

	i = -1;
	len = 4;
	true_pc(&pc);
	while (++i < len)
	{
		d->map[pc] = value >> 8 * (len - i - 1);
		d->colors[pc] = nbc;
		(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
	}
}
