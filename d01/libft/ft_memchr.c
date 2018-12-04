/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:48:19 by abchan            #+#    #+#             */
/*   Updated: 2018/03/13 13:49:41 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;
	size_t		i;

	ptr = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (*(ptr + i) == (char)c)
			return ((void *)s + i);
		else
			i++;
	}
	return (NULL);
}
