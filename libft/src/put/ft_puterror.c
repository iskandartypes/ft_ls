/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 01:19:33 by ikourkji          #+#    #+#             */
/*   Updated: 2019/02/25 01:23:17 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** writes to stderror
** returns 1 as error code for main
*/

int		ft_puterror(char const *s)
{
	ft_putstr_fd(s, 2);
	return (1);
}
