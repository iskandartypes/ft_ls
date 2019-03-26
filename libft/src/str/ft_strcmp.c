/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:37:39 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/07 22:07:47 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*s1c;
	const unsigned char	*s2c;

	s1c = (const unsigned char *)s1;
	s2c = (const unsigned char *)s2;
	while (*s1c && *s2c)
	{
		if (*s1c != *s2c)
			return ((int)*s1c - *s2c);
		s1c++;
		s2c++;
	}
	if (*s1c)
		return ((int)*s1c);
	if (*s2c)
		return ((int)*s2c * -1);
	return (0);
}
