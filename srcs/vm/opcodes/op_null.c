/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:54:09 by rlecart           #+#    #+#             */
/*   Updated: 2018/02/06 01:00:37 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	op_null(t_champ *champs, t_corewar *d, t_reg *reg)
{
	jump_to_next(d, reg, 1, false);
	(void)champs;
}
