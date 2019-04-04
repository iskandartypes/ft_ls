/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:39:43 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/04 15:51:36 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//need to store max hardlinks to get spacing right
//(link padding is one space before len maxlinks)
//actually padding is one space before maxlen of every param
//... you will either need to do something weird or implement wild (*) in pf
//^maybe implement * (takes arg for fw/prec) w/out $ (which is not arg?)
//(to get variable-width padding to format everything properly)
//(AND store maxlen for every param in dir) (maybe a maxlen struct??)
//"ent" for convenience
static void	lprint(t_lsdir *dir, long flags)
{
	t_list			*run;
	t_lsent			*ent;
	struct passwd	*uid;
	struct group	*gid;

	ft_printf("total %d\n", dir->tot);
	run = dir->entries;
	while (run)
	{
		//TODO: time! struct? so many structs
		ent = run->content;
		uid = getpwuid(ent->stats->st_uid);
		gid = getgrgid(ent->stats->st_gid);
		ft_printf("%c%s  %3d %s  %s %6ld %s\n", \
				ent->ftype, ent->perms, ent->stats->st_nlink, \
				uid->pw_name, gid->gr_name, ent->stats->st_size, ent->name);
		run = run->next;
	}
}

void		ls_print(t_lsdir *dir, long flags)
{
	t_list	*run;

	if (flags & LS_LL)
		lprint(dir, flags);
	else
	{
		run = dir->entries;
		while (run)
		{
			//can do all sorts of flag stuff here, including
			//(a) pass to longprint
			//(b) color print
			ft_printf("%s\n", ((t_lsent*)(run->content))->name);
			run = run->next;
		}
	}
}
