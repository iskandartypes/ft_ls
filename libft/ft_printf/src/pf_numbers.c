/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:45:00 by ikourkji          #+#    #+#             */
/*   Updated: 2019/02/17 01:39:23 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			int_add(t_vars *v, intmax_t n, int ng, int prec0)
{
	char	*tmp;
	int		zpad;

	if (!(tmp = pf_uitoa_base((uintmax_t)(n * ng), v->base, v->flags & F_UP)))
		return ;
	v->clen = ft_strlen(tmp);
	zpad = v->prec - v->clen;
	v->pad = v->min - (zpad > 0 ? v->prec : v->clen);
	v->pad += (prec0) ? v->clen : 0;
	v->pad -= ((v->flags & F_BLANK) || (v->flags & F_SIGN) || ng == -1) ? 1 : 0;
	(v->flags & F_ZPAD) ? zpad = v->pad : 0;
	while (!(v->flags & F_RPAD) && !(v->flags & F_ZPAD) && v->pad-- > 0)
		pf_placechar(v, ' ');
	(v->flags & F_BLANK) ? pf_placechar(v, ' ') : 0;
	(v->flags & F_SIGN) ? pf_placechar(v, '+') : 0;
	(ng == -1) ? pf_placechar(v, '-') : 0;
	while (zpad-- > 0)
		pf_placechar(v, '0');
	if (!prec0)
		while (*tmp)
			pf_placechar(v, *(tmp++));
	while (!(v->flags & F_ZPAD) && v->pad-- > 0)
		pf_placechar(v, ' ');
	free(tmp - (prec0 ? 0 : v->clen));
}

void				pf_int(t_vars *v)
{
	intmax_t	n;
	int			ng;
	int			prec0;

	n = 0;
	(v->flags & F_H) && (v->flags & F_HH) ? v->flags &= ~F_H : 0;
	(v->flags & F_L) && (v->flags & F_LL) ? v->flags &= ~F_L : 0;
	!(v->flags & F_ALL) ? n = (intmax_t)va_arg(v->args, int) : 0;
	v->flags & F_HH ? n = (intmax_t)(char)va_arg(v->args, int) : 0;
	v->flags & F_H ? n = (intmax_t)(short)va_arg(v->args, int) : 0;
	v->flags & F_L ? n = (intmax_t)(long)va_arg(v->args, long) : 0;
	v->flags & F_LL ? n = (intmax_t)(long long)va_arg(v->args, long long) : 0;
	v->flags & F_SIZE ? n = (intmax_t)(ssize_t)va_arg(v->args, ssize_t) : 0;
	v->flags & F_MAX ? n = va_arg(v->args, intmax_t) : 0;
	ng = (n < 0) ? -1 : 1;
	ng == -1 ? v->flags &= ~F_BLANK & ~F_SIGN : 0;
	prec0 = (v->flags & F_PREC) && v->prec == 0 && n == 0;
	int_add(v, n, ng, prec0);
}

static inline void	conv_print(t_vars *v)
{
	if (v->flags & F_CONV)
	{
		if (v->base == 8 || v->base == 2 || v->base == 16)
			pf_placechar(v, '0');
		if (v->base == 2)
			pf_placechar(v, (v->flags & F_UP) ? 'B' : 'b');
		else if (v->base == 16)
			pf_placechar(v, (v->flags & F_UP) ? 'X' : 'x');
	}
}

void				pf_uint_add(t_vars *v, uintmax_t n, int prec0)
{
	char	*tmp;
	int		zpad;

	if (!(tmp = pf_uitoa_base(n, v->base, v->flags & F_UP)))
		return ;
	v->clen = ft_strlen(tmp);
	zpad = v->prec - v->clen;
	v->pad = v->min - (zpad > 0 ? v->prec : v->clen);
	v->pad += (prec0) ? v->clen : 0;
	if (v->flags & F_CONV && !prec0)
	{
		v->pad -= v->base == 8 ? 1 : 0;
		v->pad -= v->base == 2 || v->base == 16 ? 2 : 0;
	}
	(v->flags & F_ZPAD) ? zpad = v->pad : 0;
	while (!(v->flags & F_RPAD) && !(v->flags & F_ZPAD) && v->pad-- > 0)
		pf_placechar(v, ' ');
	(n != 0 || v->flags & F_PTR) ? conv_print(v) : 0;
	while (zpad-- > 0)
		pf_placechar(v, '0');
	while (*tmp && !prec0)
		pf_placechar(v, *(tmp++));
	while (!(v->flags & F_ZPAD) && v->pad-- > 0)
		pf_placechar(v, ' ');
	free(tmp - (prec0 ? 0 : v->clen));
}

/*
** bBoOuUxX
** note that char and short are cast to int, because variadic functions
** implicitly cast to int all data types narrower than int
** so the following lines were cut:
** (v->flags & F_H) && (v->flags & F_HH) ? v->flags &= ~F_H: 0;
** v->flags & F_HH ? n = (uintmax_t)va_arg(*v->args, unsigned char) : 0;
*/

void				pf_uint(t_vars *v)
{
	uintmax_t	n;
	int			prec0;

	n = 0;
	(v->flags & F_H) && (v->flags & F_HH) ? v->flags &= ~F_H : 0;
	(v->flags & F_L) && (v->flags & F_LL) ? v->flags &= ~F_L : 0;
	(!(v->flags & F_ALL)) ? n = (uintmax_t)va_arg(v->args, unsigned int) : 0;
	v->flags & F_HH ? n = (uintmax_t)(unsigned char)\
						va_arg(v->args, unsigned) : 0;
	v->flags & F_H ? n = (uintmax_t)(unsigned short)\
						va_arg(v->args, unsigned) : 0;
	v->flags & F_L ? n = (uintmax_t)(unsigned long)\
						va_arg(v->args, unsigned long) : 0;
	v->flags & F_LL ? n = (uintmax_t)(unsigned long long)\
						va_arg(v->args, unsigned long long) : 0;
	v->flags & F_SIZE ? n = (uintmax_t)(size_t)va_arg(v->args, size_t) : 0;
	v->flags & F_MAX ? n = va_arg(v->args, uintmax_t) : 0;
	(v->base == 8 && v->flags & F_CONV && n == 0) ? v->prec++ : 0;
	prec0 = (v->flags & F_PREC) && v->prec == 0 && n == 0;
	pf_uint_add(v, n, prec0);
}
