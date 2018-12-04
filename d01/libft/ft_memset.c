/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:27:24 by abchan            #+#    #+#             */
/*   Updated: 2018/03/01 11:30:45 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;
	char	*ptr;

	index = 0;
	ptr = b;
	while (index < len)
	{
		*(ptr + index) = (unsigned char)c;
		index++;
	}
	return (b);
}
