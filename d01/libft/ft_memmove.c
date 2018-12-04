/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 00:15:15 by abchan            #+#    #+#             */
/*   Updated: 2018/03/05 15:19:22 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *scr, size_t len)
{
	size_t i;

	i = 0;
	if (scr < dst)
		while ((int)--len >= 0)
			*(char *)(dst + len) = *(char *)(scr + len);
	else
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(scr + i);
			i++;
		}
	return (dst);
}
