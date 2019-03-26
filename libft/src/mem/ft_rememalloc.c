/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rememalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:12:56 by ikourkji          #+#    #+#             */
/*   Updated: 2019/01/29 00:33:44 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_rememalloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*ret;

	if (!(ret = ft_memalloc(sizeof(*ret) * new_size)))
		ft_memdel(ptr);
	if (ptr)
	{
		ret = ft_memcpy(ret, ptr, MIN(old_size, new_size));
		ft_memdel(&ptr);
	}
	return (ret);
}
