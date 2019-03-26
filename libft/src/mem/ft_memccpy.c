/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 04:11:02 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/05 11:49:04 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_c;
	const unsigned char	*src_c;

	if (n == 0)
		return (NULL);
	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	c = (unsigned char)c;
	while (n && *src_c != c)
	{
		*dst_c++ = *src_c++;
		n--;
	}
	if (n)
	{
		*dst_c++ = *src_c++;
		return ((void *)dst_c);
	}
	return (NULL);
}
