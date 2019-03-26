/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:02:43 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/05 13:19:12 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ret;

	if (!s)
		return (NULL);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	ret = ft_strncpy(ret, s + start, len);
	return (ret);
}
