/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 04:15:19 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/05 11:49:13 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *mem;

	mem = (const unsigned char *)s;
	c = (unsigned char)c;
	while (n > 0)
	{
		if (*mem == c)
			return ((void *)mem);
		mem++;
		n--;
	}
	return (NULL);
}
