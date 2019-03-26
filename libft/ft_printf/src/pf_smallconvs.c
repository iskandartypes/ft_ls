/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_smallconvs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:17:13 by ikourkji          #+#    #+#             */
/*   Updated: 2019/02/11 09:59:59 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Just the % op and some flags
*/

void		pf_pct(t_vars *v)
{
	v->min--;
	if (!(v->flags & F_RPAD))
		while (v->min-- > 0)
			pf_placechar(v, v->flags & F_ZPAD ? '0' : ' ');
	pf_placechar(v, '%');
	while (v->min-- > 0)
		pf_placechar(v, ' ');
}

void		pf_ptr(t_vars *v)
{
	void				*ptr;

	ptr = va_arg(v->args, void*);
	v->flags |= F_L | F_CONV | F_PTR;
	v->base = 16;
	pf_uint_add(v, (uintmax_t)ptr, 0);
}

/*
** does length of colour like sprintf, not printf (counts chars in ansi code)
** F_CONV does bold
** } do text, ] do background
** (due to implementation opening bracket irrelevant)
** empty/unkown brackets default to colour reset (bold if F_CONV)
** WARNING if no closing bracket, eats rest of string
** the function is spelled without a 'u' bc American English is the standard
*/

void		pf_color(t_vars *v)
{
	pf_placestr(v, "\033[\0");
	(!ft_strncmp(v->fmt, "black}", 6)) ? pf_placestr(v, "30\0") : 0;
	(!ft_strncmp(v->fmt, "red}", 4)) ? pf_placestr(v, "31\0") : 0;
	(!ft_strncmp(v->fmt, "green}", 6)) ? pf_placestr(v, "32\0") : 0;
	(!ft_strncmp(v->fmt, "yellow}", 7)) ? pf_placestr(v, "33\0") : 0;
	(!ft_strncmp(v->fmt, "blue}", 5)) ? pf_placestr(v, "34\0") : 0;
	(!ft_strncmp(v->fmt, "magenta}", 8)) ? pf_placestr(v, "35\0") : 0;
	(!ft_strncmp(v->fmt, "cyan}", 5)) ? pf_placestr(v, "36\0") : 0;
	(!ft_strncmp(v->fmt, "white}", 6)) ? pf_placestr(v, "37\0") : 0;
	(!ft_strncmp(v->fmt, "black]", 6)) ? pf_placestr(v, "40\0") : 0;
	(!ft_strncmp(v->fmt, "red]", 4)) ? pf_placestr(v, "41\0") : 0;
	(!ft_strncmp(v->fmt, "green]", 6)) ? pf_placestr(v, "42\0") : 0;
	(!ft_strncmp(v->fmt, "yellow]", 7)) ? pf_placestr(v, "43\0") : 0;
	(!ft_strncmp(v->fmt, "blue]", 5)) ? pf_placestr(v, "44\0") : 0;
	(!ft_strncmp(v->fmt, "magenta]", 8)) ? pf_placestr(v, "45\0") : 0;
	(!ft_strncmp(v->fmt, "cyan]", 5)) ? pf_placestr(v, "46\0") : 0;
	(!ft_strncmp(v->fmt, "white]", 6)) ? pf_placestr(v, "47\0") : 0;
	(v->flags & F_CONV) ? pf_placestr(v, ";1\0") : 0;
	pf_placechar(v, 'm');
	while (*v->fmt && *v->fmt != '}' && *v->fmt != ']')
		v->fmt++;
	(*v->fmt) ? v->fmt++ : 0;
}
