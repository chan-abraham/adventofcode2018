/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:40:44 by abchan            #+#    #+#             */
/*   Updated: 2018/03/13 13:57:18 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	if (!s)
		return (NULL);
	s2 = ft_strnew(ft_strlen(s));
	if (!s2)
		return (NULL);
	i = -1;
	while (*(s + ++i))
		*(s2 + i) = f(i, *(s + i));
	return (s2);
}
