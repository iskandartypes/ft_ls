/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findintab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 02:51:34 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/11 03:10:34 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns index of string in NULL-terminated array of strings
** -1 if none
*/

int		ft_findintab(char **haystack, char *needle)
{
	int i;

	i = 0;
	while (haystack[i])
	{
		if (ft_strcmp(haystack[i], needle) == 0)
			return (i);
		i++;
	}
	return (-1);
}
