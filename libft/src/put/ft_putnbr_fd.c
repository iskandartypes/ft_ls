/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 02:20:44 by ikourkji          #+#    #+#             */
/*   Updated: 2019/01/08 20:53:04 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int negflag;

	negflag = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		negflag = -1;
	}
	if (n >= -9 && n <= 9)
		ft_putchar_fd('0' + n * negflag, fd);
	else
	{
		ft_putnbr_fd((n / 10) * negflag, fd);
		ft_putnbr_fd((n % 10) * negflag, fd);
	}
}
