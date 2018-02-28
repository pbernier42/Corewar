/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:44:24 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/28 07:24:32 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_add(t_champ *champs, t_corewar *d, t_reg *reg)
{
	int		i;
	int		pc;
	int		r[3];
	t_ocp	ocp;

	(void)champs;
	if (++reg->cycle == 10 && !(reg->cycle = 0))
	{
		i = -1;
		(pc = reg->pc + 1) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
		ocp = find_ocp(d->map[pc]);
		if (!valid_ocp(ocp) && (false_command(d, reg, true)))
			return ;
		while (++i < 3)
		{
			(++pc) >= MEM_SIZE ? pc -= MEM_SIZE : pc;
			if (((r[i] = d->map[pc] - 1) < 0 || r[i] > 16) &&
					(false_command(d, reg, true)))
				return;
		}
		reg->r[r[2]] = reg->r[r[0]] + reg->r[r[1]];
		jump_to_next(d, reg, 5, false);
		reg->carry = !reg->r[r[2]] ? 1 : 0;
	}
}
