/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:28:40 by abchan            #+#    #+#             */
/*   Updated: 2018/03/13 13:44:41 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*s2;

	i = -1;
	if (!s)
		return (NULL);
	s2 = ft_strnew(ft_strlen(s));
	if (!s2)
		return (NULL);
	while (*(s + ++i))
		*(s2 + i) = f(*(s + i));
	return (s2);
}
