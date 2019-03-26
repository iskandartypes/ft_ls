/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:39:28 by ikourkji          #+#    #+#             */
/*   Updated: 2018/12/07 19:53:52 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*run;
	t_list	*ret;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (!(ret = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	run = ret;
	while ((lst = lst->next))
	{
		tmp = f(lst);
		if (!(run->next = ft_lstnew(tmp->content, tmp->content_size)))
			break ;
		run = run->next;
	}
	return (ret);
}
