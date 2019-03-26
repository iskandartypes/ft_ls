/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:47:29 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/12 03:37:22 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  #  conv
**  0  zpad
**  -  rpad
** ' ' blank
**  +  sign
*/

static void	parse_flags_mods(t_vars *v)
{
	int	f;

	f = -1;
	while (*v->fmt && (f = ft_charat("#0- +\0", *v->fmt)) > -1 && v->fmt++)
		v->flags |= (1 << f);
	(v->flags & F_RPAD) ? v->flags &= ~F_ZPAD : 0;
	(v->flags & F_SIGN) ? v->flags &= ~F_BLANK : 0;
	if (*v->fmt >= '1' && *v->fmt <= '9')
		v->min = ft_atoi_skip(&v->fmt);
	if (*v->fmt == '.')
	{
		v->fmt++;
		v->prec = ft_atoi_skip(&v->fmt);
		v->flags |= F_PREC;
	}
	(v->flags & F_PREC) ? v->flags &= ~F_ZPAD : 0;
	if (*v->fmt && (f = ft_charat("hljzL\0", *v->fmt)) > -1)
	{
		v->flags |= (1 << (f + 8));
		if (f == 0)
			v->flags |= (*(v->fmt + 1) == 'h' && v->fmt++) ? F_HH : 0;
		else if (f == 1)
			v->flags |= (*(v->fmt + 1) == 'l' && v->fmt++) ? F_LL : 0;
		v->fmt++;
	}
}

/*
** the _ is a bonus base that does any base 2 - 16 inclusive (^ for upcase)
** overwrites conversion base if in range, otherwise goes back to default
*/

static void	parse_base_long(t_vars *v)
{
	int i;

	i = -1;
	if (*v->fmt == '_' && *(++v->fmt))
	{
		if (*v->fmt == '^' && *(++v->fmt))
			v->flags |= F_UP;
		v->base = ft_atoi_skip(&v->fmt);
		if (v->base > 1 && v->base < 17)
			i = 0;
	}
	if (i && (i = ft_charat("bBbboOxX\0", *v->fmt)) > -1)
		v->base = 2 << (i >> 1);
	if (i == -1)
		v->base = 10;
	if (ft_charat("DOUCS\0", *v->fmt) > -1)
		v->flags = (v->flags & ~F_ALL) | F_L;
	if (ft_charat("FBX\0", *v->fmt) > -1)
		v->flags |= F_UP;
}

/*
** second parse_flags_mods is to get all specifiers out of way
** idea is, even with incorrect input order, to at least get the conv
** (user error minimizing)
*/

static void	parse(t_vars *v)
{
	int i;

	i = 0;
	v->flags = 0;
	v->clen = 0;
	v->min = 0;
	v->prec = 0;
	v->base = 10;
	parse_flags_mods(v);
	if (!(*v->fmt))
		return ;
	parse_base_long(v);
	if (!(*v->fmt))
		return ;
	parse_flags_mods(v);
	if (!(*v->fmt))
		return ;
	if ((i = ft_charat("dDiibBoOuUxXfFcCsS%%pp{[\0",\
					*v->fmt)) > -1 && v->fmt++)
		v->ftab[i >> 1](v);
}

void		core(t_vars *v)
{
	while (*(v->fmt))
	{
		if (*(v->fmt) == '%')
		{
			if (!*(v->fmt + 1))
				break ;
			v->fmt++;
			parse(v);
		}
		else
			pf_placechar(v, *(v->fmt++));
		if (!(v->buf))
			return ;
	}
	v->buf = ft_rememalloc(v->buf, v->buf_len, v->buf_i);
}

void		pf_make_ftab(t_vars *v)
{
	int i;

	if (!(v->ftab = malloc(sizeof(*v->ftab) * NCONV)))
		return ;
	i = 0;
	while (i < ICONV)
		v->ftab[i++] = &pf_int;
	while (i < (ICONV + UICONV))
		v->ftab[i++] = &pf_uint;
	v->ftab[i++] = &pf_float;
	v->ftab[i++] = &pf_char;
	v->ftab[i++] = &pf_str;
	v->ftab[i++] = &pf_pct;
	v->ftab[i++] = &pf_ptr;
	v->ftab[i++] = &pf_color;
}
