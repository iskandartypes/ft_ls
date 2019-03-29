/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:36:43 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/28 19:47:30 by ikourkji         ###   ########.fr       */
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
			i = ft_charat("AFGRSTUafgilnprstu\0", **av);
			if (i == -1 && (*flags = -1))
				break ;
			*flags |= (1l << i);
			(*av)++;
		}
		if (i == -1)
			break ;
		av++;
	}
	return (av);
}

void	ls_print_dir(DIR *dir, long flags)
{
	struct dirent	*entry;
	struct stat		stats;
	while((entry = readdir(dir)))
	{
		if (entry->d_name[0] != '.' || flags & LS_LA || flags & LS_LF)
		{
			stat(entry->d_name, &stats);
			//^ won't work right for symlinks, only works for curdir bc
			//dirent->d_name is fname not path (use sprintf to append dir?)
			if (flags & LS_UG)
				ls_set_color(stats.st_mode);
			ft_printf("%-20s %d %d\n", entry->d_name, stats.st_uid, stats.st_size);
			if (flags & LS_UG)
				ft_printf("%{}");
		}
	}
}

int		main(int ac, char **av)
{
	//you will have to make this a struct so that you can handle -R
	DIR				*dir;
	long			flags;

	flags = 0;
	if (ac == 1)
		dir = opendir(".");
	else
	{
		av = ls_parse_flags(av + 1, &flags);
		if (flags == -1)
			return (ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls "
						"[-AFGRSTUafgilnprstu] [file ...]\n", av[0][0]));
		ft_printf("flags: %015b\n", flags);
		dir = *av ? opendir(*av) : opendir(".");
	}
	ls_print_dir(dir, flags);
	closedir(dir);
	return (0);
}
