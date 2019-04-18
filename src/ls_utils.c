/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:58:38 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/18 02:34:25 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** executable, pipe, directory, symbolic link, socket, executable with setuid,
** executable with setgid, other permissable executable w/out sticky and with
*/

void	ls_set_color(t_lsent *ent)
{
	if (ent->ftype == 'd')
		ft_printf("%{blue}");
	else if (ft_charat(ent->perms, 'x') > -1)
	   	ft_printf("%{red}");
	if (ent->ftype == 'p')
	   	ft_printf("%{yellow}");
	else if (ent->ftype == 'l')
		ft_printf("%{magenta}");
	else if (ent->ftype == 's')
		ft_printf("%{green}");
	if (ent->ftype == '-' && ent->perms[2] == 's')
		ft_printf("%{black}%[red]");
	else if (ent->ftype == '-' && ent->perms[5] == 's')
		ft_printf("%{black}%[cyan]");
	if (ent->ftype == 'd' && ft_charat(ent->perms + 3, 'w') > -1)
		(ent->perms[8] == 't' || ent->perms[8] == 'T') ? \
				ft_printf("%{black}%[green]") : ft_printf("%{black}%[yellow]");
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
	ft_asprintf(&(entry->perms), "%c%c%c%c%c%c%c%c%c", mode & S_IRUSR ? 'r' : '-'\
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
