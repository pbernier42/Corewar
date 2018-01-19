/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:15:05 by rlecart           #+#    #+#             */
/*   Updated: 2018/01/19 08:18:01 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	end_ww(t_corewar *d)
{
	if (d->flag_v)
		printw("Aucun champion n'a gagne.\n");
	else
		ft_putstr("Aucun champion n'a gagne.\n");
}

void	end_game(t_champ *champs, t_corewar *d)
{
	int		i;

	i = 0;
	if (d->last_live_call <= 0)
	{
		end_ww(d);
		return ;
	}
	if (d->flag_v)
	{
		printw("Le joueur %d(", i + 1);
		display_champs_color(i + 1);
		printw("%s", champs[d->last_live_call - 1].name);
		printw(") a gagne.\n\n");
		display_champs_color(0);
		printw("Appuyez sur une touche pour continuer.");
	}
	else
	{
		ft_putstr("Le joueur ");
		ft_putnbr(i + 1);
		ft_putstr("(");
		display_champs_color(i + 1);
		ft_putstr(champs[i].name);
		display_champs_color(0);
		ft_putstr(") a gagne.\n");
	}
}

void	game(t_champ *champs, t_corewar *d, char *map)
{
	int		i;
	int		pc;
	t_reg	*t;

	i = -1;
	while (++i < d->nbc)
	{
		if (champs[i].alive)
		{
			t = champs[i].reg;
			while (t)
			{
				if ((pc = map[champs[i].reg->pc]) >= 0)
					d->opcodes[pc](&champs[i], d, t);
				t = t->next;
			}
		}
	}
}
