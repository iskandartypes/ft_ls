/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 00:51:03 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/07 20:07:34 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dlen;
	size_t slen;
	size_t alen;

	dlen = 0;
	while (dst[dlen] && dlen < dstsize)
		dlen++;
	slen = ft_strlen(src);
	alen = dstsize - dlen - (dstsize == dlen ? 0 : 1);
	if (slen < alen)
		ft_strncat(dst, src, slen);
	else
		ft_strncat(dst, src, alen);
	return (slen + dlen);
}
