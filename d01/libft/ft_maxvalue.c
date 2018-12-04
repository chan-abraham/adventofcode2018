/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:38:13 by abchan            #+#    #+#             */
/*   Updated: 2018/03/16 15:32:34 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this function finds the max value in an array of ints
*/

int		ft_maxvalue(int *tab, unsigned int len)
{
	unsigned int	i;
	int				res;

	i = 1;
	res = tab[0];
	while (i < len)
	{
		if (res < tab[i])
			res = tab[i];
		i++;
	}
	if (i == len)
		return (res);
	return (0);
}
