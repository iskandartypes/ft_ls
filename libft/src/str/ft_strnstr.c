/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:46:00 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/05 00:30:54 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	i = 0;
	while (*(haystack + i) && (i + n_len) <= len)
	{
		if (ft_strncmp(haystack + i, needle, n_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
