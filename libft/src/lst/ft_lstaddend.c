/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:25:00 by ikourkji          #+#    #+#             */
/*   Updated: 2019/04/01 16:22:00 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*run;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	run = *alst;
	while (run->next)
		run = run->next;
	run->next = new;
}
