/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:21:51 by abchan            #+#    #+#             */
/*   Updated: 2018/03/13 13:59:17 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		l;
	int		i;
	int		k;
	char	*newstr;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	i = 0;
	while (s[l - 1] == ' ' || s[l - 1] == ','
			|| s[l - 1] == '\n' || s[l - 1] == '\t')
		l--;
	while (l > 0 && (s[i] == ' ' || s[i] == ','
				|| s[i] == '\n' || s[i] == '\t'))
		i++;
	l = l - i;
	newstr = ft_strnew(l);
	if (!newstr)
		return (NULL);
	k = 0;
	while (k < l)
		*(newstr + k++) = *(s + i++);
	return (newstr);
}
