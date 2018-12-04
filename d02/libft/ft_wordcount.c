/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:37:03 by abchan            #+#    #+#             */
/*   Updated: 2018/03/16 10:55:36 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the purpose of this function is to return the number of words in a string
*/

int		ft_wordcount(char const *s, char c)
{
	int count;
	int i;
	int seperator;

	count = 0;
	i = 0;
	seperator = 1;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			seperator = 1;
			i++;
		}
		while (s[i] != c && seperator == 0 && s[i] != '\0')
			i++;
		if (s[i] != c && seperator == 1 && s[i] != '\0')
		{
			count++;
			i++;
			seperator = 0;
		}
	}
	return (count);
}
