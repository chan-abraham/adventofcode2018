/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:38:31 by abchan            #+#    #+#             */
/*   Updated: 2018/03/13 13:33:52 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t dstlen;
	size_t srclen;

	i = 0;
	j = (size_t)ft_strlen(dst);
	dstlen = (size_t)ft_strlen(dst);
	srclen = (size_t)ft_strlen(src);
	if (dstlen + 1 > dstsize)
		return (srclen + dstsize);
	if ((dstlen + 1) < dstsize)
	{
		while (j < dstsize - 1)
		{
			*(dst + j) = *(src + i);
			j++;
			i++;
		}
		*(dst + j) = '\0';
	}
	return (dstlen + srclen);
}
