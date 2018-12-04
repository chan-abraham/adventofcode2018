/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:18:17 by abchan            #+#    #+#             */
/*   Updated: 2018/03/16 15:16:56 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the purpose of this function is to reverse the order of items in a char str
*/

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	if (!str)
		return (str);
	i = 0;
	j = ft_strlen(str);
	while (i < j - 1)
	{
		tmp = str[j - 1];
		str[j - 1] = str[i];
		str[i] = tmp;
		i++;
		j--;
	}
	return (str);
}
