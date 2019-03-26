/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:03:39 by ikourkji          #+#    #+#             */
/*   Updated: 2019/01/08 20:05:11 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubdel(char *s, unsigned int start, size_t len)
{
	char *ret;

	if (!s)
		return (NULL);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	ret = ft_strncpy(ret, s + start, len);
	ft_strdel((char **)&s);
	return (ret);
}
