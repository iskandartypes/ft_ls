/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:16:35 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/26 21:32:43 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** these sort, print and delete the t_list of names
*/

static void	print_notnames(t_list *notnames)
{
	t_list	*tmp;

	ft_lstmsort(&notnames, &ls_basic_alphacomp);
	while (notnames)
	{
		tmp = notnames;
		notnames = notnames->next;
		ft_dprintf(2, "ft_ls: %s: %s\n", (char*)tmp->content, strerror(errno));
		free(tmp);
	}
}

static void	print_fnames(t_list *fnames, long fl)
{
	t_list	*run;
	t_lsent	*ent;

	fl |= LS_LA;
	ls_sort_ents(&fnames, fl);
	if (fl & LS_LL)
		ls_lprint(fnames, fl);
	else
	{
		run = fnames;
		while (run)
		{
			ent = run->content;
			ls_inode_block_skip(ent, fl);
			ls_print_name(ent, fl);
			run = run->next;
		}
	}
	ls_rmentries(fnames);
}

static void	print_dnames(t_list *dnames, long flags)
{
	t_lsdir	*dir;
	t_list	*run;
	int		first;

	if (!dnames)
	{
		dir = ls_mkdir(".", flags);
		ls_print(dir, flags);
		ls_print_q(dir, flags);
		ls_rmdir(dir);
		return ;
	}
	first = 1;
	ls_sort_ents(&dnames, flags);
	run = dnames;
	while (run)
	{
		first ? first = 0 : ft_putchar('\n');
		dir = ls_mkdir(((t_lsent*)(run->content))->name, flags);
		ls_print(dir, flags);
		ls_print_q(dir, flags);
		ls_rmdir(dir);
		run = run->next;
	}
	ls_rmentries(dnames);
}

/*
** this gets and separates fnames and dnames, and then sort them alphabetically
*/

static void	name_sort_print(t_list **nnm, t_list **fnm, t_list **dnm, long fl)
{
	int		dflag;
	int		nflag;

	nflag = *fnm && *dnm;
	dflag = *nnm || *fnm;
	if (*nnm)
		print_notnames(*nnm);
	if (*fnm)
		print_fnames(*fnm, fl);
	if (nflag)
		ft_putchar('\n');
	if (*dnm || !(dflag))
		print_dnames(*dnm, fl);
}

void		ls_get_names(char **av, long fl)
{
	t_list		**notnames;
	t_list		**fnames;
	t_list		**dnames;
	struct stat	*stats;

	notnames = ft_memalloc(sizeof(*notnames));
	fnames = ft_memalloc(sizeof(*fnames));
	dnames = ft_memalloc(sizeof(*dnames));
	stats = ft_memalloc(sizeof(*stats));
	while (*av)
	{
		if (stat(*av, stats) == -1)
			ft_lstadd(notnames, ft_lstnew(*av, ft_strlen(*av) + 1));
		else
			ft_lstadd(S_ISDIR(stats->st_mode) ? dnames : fnames, \
				ft_lstnew(ls_init_entry(*av), sizeof(t_lsent)));
		av++;
	}
	name_sort_print(notnames, fnames, dnames, fl);
	free(notnames);
	free(fnames);
	free(dnames);
	free(stats);
}
