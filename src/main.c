/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:36:43 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/28 13:16:46 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** stores opts in flags; if illegal opt, option is at av[0][0]
*/

char	**ls_parse_flags(char **av, int *flags)
{
	int i;

	while ( *av && (*av)[0] == '-' && (*av)[1])
	{
		(*av)++;
		while (**av)
		{
			i = ft_charat("lRartGpFhiSTuUg\0", **av);
			if (i == -1 && (*flags = -1))
				break ;
			*flags |= (1 << i);
			(*av)++;
		}
		if (i == -1)
			break ;
		av++;
	}
	return (av);
}

/*
** test executable first, so subsequent calls override if x but !reg file
*/

void	ls_set_color(struct stat *stats)
{
	(stats->st_mode & S_IXUSR) || (stats->st_mode & S_IXGRP) ||\
		(stats->st_mode & S_IXOTH) ? ft_printf("%{red}") : 0;
	S_ISFIFO(stats->st_mode) ? ft_printf("%{yellow}") : 0;
	S_ISCHR(stats->st_mode) ? ft_printf("%[yellow]%{blue}") : 0;
	S_ISDIR(stats->st_mode) ? ft_printf("%{blue}") : 0;
	S_ISBLK(stats->st_mode) ? ft_printf("%[cyan]%{blue}") : 0;
	S_ISLNK(stats->st_mode) ? ft_printf("%{magenta}") : 0;
	S_ISSOCK(stats->st_mode) ? ft_printf("%{green}") : 0;

}

void	ls_print_dir(DIR *dir, int flags)
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
				ls_set_color(&stats);
			ft_printf("%-20s %d\n", entry->d_name, stats.st_size);
			if (flags & LS_UG)
				ft_printf("%{}");
		}
	}
}

int		main(int ac, char **av)
{
	//you will have to make this a struct so that you can handle -R
	DIR				*dir;
	int				flags;

	flags = 0;
	if (ac == 1)
		dir = opendir(".");
	else
	{
		av = ls_parse_flags(av + 1, &flags);
		if (flags == -1)
			return (ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls "
						"[-GRSTUafghilptu] [file ...]\n", av[0][0]));
		ft_printf("flags: %015b\n", flags);
		dir = *av ? opendir(*av) : opendir(".");
	}
	ls_print_dir(dir, flags);
	closedir(dir);
	return (0);
}
