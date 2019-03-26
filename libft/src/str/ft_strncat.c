/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 07:20:10 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/01 21:31:13 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len1;
	size_t len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len2 < n)
		n = len2;
	ft_strncpy(s1 + len1, s2, n);
	s1[len1 + n] = '\0';
	return (s1);
}
