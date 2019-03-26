/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:33:33 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/06 22:34:09 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_c(char const *s, char c)
{
	char	*ret;
	size_t	len;
	size_t	start;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	start = 0;
	while (start < len && s[start] == c)
		start++;
	while (start < len && s[len - 1] == c)
		len--;
	if (!(ret = ft_strnew(len - start)))
		return (NULL);
	ret = ft_strncpy(ret, s + start, len - start);
	return (ret);
}
