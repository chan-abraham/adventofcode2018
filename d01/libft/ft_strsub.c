/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:58:04 by abchan            #+#    #+#             */
/*   Updated: 2018/03/13 13:52:33 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	if (!s)
		return (NULL);
	newstr = ft_strnew(len);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(newstr + i) = *(s + start);
		i++;
		start++;
	}
	return (newstr);
}
