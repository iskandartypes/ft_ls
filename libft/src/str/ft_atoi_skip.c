/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:29:41 by ikourkji          #+#    #+#             */
/*   Updated: 2019/01/28 21:38:18 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_skip(char **str)
{
	int ret;
	int sign;

	while (ft_iswhite(**str))
		(*str)++;
	ret = 0;
	sign = 1;
	if (**str == '-' || **str == '+')
	{
		sign = ',' - **str;
		(*str)++;
	}
	while (ft_isdigit(**str))
	{
		ret = (ret * 10) + (**str - '0');
		(*str)++;
	}
	return (ret * sign);
}
