/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:49:31 by abchan            #+#    #+#             */
/*   Updated: 2018/03/16 15:15:11 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the purpose of this function is to return the return the number of digits
** contained in an int
*/

int		ft_countdigits(int n)
{
	int			i;
	long long	t;

	t = n;
	i = 1;
	if (t < 0)
		t = -t;
	while (t / 10 >= 1)
	{
		t = t / 10;
		i++;
	}
	return (i);
}
