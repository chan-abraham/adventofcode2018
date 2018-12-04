/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:02:54 by abchan            #+#    #+#             */
/*   Updated: 2018/03/13 14:00:35 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkdigits(int n)
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

char		*ft_itoa(int n)
{
	int			i;
	char		*nbrstr;
	long long	t;

	t = (long long)n;
	i = checkdigits(t);
	if (t < 0)
	{
		i++;
		t = -t;
	}
	nbrstr = ft_strnew(i);
	if (!nbrstr)
		return (NULL);
	if (i > 1)
		nbrstr[0] = '-';
	if (t == 0)
		nbrstr[0] = '0';
	while (t > 0)
	{
		*(nbrstr + --i) = t % 10 + '0';
		t = t / 10;
	}
	return (nbrstr);
}
