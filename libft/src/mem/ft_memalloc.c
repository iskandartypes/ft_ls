/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:38:32 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/03 15:47:35 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ret;

	ret = malloc(sizeof(*ret) * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
