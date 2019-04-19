/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:36:43 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/18 17:15:09 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** stores opts in flags; if illegal opt, option is at av[0][0]
*/

char	**ls_parse_flags(char **av, long *flags)
{
	int i;

	while ( *av && (*av)[0] == '-' && (*av)[1])
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
	*flags |= (*flags & (LS_LN | LS_LG)) ? LS_LL : 0;
	return (av);
}

/*
** that funny num_dirs conditional in the while is putting
** newlines between multiple directories;
** it's a "don't put a newline before the first entry" check
*/

int		main(int ac, char **av)
{
	t_lsdir			*dir;
	long			flags;
	int				num_dirs;

	flags = 0;
	num_dirs = 0;
	while (ac > 1 && av[--ac][0] != '-')
		num_dirs++;
	if (num_dirs > 1)
		flags |= LS_MU;
	av = ls_parse_flags(av + 1, &flags);
	if (flags == -1)
		return (ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls "
					"[-AFGRSTafgilnprstu] [file ...]\n", av[0][0]));
	dir = ls_mkdir(*av ? *av++ : ".", flags, 0);
	ls_print(dir, flags);
	ls_rmdir(dir);
	while (*av)
	{
		ft_putchar('\n');
		dir = ls_mkdir(*av++, flags, 0);
		ls_print(dir, flags);
		ls_rmdir(dir);
	}
	return (0);
}
