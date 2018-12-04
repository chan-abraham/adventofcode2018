/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:29:04 by abchan            #+#    #+#             */
/*   Updated: 2018/03/16 15:14:50 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this function prints a number (provided as an unsigned char) and prints it
** out as binary
*/

void	print_bits(unsigned char octet)
{
	char	bit;
	int		i;

	i = 7;
	while (i-- >= 0)
	{
		bit = ((octet >> i & 1) + '0');
		write(1, &bit, 1);
	}
}
