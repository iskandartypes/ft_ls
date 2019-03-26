/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapend32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 02:21:02 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/11 02:54:27 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** swaps endianness for 32-bit vals
*/

uint32_t	ft_swapend32(uint32_t n)
{
	uint32_t b0;
	uint32_t b1;
	uint32_t b2;
	uint32_t b3;

	b0 = (n & 0x000000ff) << 24u;
	b1 = (n & 0x0000ff00) << 8u;
	b2 = (n & 0x00ff0000) >> 8u;
	b3 = (n & 0xff000000) >> 24u;
	return (b0 | b1 | b2 | b3);
}
