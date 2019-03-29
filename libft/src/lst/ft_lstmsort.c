/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:49:56 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/29 11:51:33 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** mergesort; takes in unsorted lst + comparison function (comparator)
** comparator returns neg for a < b, 0 for a == b, and pos for a > b
** (< == > are sort order, not act. value, ie a < b :: a before b)
*/

/*
** merges sorted lists.
** mergesort works under the idea that a list of one is a sorted list,
** and then we just have to merge them while keeping the order.
** so this is the workhorse.
*/

static t_list	*merge(t_list *lst1, t_list *lst2, int (*f)(t_list*, t_list*))
{
	t_list	*sorted;

	if (!lst1)
		return (lst2);
	else if (!lst2)
		return (lst1);
	if (f(lst1, lst2) < 1)
	{
		sorted = lst1;
		sorted->next = merge(lst1->next, lst2, f);
	}
	else
	{
		sorted = lst2;
		sorted->next = merge(lst1, lst2->next, f);
	}
	return (sorted);
}

/*
** we're dividing the list into two here;
** bc we don't know the length of the list, we advance two for one
** (fast vs slow); when fast hits end, slow is in the middle
** we "return" pointers to front and back halves through pointers
*/

static void		split_list(t_list *lst, t_list **frontp, t_list **backp)
{
	t_list	*fast;
	t_list	*slow;

	slow = lst;
	fast = slow->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontp = lst;
	*backp = slow->next;
	slow->next = NULL;
}

/*
** the driver; split splits, merge merges and takes the comparator to sort
** all this does is recur down, splitting until we hit nothing or one
*/

void			ft_lstmsort(t_list **lst, int (*f)(t_list*, t_list*))
{
	t_list	*head;
	t_list	*front;
	t_list	*back;

	head = *lst;
	if (head == NULL || head->next == NULL)
		return ;
	split_list(head, &front, &back);
	ft_lstmsort(&front, f);
	ft_lstmsort(&back, f);
	*lst = merge(front, back, f);
}
