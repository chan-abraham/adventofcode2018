/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:22:15 by abchan            #+#    #+#             */
/*   Updated: 2018/03/26 13:07:35 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this function founts the number of elements in the linked list
*/

int		ft_lstsize(t_list *begin_list)
{
	int		i;
	t_list	*list;

	i = 0;
	list = begin_list;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
