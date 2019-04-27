/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:22:45 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/26 22:20:06 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
** yes, in the future, I'll start having the appropriate headers in the files
** and *not* all here like an absolute madman
*/

# include "ft_printf.h"
# include "libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

/*
** flags: L/U = lower/upper, followed by letter
** instead of overriding by order given, maybe override by cascade for ease?
**
** LS_UA	list all except . & ..
** LS_UF	dir/ , exec*, socket=, symlink@, fifo|
** LS_UG	colours!
** LS_UR	REQ recur on subdirs
** LS_US	sort by size
** LS_UT	req -l, display complete time info ie Mar 26 20:01:18 2019
** LS_LA	REQ list all w/ .
** LS_LF	output not sorted, and -a
** LS_LG	no username in -l (turns on -l)
** LS_LI	print inode # (doesn't need -l!)
** LS_LL	REQ long format
** LS_LN	disp uid and gid as #; turn on -l
** LS_LP	 '/' after directories, similar to F but less intense
** LS_LR	REQ reverse sort order (rev alpha, oldest first, largest last)
** LS_LS	output blocksize (lists total like -l, doesn't need -l)
** LS_LT	REQ sort by mod time (most recent first) and then name
** LS_LU	time of last access instead of last mod for -t sort and -l
** LS_MU	multiple args (needs header for each)
*/

# define LS_UA 0x00001
# define LS_UF 0x00002
# define LS_UG 0x00004
# define LS_UR 0x00008
# define LS_US 0x00010
# define LS_UT 0x00020
# define LS_LA 0x00040
# define LS_LF 0x00080
# define LS_LG 0x00100
# define LS_LI 0x00200
# define LS_LL 0x00400
# define LS_LN 0x00800
# define LS_LP 0x01000
# define LS_LR 0x02000
# define LS_LS 0x04000
# define LS_LT 0x08000
# define LS_LU 0x10000
# define LS_MU 0x20000

/*
** tot: size in b / 512 (rounded up) (given by st_blocks no worries)
** there's a queue of dirs for -R
** and a flag that's like "whoa please title my directory" because
** -R has weird behaviour around directory titles in that the first
** doesn't have a title but its children do
*/

typedef struct	s_lsdir
{
	int			tot;
	char		*path;
	DIR			*dir;
	t_list		*entries;
	t_queue		*nested;
	int			r_notfirst;
}				t_lsdir;

# define SYMBUF 1024

typedef struct	s_lsent
{
	char		*name;
	char		*full_name;
	struct stat	*stats;
	char		ftype;
	char		*perms;
	char		symbuf[SYMBUF];
}				t_lsent;

/*
** utils handy for -l and not
*/

void			ls_set_color(t_lsent *ent);
void			ls_get_ftype(t_lsent *entry);
void			ls_get_perms(t_lsent *perms);
int				ls_inode_block_skip(t_lsent *ent, long flags);

t_lsdir			*ls_mkdir(char *name, long flags);
void			ls_sort_ents(t_list **ents, long fl);
void			ls_print(t_lsdir *dir, long flags);
void			ls_lprint(t_list *run, long flags);
void			ls_print_name(t_lsent *ent, long flags);
void			ls_rmentries(t_list *entries);
void			ls_rmdir(t_lsdir *dir);

t_lsent			*ls_init_entry(char *path);

void			ls_queue_dirs(t_lsdir *dir, long fl);
void			ls_print_q(t_lsdir *dir, long fl);

void			ls_get_names(char **av, long fl);
int				ls_basic_alphacomp(t_list *n1, t_list *n2);

int				ls_alphacomp(t_list *n1, t_list *n2);
int				ls_revalpha(t_list *n1, t_list *n2);
int				ls_modtimecomp(t_list *n1, t_list *n2);
int				ls_revmodtime(t_list *n1, t_list *n2);
int				ls_acctimecomp(t_list *n1, t_list *n2);
int				ls_revacctime(t_list *n1, t_list *n2);
int				ls_sizecomp(t_list *n1, t_list *n2);
int				ls_revsize(t_list *n1, t_list *n2);

#endif
