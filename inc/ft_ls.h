/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:22:45 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/28 19:54:19 by ikourkji         ###   ########.fr       */
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
# define LS_UU 0x00040	//use time of creation for -t sort and -l
# define LS_LA 0x00080	//REQ list all w/ .
# define LS_LF 0x00100	//output not sorted, and -a
# define LS_LG 0x00200	//no username in -l
# define LS_LI 0x00400	//print inode # (doesn't need -l!)
# define LS_LL 0x00800	//REQ long format
# define LS_LN 0x01000	//disp uid and gid as #; turn on -l
# define LS_LP 0x02000	// '/' after directories, similar to F but less intense
# define LS_LR 0x04000	//REQ reverse sort order (rev alpha, oldest first, largest last)
# define LS_LS 0x08000	//output blocksize (lists total like -l, doesn't need -l)
# define LS_LT 0x10000	//REQ sort by mod time (most recent first) and then name
# define LS_LU 0x20000	//time of last access instead of last mod for -t sort and -l

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
typedef struct	s_lsl
{
	struct stat	stats; //v. important, basically inherits from
	char		ftype; 
	char		*perms;
	char		*owner; //getpwuid(uid) (might not need var)
	char		*group; //getgrgid(gid) (might not need var)
	int			sixmo_flag;

}				t_lsl;

void			ls_set_color(mode_t mode);
void			ls_print_long(struct dirent *entry, char *path, int f);

#endif
