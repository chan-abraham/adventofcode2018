/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powerof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:12:49 by abchan            #+#    #+#             */
/*   Updated: 2018/03/16 15:13:58 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the purpose of this function is to return the result of the exponent thing
** this does not work with negative powers
*/

long int	ft_powerof(int base, int p)
{
	long int (res);

	if (p == 0)
		return (1);
	if (p == 1)
		return ((long)base);
	res = (long)base;
	while (p-- >= 2)
		res = res * base;
	return (res);
}
