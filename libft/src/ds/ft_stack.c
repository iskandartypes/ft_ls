/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 05:48:24 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/28 05:55:27 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stis_empty(t_stack *stack)
{
	return (stack->top == NULL ? 1 : 0);
}

t_stack	*ft_stinit(void)
{
	t_stack *ret;

	ret = malloc(sizeof(*ret));
	ret->top = NULL;
	return (ret);
}

void	*ft_pop(t_stack *stack)
{
	t_stnode	*tmp;
	void		*ret;

	if (ft_stis_empty(stack))
		return (NULL);
	tmp = stack->top;
	stack->top = tmp->next;
	ret = tmp->content;
	free(tmp);
	return (ret);
}

void	ft_push(t_stack *stack, void *content)
{
	t_stnode	*add;

	add = malloc(sizeof(*add));
	add->content = content;
	add->next = stack->top;
	stack->top = add;
}

void	*ft_stpeek(t_stack *stack)
{
	if (ft_stis_empty(stack))
		return (NULL);
	return (stack->top->content);
}
