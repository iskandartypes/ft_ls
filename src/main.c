/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:36:43 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/26 22:09:44 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** stores opts in flags; if illegal opt, option is at av[0][0]
*/

char	**ls_parse_flags(char **av, long *flags)
{
	int i;

	while (*av && (*av)[0] == '-' && (*av)[1])
	{
		(*av)++;
		while (**av)
		{
			i = ft_charat("AFGRSTafgilnprstu\0", **av);
			if (i == -1 && (*flags = -1))
				break ;
			*flags |= (1l << i);
			(*av)++;
		}
		if (i == -1)
			break ;
		av++;
	}
	*flags |= (*flags & LS_LF) ? LS_LA : 0;
	*flags &= (*flags & LS_UA) && (*flags & LS_LA) ? ~LS_UA : ~0l;
	*flags |= (*flags & (LS_LN | LS_LG)) ? LS_LL : 0;
	return (av);
}

/*
** I don't know why norminette wants the ls_get_names indented like that,
** but it does and I am not going to argue for right now
*/

int		main(int ac, char **av)
{
	long			flags;
	int				num_args;

	flags = 0;
	num_args = 0;
	while (ac > 1 && av[--ac][0] != '-')
		num_args++;
	if (num_args > 1)
		flags |= LS_MU;
	av = ls_parse_flags(av + 1, &flags);
	if (flags == -1)
		return (ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls "
			"[-AFGRSTafgilnprstu] [file ...]\n", av[0][0]));
		ls_get_names(av, flags);
	return (0);
}
