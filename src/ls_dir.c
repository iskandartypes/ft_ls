/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:47:22 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/01 19:55:36 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	make_entries(t_lsdir *dir)
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
		dir->tot += ls_entry->stats->st_blocks;
		ft_lstaddend(&(dir->entries), ft_lstnew(ls_entry, sizeof(*ls_entry)));
	}
}

//it feels like you are going to have problems with recursive stuff?
//unless you pass in dir->path as name?
//maybe you will need prefix string? dir->path as prefix string
//(base case prefix string is "")
t_lsdir	*ls_mkdir(char *name, long flags)
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

void	ls_print(t_lsdir *dir, long flags)
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

void	ls_rmdir(t_lsdir *dir)
{
	//TODO: free all stats in each entry
	//free all entries
	free(dir->path);
	closedir(dir->dir);
	//free dir
}
