/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 06:59:26 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/01 07:09:57 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t s_len;

	s_len = ft_strlen(src);
	dst = ft_memcpy(dst, src, len);
	if (s_len < len)
		ft_bzero(dst + s_len, len - s_len);
	return (dst);
}
