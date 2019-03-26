/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:04:49 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/05 11:50:45 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1c;
	const unsigned char	*s2c;
	int					i;

	s1c = (const unsigned char *)s1;
	s2c = (const unsigned char *)s2;
	i = 0;
	while (s1c[i] && s2c[i] && n)
	{
		if (s1c[i] != s2c[i])
			return ((int)s1c[i] - s2c[i]);
		i++;
		n--;
	}
	if (s1c[i] && n)
		return ((int)s1c[i]);
	if (s2c[i] && n)
		return ((int)-s2c[i]);
	return (0);
}
