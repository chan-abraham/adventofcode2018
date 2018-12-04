/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:09:31 by abchan            #+#    #+#             */
/*   Updated: 2018/03/16 11:13:12 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t h;
	size_t n;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	if (!len)
		return (NULL);
	h = 0;
	while (haystack[h] != '\0' && h < len)
	{
		n = 0;
		while (haystack[h + n] == needle[n] && h + n < len)
		{
			if (!(needle[n + 1]))
				return ((char *)(haystack + h));
			n++;
		}
		h++;
	}
	return (NULL);
}
