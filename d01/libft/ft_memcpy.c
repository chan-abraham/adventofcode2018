/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 21:57:15 by abchan            #+#    #+#             */
/*   Updated: 2018/03/13 13:33:25 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptrdst;
	char	*ptrsrc;
	size_t	i;

	i = 0;
	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	while (i < n)
	{
		*(ptrdst + i) = *(ptrsrc + i);
		i++;
	}
	return (dst);
}
