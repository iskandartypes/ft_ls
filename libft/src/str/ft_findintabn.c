/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findintabn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 03:16:23 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/11 03:19:09 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns index of string in in first n of array of strings
** -1 if none
*/

int		ft_findintabn(char **haystack, char *needle, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(haystack[i], needle) == 0)
			return (i);
		i++;
	}
	return (-1);
}
