/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:12:53 by abchan            #+#    #+#             */
/*   Updated: 2018/03/13 13:56:14 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	newstr = ft_strnew(len);
	if (!newstr)
		return (NULL);
	while (*(s1 + i) != '\0')
		*(newstr + j++) = *(s1 + i++);
	i = 0;
	while (*(s2 + i) != '\0')
		*(newstr + j++) = *(s2 + i++);
	return (newstr);
}
