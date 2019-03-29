/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_rcomps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:26:58 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/29 14:44:52 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** I could doubly link the lists and read backwards from them,
** but the overhead for the extra pointers seems roughly equivalent
** to the overhead from doing this.
*/

int		ls_revalpha(t_list *n1, t_list *n2)
{
	return (ls_alphacomp(n1, n2) * -1);
}

int		ls_revmodtime(t_list *n1, t_list *n2)
{
	return (ls_modtimecomp(n1, n2) * -1);
}

int		ls_revacctime(t_list *n1, t_list *n2)
{
	return (ls_acctimecomp(n1, n2) * -1);
}

int		ls_revsize(t_list *n1, t_list *n2)
{
	return (ls_sizecomp(n1, n2) * -1);
}
