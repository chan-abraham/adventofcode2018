/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:39:38 by abchan            #+#    #+#             */
/*   Updated: 2018/03/12 23:29:14 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int index;

	index = 0;
	if (s != NULL)
		while (s[index] != '\0')
		{
			ft_putchar_fd(s[index], fd);
			index++;
		}
}
