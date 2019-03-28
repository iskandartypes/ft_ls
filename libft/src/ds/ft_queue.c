/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 05:25:11 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/28 05:41:43 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_qis_empty(t_queue *queue)
{
	return (queue->first == NULL ? 1 : 0);
}

t_queue	*ft_qinit(void)
{
	t_queue *q;

	q = malloc(sizeof(*q));
	q->first = NULL;
	q->last = NULL;
	return (q);
}

void	ft_enqueue(t_queue *queue, void *content)
{
	t_qnode *node;

	node = malloc(sizeof(*node));
	node->content = content;
	node->next = NULL;
	if (ft_qis_empty(queue))
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = node;
	}
}

void	*ft_dequeue(t_queue *queue)
{
	t_qnode	*tmp;
	void	*ret;

	if (ft_qis_empty(queue))
		return (NULL);
	tmp = queue->first;
	ret = tmp->content;
	queue->first = tmp->next;
	if (queue->last == tmp)
		queue->last = NULL;
	free(tmp);
	return (ret);
}

void	*ft_peek(t_queue *queue)
{
	if (ft_qis_empty(queue))
		return (NULL);
	return (queue->first->content);
}
