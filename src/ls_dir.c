/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:47:22 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/29 23:32:08 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	make_entries(t_lsdir dir)
{
	struct dirent	*entry;
	t_lst			*entrun;
	t_lsent			*ls_entry;

	entrun = dir->entries;
	while (entry = readdir(dir->path))
	{
		ls_entry = malloc(sizeof(*ls_entry));
		ls_entry->name = entry->d_name;
		entrun = ft_lstnew(ls_entry, sizeof(*ls_entry));
		ft_asprintf(&(ls_entry->full_name), "%s/%s", dir->path, entry->name);
		stat(ls_entry->full_name, entrun->stats);
		dir->tot += entrun->stats->st_size;
		entrun = entrun->next;
	}
}

t_lsdir	*ls_mkdir(char *name, long flags)
{
	t_lsdir	*dir;

	dir = malloc(sizeof(*dir));
	dir->tot = 0;
	ft_asprintf(&(dir->path), "./%s", name);
	dir->dir = opendir(dir->path);
	//sort here? need flags for sort
	return (ret);
}

void	ls_print(t_lsdir dir)
{
	//TODO: errythang
}

void	ls_rmdir(t_lsdir dir)
{
	//TODO: free all stats in each entry
	//free all entries
	free(dir->path);
	closedir(dir->dir);
	//free dir
}
