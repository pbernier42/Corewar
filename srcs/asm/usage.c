/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:39:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/07 20:22:18 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	usage(t_asm *e, int argc, char *av)
{
	int	len;

	if (argc != 2)
		error(e, NB_ARG);
	len = ft_strlen(av);
	if (av[len - 2] != '.' &&
		av[len - 1] != 's')
		error(e, EXTENTION);
	if ((e->champ.fd = open(av, O_RDONLY)) < 2)
		error(e, OPEN_CHAMP);
	e->champ.file_path = av;
	len -= 3;
	while (len > 0 && av[len] != '/')
		--len;
	if (!(e->champ.file_name = ft_strsub(av, len + 1, ft_strlen(av) - len - 3)))
		error(e, MALLOC);
}
