/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:41:04 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/07 22:20:21 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int negflag;

	negflag = 1;
	if (n < 0)
	{
		ft_putchar('-');
		negflag = -1;
	}
	if (n >= -9 && n <= 9)
		ft_putchar('0' + n * negflag);
	else
	{
		ft_putnbr((n / 10) * negflag);
		ft_putnbr((n % 10) * negflag);
	}
}
