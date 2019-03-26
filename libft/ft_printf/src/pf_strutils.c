/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:16:03 by ikourkji          #+#    #+#             */
/*   Updated: 2019/02/17 01:40:38 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** returns number of bytes in UTF-8, which these machines use
** masks for bits 17-21, 12-16, & 8-11 (inclusive)
*/

int		pf_uclen(wchar_t c)
{
	if (c & 0x1F0000)
		return (4);
	if (c & 0xF800)
		return (3);
	if (c & 0x780)
		return (2);
	return (1);
}

int		pf_wclen(wchar_t c)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (!(c >> (8 * i)))
			return (i);
		i++;
	}
	return (0);
}

int		pf_ustrlen(wchar_t *s)
{
	int len;

	len = 0;
	while (*s)
		len += pf_uclen(*(s++));
	return (len);
}

int		pf_wstrlen(wchar_t *s)
{
	int	len;

	len = 0;
	while (*s)
		len += pf_wclen(*(s++));
	return (len);
}
