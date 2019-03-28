/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:22:45 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/27 22:26:33 by ikourkji         ###   ########.fr       */
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
** not in any particular order, but that's not relevant
*/
# define LS_LL 0x0001
# define LS_UR 0x0002
# define LS_LA 0x0004
# define LS_LR 0x0008
# define LS_LT 0x0010
# define LS_UG 0x0020
# define LS_LP 0x0040
# define LS_LF 0x0080
# define LS_LH 0x0100
# define LS_LI 0x0200
# define LS_US 0x0400
# define LS_UT 0x0800
# define LS_LU 0x1000
# define LS_UU 0x2000
# define LS_LG 0x4000

#endif
