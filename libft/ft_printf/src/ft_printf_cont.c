/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cont.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:45:26 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/12 03:39:37 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define INIT_BUF 64

/*
** man 3 printf:
** The sprintf() and vsprintf() functions
** effectively assume a size of INT_MAX + 1.
** They both also won't be NULL-terminated if the last arg isn't.
** This is slightly edited here; both are always NULL-terminated
** (unlike the OG), although they can still both overwrite the end of the buf.
*/

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	int		len;
	char	*ret;

	len = ft_vasprintf(&ret, format, ap);
	if (!ret)
		return (-1);
	str = ft_memcpy(str, ret, len);
	ft_memdel((void **)&ret);
	return (len);
}

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vsnprintf(str, size, format, args);
	va_end(args);
	return (len);
}

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	char	*ret;
	int		len;

	len = ft_vasprintf(&ret, format, ap);
	if (!ret)
		return (-1);
	str = ft_memcpy(str, ret, size);
	ft_memdel((void **)&ret);
	if (size)
		str[size] = '\0';
	return (len);
}

int	ft_asprintf(char **ret, const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vasprintf(ret, format, args);
	va_end(args);
	return (len);
}

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_vars	*v;
	int		len;

	if (!(v = ft_memalloc(sizeof(*v))))
		return (-1);
	len = 0;
	v->fmt = (char *)format;
	va_copy(v->args, ap);
	pf_make_ftab(v);
	if (!(v->ftab))
		return (-1);
	if ((v->buf = ft_strnew(INIT_BUF - 1)))
	{
		v->buf_i = 0;
		v->buf_len = INIT_BUF;
		core(v);
		len = v->buf_i;
	}
	*ret = v->buf;
	ft_memdel((void **)&v->ftab);
	va_end(v->args);
	ft_memdel((void **)&v);
	return (len);
}
