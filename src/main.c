/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:36:43 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/27 02:00:06 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ls_parse_flags(char **av, int *flags)
{
	ft_printf("%s %s\n", av[0], av[1]);
	while ( *av && (*av)[0] == '-' && (*av)[1])
	{
		(*av)++;
		while (**av)
		{
			*flags |= **av == 'l' ? LS_LL : 0;
			*flags |= **av == 'R' ? LS_UR : 0;
			*flags |= **av == 'a' ? LS_LA : 0;
			*flags |= **av == 'r' ? LS_LR : 0;
			*flags |= **av == 't' ? LS_LT : 0;
			*flags |= **av == 'G' ? LS_UG : 0;
			*flags |= **av == 'p' ? LS_LP : 0;
			*flags |= **av == 'f' ? LS_LF : 0;
			*flags |= **av == 'h' ? LS_LH : 0;
			*flags |= **av == 'i' ? LS_LI : 0;
			*flags |= **av == 'S' ? LS_US : 0;
			*flags |= **av == 'T' ? LS_UT : 0;
			*flags |= **av == 'u' ? LS_LU : 0;
			*flags |= **av == 'U' ? LS_UU : 0;
			*flags |= **av == 'g' ? LS_LG : 0;
			(*av)++;
		}
		av++;
	}
	return (av);
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
			ft_printf("%-20s %d\n", entry->d_name, stats.st_size);
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
		ft_printf("flags: %015b\n", flags);
		dir = *av ? opendir(*av) : opendir(".");
	}
	ls_print_dir(dir, flags);
	closedir(dir);
	return (0);
}
