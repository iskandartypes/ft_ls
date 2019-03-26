/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:55:46 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/04 20:53:04 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dup;

	dup = (char *)malloc(sizeof(*dup) * (ft_strlen(s) + 1));
	if (dup)
		dup = ft_strcpy(dup, s);
	return (dup);
}
