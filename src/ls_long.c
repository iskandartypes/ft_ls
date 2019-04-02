/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:58:38 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/01 21:14:12 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** test executable first, so subsequent calls override if x but !reg file
*/

void	ls_set_color(mode_t mode)
{
	(mode & (S_IXUSR | S_IXGRP | S_IXOTH)) ? ft_printf("%{red}") : 0;
	S_ISFIFO(mode) ? ft_printf("%{yellow}") : 0;
	S_ISCHR(mode) ? ft_printf("%[yellow]%{blue}") : 0;
	S_ISDIR(mode) ? ft_printf("%{blue}") : 0;
	S_ISBLK(mode) ? ft_printf("%[cyan]%{blue}") : 0;
	S_ISLNK(mode) ? ft_printf("%{magenta}") : 0;
	S_ISSOCK(mode) ? ft_printf("%{green}") : 0;
	//ex w/gid: cyan back black text
	//ex w/uid: red back black text
	//other write dir: yellow back black text
	//other write dir sticky bit: green back black text
}

/*
** in rough order of common appearance, to save time
** for both 'l' flag (common) and 'F' flag (less common)
** ^ triggers on int lf (# for l, 0 for F)
*/

void	ls_get_ftype(t_lsent *entry)
{
	mode_t	mode;
	
	mode = entry->stats->st_mode;
	if (S_ISREG(mode))
	{
		entry->ftype = '-';
		if (mode & (S_IXUSR | S_IXGRP | S_IXOTH))
			entry->exec = '*';
	}
	else if (S_ISDIR(mode))
		entry->ftype = 'd';
	else if (S_ISLNK(mode))
		entry->ftype = 'l';
	else if (S_ISFIFO(mode))
		entry->ftype = 'p';
	else if (S_ISSOCK(mode))
		entry->ftype = 's';
	else if (S_ISCHR(mode))
		entry->ftype = 'c';
	else if (S_ISBLK(mode))
		entry->ftype = 'b';
}

void	ls_get_perms(t_lsent *entry)
{
	mode_t	mode;
	char	ux;
	char	gx;
	char	ox;

	mode = entry->stats->st_mode;
	ux = mode & S_IXUSR ? 'x' : '-';
	if (mode & S_ISUID)
		ux = ux == 'x' ? 's' : 'S';
	gx = mode & S_IXGRP ? 'x' : '-';
	if (mode & S_ISGID)
		gx = gx == 'x' ? 's' : 'S';
	ox = mode & S_IXOTH ? 'x' : '-';
	if (mode & S_ISVTX)
		ox = ox == 'x' ? 't' : 'T';
	ft_asprintf(&(entry->perms), "%d%d%d%d%d%d%d%d%d", mode & S_IRUSR ? 'r' : '-'\
			, mode & S_IWUSR ? 'w' : '-', ux, mode & S_IRGRP ? 'r' : '-', \
			mode & S_IWGRP ? 'w' : '-', gx, mode & S_IROTH ? 'r' : '-', \
			mode & S_IWOTH ? 'w' : '-', ox);
}

void	ls_print_long(struct dirent *entry, char *path, int f)
{
	char		*full;
	struct stat	stats;

//	ft_asprintf(&full, "%s/%s", path, entry->d_name);
//	stat(full, &stats);
//	print_ftype(stats.st_mode, 1);
//	print_perm(stats.st_mode);

}
