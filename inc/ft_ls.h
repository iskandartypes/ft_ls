/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:22:45 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/26 03:49:19 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
# include "libft.h"
# include <dirent.h> //opendir, readdir, closedir
# include <stdlib.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h> //getpwuid, getgrgid (also prev 4)
# include <sys/xattr.h> //listxattr, getxattr
# include <time.h> //time, ctime
# include <sys/stat.h> //stat, lstat
# include <unistd.h> //readlink
# include <stdio.h> //perror
# include <string.h> //strerror
# include <errno.h>

/*
** flags: L/U = lower/upper, followed by letter
** instead of overriding by order given, maybe override by cascade for ease?
*/
# define LS_UA 0x00001	//list all except . & .. DONE
# define LS_UF 0x00002	//dir/ , exec*, socket=, whiteout% (ignore?), fifo| DONE
# define LS_UG 0x00004	//colours! DONE
# define LS_UR 0x00008	//REQ recur on subdirs
# define LS_US 0x00010	//sort by size DONE
# define LS_UT 0x00020	//req -l, display complete time info ie Mar 26 20:01:18 2019 DONE
# define LS_LA 0x00040	//REQ list all w/ . DONE
# define LS_LF 0x00080	//output not sorted, and -a DONE
# define LS_LG 0x00100	//no username in -l (turns on -l) DONE
# define LS_LI 0x00200	//print inode # (doesn't need -l!) DONE
# define LS_LL 0x00400	//REQ long format DONE
# define LS_LN 0x00800	//disp uid and gid as #; turn on -l DONE
# define LS_LP 0x01000	// '/' after directories, similar to F but less intense DONE
# define LS_LR 0x02000	//REQ reverse sort order (rev alpha, oldest first, largest last)
# define LS_LS 0x04000	//output blocksize (lists total like -l, doesn't need -l) DONE
# define LS_LT 0x08000	//REQ sort by mod time (most recent first) and then name DONE
# define LS_LU 0x10000	//time of last access instead of last mod for -t sort and -l DONE
# define LS_MU 0x20000	//multiple args (needs header for each) DONE

/*
** tot: size in b / 512 (rounded up) (given by st_blocks no worries)
** there's a queue of dirs for -R
*/

typedef struct	s_lsdir
{
	int			tot;
	char		*path;
	DIR			*dir;
	t_list		*entries;
	t_queue		*nested;
}				t_lsdir;

//there'll be a ll of these suckers right here, sorted according to flags
//like, after being created obvi (and summing themselves for ^tot)
//need delete func? like to free all the shit inside
//saving d_name to avoid having to save dirent struct
//(other info in dirent duped in stats)
# define SYMBUF 1024

typedef struct	s_lsent
{
	char		*name;
	char		*full_name;
	struct stat	*stats; //v. important, basically inherits from
	char		ftype;	//in handy printable fmt
	char		*perms;
	char		symbuf[SYMBUF];
}				t_lsent;

typedef int		(*ls_comp)(t_list*, t_list*);

/*
** utils handy for -l and not
*/

void			ls_set_color(t_lsent *ent);
void			ls_get_ftype(t_lsent *entry);
void			ls_get_perms(t_lsent *perms);
int				ls_inode_block_skip(t_lsent *ent, long flags);

t_lsdir			*ls_mkdir(char *name, long flags);
void			ls_print(t_lsdir *dir, long flags);
void			ls_rmdir(t_lsdir *dir);

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
