/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:44:53 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/07 10:36:28 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_neg(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char		*ft_itoa(int n)
{
	int		len;
	int		n_c;
	int		negflag;
	char	*ret;

	len = 1;
	negflag = is_neg(n);
	len += (negflag == -1) ? 1 : 0;
	n_c = n;
	while (n_c >= 10 || n_c <= -10)
	{
		n_c /= 10;
		len++;
	}
	if (!(ret = ft_strnew(len--)))
		return (NULL);
	while (len >= 0)
	{
		ret[len--] = '0' + ((n % 10) * negflag);
		n /= 10;
		if (len == 0 && negflag == -1)
			ret[len--] = '-';
	}
	return (ret);
}
