/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:36:43 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/27 01:13:15 by ikourkji         ###   ########.fr       */
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
	if (*flags != -1)
	{
		*flags |= (*flags & LS_LF) ? LS_LA : 0;
		*flags |= (*flags & (LS_LN | LS_LG)) ? LS_LL : 0;
		if ((*flags & LS_UA) && (*flags & LS_LA))
			*flags &= ~LS_UA;
	}
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
