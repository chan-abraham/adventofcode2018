/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:53:20 by abchan            #+#    #+#             */
/*   Updated: 2018/03/16 11:13:10 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t h;
	size_t n;

	h = 0;
	n = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*(haystack + h) != '\0')
	{
		if (*(haystack + h) != *(needle + n))
		{
			h = h - n + 1;
			n = 0;
		}
		if (*(haystack + h) == *(needle + n))
		{
			h++;
			n++;
			if (n == ft_strlen(needle))
				return ((char *)haystack + h - n);
		}
	}
	return (NULL);
}
