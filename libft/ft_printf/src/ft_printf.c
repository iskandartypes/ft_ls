/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 02:02:01 by ikourkji          #+#    #+#             */
/*   Updated: 2019/02/03 02:08:18 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vdprintf(1, format, args);
	va_end(args);
	return (len);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vdprintf(fd, format, args);
	va_end(args);
	return (len);
}

int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		len;
	char	*ret;

	len = ft_vasprintf(&ret, format, ap);
	if (!ret)
		return (-1);
	write(fd, ret, len);
	ft_memdel((void **)&ret);
	return (len);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vsprintf(str, format, args);
	va_end(args);
	return (len);
}
