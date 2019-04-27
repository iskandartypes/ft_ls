/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:47:22 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/26 21:02:39 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	make_entries(t_lsdir *dir, long flags)
{
	struct dirent	*entry;
	t_lsent			*ls_entry;

	while ((entry = readdir(dir->dir)))
	{
		ls_entry = ft_memalloc(sizeof(*ls_entry));
		ls_entry->name = entry->d_name;
		ft_asprintf(&(ls_entry->full_name), "%s/%s", dir->path, entry->d_name);
		ls_entry->stats = malloc(sizeof(*ls_entry->stats));
		lstat(ls_entry->full_name, ls_entry->stats);
		ls_get_ftype(ls_entry);
		ls_get_perms(ls_entry);
		dir->tot += entry->d_name[0] != '.' || flags & (LS_LA | LS_UA) ? \
					ls_entry->stats->st_blocks : 0;
		dir->tot -= flags & LS_UA && (!(ft_strcmp(entry->d_name, ".")) || \
					!(ft_strcmp(entry->d_name, ".."))) ? \
					ls_entry->stats->st_blocks : 0;
		ft_lstaddend(&(dir->entries), ft_lstnew(ls_entry, sizeof(*ls_entry)));
	}
}

/*
** using a dispatch table is actually *less descriptive* than this
** I would have had to pass them manually anyway, only without helpful names
*/

void		ls_sort_ents(t_list **ents, long fl)
{
	ft_lstmsort(ents, fl & LS_LR ? &ls_revalpha : &ls_alphacomp);
	if (fl & LS_US)
		ft_lstmsort(ents, fl & LS_LR ? &ls_revsize : &ls_sizecomp);
	else if (fl & (LS_LT | LS_LU))
		ft_lstmsort(ents, fl & LS_LR ? &ls_revacctime : &ls_acctimecomp);
	else if (fl & LS_LT)
		ft_lstmsort(ents, fl & LS_LR ? &ls_revmodtime : &ls_modtimecomp);
}

t_lsdir		*ls_mkdir(char *name, long flags)
{
	t_lsdir	*dir;

	dir = ft_memalloc(sizeof(*dir));
	ft_asprintf(&(dir->path), "%s", name);
	dir->dir = opendir(dir->path);
	dir->entries = NULL;
	if (!dir->dir)
		return (dir);//is this a good idea?
	make_entries(dir, flags);
	ls_sort_ents(&(dir->entries), flags);
	flags & LS_UR ? ls_queue_dirs(dir, flags) : 0;
	return (dir);
}

 void		ls_rmentries(t_list *entries)
{
	t_list	*run;
	t_lsent	*entry;

	if (!entries)
		return ;
	run = entries->next;
	entry = entries->content;
	free(entry->full_name);
	free(entry->stats);
	free(entry->perms);
	free(entries);
	if (run)
		ls_rmentries(run);
}

void		ls_rmdir(t_lsdir *dir)
{
	ls_rmentries(dir->entries);
	free(dir->path);
	closedir(dir->dir);
	free(dir->nested);
	free(dir);
	dir = NULL;
}
