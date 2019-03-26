/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:04:07 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/07 19:18:34 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *run;

	if (!alst || !*alst)
		return ;
	while ((run = (*alst)))
	{
		*alst = (*alst)->next;
		ft_lstdelone(&run, del);
	}
}
