/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:04:11 by rlecart           #+#    #+#             */
/*   Updated: 2017/12/14 01:46:10 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <corewar.h>

typedef struct		s_champ
{
	int				len;
	bool			alive;
	char			*name;
	char			*comment;
	char			*content;
}					t_champ;

int					get_nbc(char **argv);
void				usage(void);
void				battle(t_champ *champs, int nbc);
t_champ				*get_all_champs(char **argv, int nbc);

#endif
