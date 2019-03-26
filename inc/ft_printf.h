/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 01:52:18 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/25 05:24:32 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define F_CONV		0x1
# define F_ZPAD		0x2
# define F_RPAD		0x4
# define F_BLANK	0x8
# define F_SIGN		0x10
# define F_PTR		0x20
# define F_PREC		0x40
# define F_BASE		0x80
# define F_H		0x100
# define F_L		0x200
# define F_MAX		0x400
# define F_SIZE		0x800
# define F_LL		0x1000
# define F_HH		0x2000
# define F_ALL		0x3f00
# define F_UP		0x4000

# define NCONV		12
# define ICONV		2
# define UICONV		4

typedef struct s_vars	t_vars;
typedef void	(*t_func)(t_vars*);
struct	s_vars
{
	va_list	args;
	char	*fmt;
	char	*buf;
	t_func	*ftab;
	size_t	buf_len;
	size_t	buf_i;
	int		flags;
	int		clen;
	int		min;
	int		base;
	int		pad;
	int		prec;
};

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vprintf(const char *format, va_list ap);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_sprintf(char *str, const char *format, ...);

int		ft_vsprintf(char *str, const char *format, va_list ap);
int		ft_snprintf(char *str, size_t size, const char *format, ...);
int		ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);
int		ft_asprintf(char **ret, const char *format, ...);
int		ft_vasprintf(char **ret, const char *format, va_list ap);

void	core(t_vars *v);
void	pf_make_ftab(t_vars *v);

void	pf_int(t_vars *v);
void	pf_uint(t_vars *v);
void	pf_uint_add(t_vars *v, uintmax_t n, int prec0);

void	pf_char(t_vars *v);
void	pf_str(t_vars *v);

void	pf_float(t_vars *v);
void	pf_pct(t_vars *v);
void	pf_ptr(t_vars *v);
void	pf_color(t_vars *v);

int		pf_uclen(wchar_t c);
int		pf_wclen(wchar_t c);
int		pf_ustrlen(wchar_t *s);
int		pf_wstrlen(wchar_t *s);

void	pf_placechar(t_vars *v, char c);
void	pf_placestr(t_vars *v, char *s);
t_vars	*pf_partial_copy(t_vars *v);
void	pf_destroy_copy(t_vars *c, t_vars *v);
char	*pf_uitoa_base(uintmax_t n, int base, int up);
#endif
