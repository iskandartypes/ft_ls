/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:28:26 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/05 18:10:03 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define WHITE(c) (c == ' ' || c == '\n' || c == '\t')

char	*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	len;
	size_t	start;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	start = 0;
	while (start < len && WHITE(s[start]))
		start++;
	while (start < len && WHITE(s[len - 1]))
		len--;
	if (!(ret = ft_strnew(len - start)))
		return (NULL);
	ret = ft_strncpy(ret, s + start, len - start);
	return (ret);
}
