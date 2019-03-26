/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 04:13:51 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/04 21:18:36 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note: this method of checking the pointer location both technically works
** and is in accordance with how the C standard is programmed, but *isn't safe*
** if the chunks of memory being compared aren't in the same block.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_c;
	const unsigned char	*src_c;

	dst_c = dst;
	src_c = src;
	if (dst_c < src_c)
		dst_c = ft_memcpy(dst_c, src_c, len);
	else if (len)
	{
		while (--len)
			dst_c[len] = src_c[len];
		dst_c[0] = src_c[0];
	}
	return (dst);
}
