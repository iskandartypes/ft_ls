/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 03:13:57 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/26 04:13:06 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_queue_dirs(t_lsdir *dir, long fl)
{
	t_list	*run;
	t_lsent	*ent;

	run = dir->entries;
	dir->nested = ft_qinit();
	while (run)
	{
		ent = run->content;
		if (ent->ftype == 'd' && ft_strcmp(ent->name, ".") != 0 && \
				ft_strcmp(ent->name, "..") != 0 && \
				(ent->name[0] != '.' || fl & (LS_LA | LS_UA)))
		{
			ft_enqueue(dir->nested, ls_mkdir(ent->full_name, fl));
	//		ft_printf("%{red}enqueued: %s\n%{}", ent->full_name);
		}
		run = run->next;
	}
}

void	ls_print_q(t_lsdir *dir, long fl)
{
	t_lsdir	*child;

	if (!(fl & LS_UR))
		return ;
	while (!ft_qis_empty(dir->nested))
	{
		ft_putchar('\n');
		child = ft_dequeue(dir->nested);
	//	ft_printf("%{green}dequeued: %s\n%{}", child->path);
		ls_print(child, fl);
		ls_print_q(child, fl);
		ls_rmdir(child);
	}
}
