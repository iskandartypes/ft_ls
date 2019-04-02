/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:22:45 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/01 22:28:30 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
# include "libft.h"
# include <dirent.h> //opendir, readdir, closedir
# include <stdlib.h>
# include <uuid/uuid.h> //getpwuid, getgrgid
# include <sys/xattr.h> //listxattr, getxattr
# include <time.h> //time, ctime
# include <sys/stat.h> //stat, lstat
# include <unistd.h> //readlink
# include <stdio.h> //perror, strerror

/*
** flags: L/U = lower/upper, followed by letter
** instead of overriding by order given, maybe override by cascade for ease?
*/
# define LS_UA 0x00001	//list all except . & ..
# define LS_UF 0x00002	//dir/ , exec*, socket=, whiteout% (ignore?), fifo|
# define LS_UG 0x00004	//colours!
# define LS_UR 0x00008	//REQ recur on subdirs
# define LS_US 0x00010	//sort by size
# define LS_UT 0x00020	//req -l, display complete time info ie Mar 26 20:01:18 2019
# define LS_LA 0x00040	//REQ list all w/ .
# define LS_LF 0x00080	//output not sorted, and -a
# define LS_LG 0x00100	//no username in -l
# define LS_LI 0x00200	//print inode # (doesn't need -l!)
# define LS_LL 0x00400	//REQ long format
# define LS_LN 0x00800	//disp uid and gid as #; turn on -l
# define LS_LP 0x01000	// '/' after directories, similar to F but less intense
# define LS_LR 0x02000	//REQ reverse sort order (rev alpha, oldest first, largest last)
# define LS_LS 0x04000	//output blocksize (lists total like -l, doesn't need -l)
# define LS_LT 0x08000	//REQ sort by mod time (most recent first) and then name
# define LS_LU 0x10000	//time of last access instead of last mod for -t sort and -l

/*
** tot: size in b / 512 (rounded up) (given by st_mode no worries)
*/
//these will be enqueued
typedef struct	s_lsdir
{
	int			tot;
	char		*path;
	DIR			*dir;
	t_list		*entries;
}				t_lsdir;

//there'll be a ll of these suckers right here, sorted according to flags
//like, after being created obvi (and summing themselves for ^tot)
//need delete func? like to free all the shit inside
//saving d_name to avoid having to save dirent struct
//(other info in dirent duped in stats)
typedef struct	s_lsent
{
	char		*name;
	char		*full_name;
	struct stat	*stats; //v. important, basically inherits from
	char		ftype;	//in handy printable fmt
	char		exec;	//is it executable?
	char		*perms;
	char		*owner; //getpwuid(uid) (might not need var)
	char		*group; //getgrgid(gid) (might not need var)
	int			sixmo_flag;

}				t_lsent;

typedef int		(*ls_comp)(t_list*, t_list*);

void			ls_set_color(mode_t mode);
void			ls_print_long(struct dirent *entry, char *path, int f);

void			ls_get_ftype(t_lsent *entry);
void			ls_get_perms(t_lsent *perms);

t_lsdir			*ls_mkdir(char *name, long flags);
void			ls_print(t_lsdir *dir, long flags);
void			ls_rmdir(t_lsdir *dir);

int				ls_alphacomp(t_list *n1, t_list *n2);
int				ls_revalpha(t_list *n1, t_list *n2);
int				ls_modtimecomp(t_list *n1, t_list *n2);
int				ls_revmodtime(t_list *n1, t_list *n2);
int				ls_acctimecomp(t_list *n1, t_list *n2);
int				ls_revacctime(t_list *n1, t_list *n2);
int				ls_sizecomp(t_list *n1, t_list *n2);
int				ls_revsize(t_list *n1, t_list *n2);

#endif
