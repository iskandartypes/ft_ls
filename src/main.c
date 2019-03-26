/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:36:43 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/26 07:54:37 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	//you will have to make this a struct so that you can handle -R
	DIR				*dir;
	struct dirent	*entry;
	struct stat		stats;

	if (ac == 1)
		dir = opendir(".");
	else
		dir = opendir(av[1]);
	while((entry = readdir(dir)))
	{
		stat(entry->d_name, &stats);
		//^ won't work right for symlinks, only works for curdir bc
		//dirent->d_name is fname not path (use sprintf to append dir?)
		ft_printf("%-20s %d\n", entry->d_name, stats.st_size);
	}
	closedir(dir);
	return (0);
}
