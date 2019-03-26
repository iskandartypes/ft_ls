/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 07:22:45 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/26 07:30:02 by ikourkji         ###   ########.fr       */
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

#endif
