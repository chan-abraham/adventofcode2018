/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 00:05:08 by abchan            #+#    #+#             */
/*   Updated: 2018/03/15 12:34:11 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;
	t_list *head;

	tmp = f(lst);
	head = tmp;
	new = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp = f(lst);
		new->next = tmp;
		new = tmp;
	}
	return (head);
}
