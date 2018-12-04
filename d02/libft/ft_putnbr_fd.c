/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 10:44:14 by abchan            #+#    #+#             */
/*   Updated: 2018/03/12 23:21:35 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long t;

	t = n;
	if (t < 0)
	{
		t = -t;
		ft_putchar_fd('-', fd);
	}
	if (t >= 10)
	{
		ft_putnbr_fd(t / 10, fd);
		ft_putchar_fd(t % 10 + '0', fd);
	}
	else
		ft_putchar_fd(t + '0', fd);
}
