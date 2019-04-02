/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:47:22 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/01 22:32:21 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	make_entries(t_lsdir *dir)
{
	struct dirent	*entry;
	t_lsent			*ls_entry;

	ft_printf("enter make entries\n");
	while ((entry = readdir(dir->dir)))
	{
		ls_entry = malloc(sizeof(*ls_entry));
		ls_entry->name = entry->d_name;
		ft_asprintf(&(ls_entry->full_name), "%s/%s", dir->path, entry->d_name);
		ls_entry->stats = malloc(sizeof(*ls_entry->stats));
		stat(ls_entry->full_name, ls_entry->stats);
		ls_get_ftype(ls_entry);
		ls_get_perms(ls_entry);
		dir->tot += ls_entry->stats->st_blocks;
		ft_lstaddend(&(dir->entries), ft_lstnew(ls_entry, sizeof(*ls_entry)));
	}
}

/*
** using a dispatch table is actually *less descriptive* than this
** I would have had to pass them manually anyway, only without helpful names
*/

static void	sort_ents(t_list *ents, long fl)
{
	if (fl & LS_LF)
	{
		fl |= LS_LA;
		return ;
	}
	ft_lstmsort(&ents, fl & LS_LR ? &ls_revalpha : &ls_alphacomp);
	if (fl & LS_US)
		ft_lstmsort(&ents, fl & LS_LR ? &ls_revsize : &ls_sizecomp);
	else if (fl & LS_LT)
		ft_lstmsort(&ents, fl & LS_LR ? &ls_revmodtime : &ls_modtimecomp);
	else if (fl & LS_LU)
		ft_lstmsort(&ents, fl & LS_LR ? &ls_revacctime : &ls_acctimecomp);
}

//it feels like you are going to have problems with recursive stuff?
//unless you pass in dir->path as name?
//maybe you will need prefix string? dir->path as prefix string
//(base case prefix string is "")
t_lsdir		*ls_mkdir(char *name, long flags)
{
	t_lsdir	*dir;

	dir = ft_memalloc(sizeof(*dir));
	if (name[0] == '.')
		name += (name[1] == '/' ? 2 : 1);
	ft_asprintf(&(dir->path), name[0] ? "./%s" : ".", name);
	dir->dir = opendir(dir->path);
	make_entries(dir);
	//sort here? need flags for sort
	return (dir);
}

void		ls_print(t_lsdir *dir, long flags)
{
	t_list	*run;

	ft_printf("enter ls_print\n");
	run = dir->entries;
	while (run)
	{
		//can do all sorts of flag stuff here, including
		//(a) pass to longprint
		//(b) color print
		ft_printf("%s\n", ((t_lsent*)(run->content))->full_name);
		run = run->next;
	}
}

static void	rmentries(t_list *entries)
{
	t_list	*run;
	t_lsent	*entry;

	if (!entries)
		return ;
	run = entries->next;
	entry = entries->content;
	//free(entry->name); ??
	free(entry->full_name);
	free(entry->stats);
	free(entry->perms);
	free(entries);
	//free(entry->owner);
	if (run)
		rmentries(run);
}

void		ls_rmdir(t_lsdir *dir)
{
	rmentries(dir->entries);
	free(dir->path);
	closedir(dir->dir);
	free(dir);
}
