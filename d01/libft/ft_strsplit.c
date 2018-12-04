/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:51:10 by abchan            #+#    #+#             */
/*   Updated: 2018/03/13 14:00:56 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(const char *str, char c)
{
	int i;
	int l;

	i = 0;
	l = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		l++;
	}
	return (l);
}

static int	wordcount(char const *s, char c)
{
	int count;
	int i;
	int seperator;

	count = 0;
	i = 0;
	seperator = 1;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			seperator = 1;
			i++;
		}
		while (s[i] != c && seperator == 0 && s[i] != '\0')
			i++;
		if (s[i] != c && seperator == 1 && s[i] != '\0')
		{
			count++;
			i++;
			seperator = 0;
		}
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		wcounter;
	int		scounter;
	int		i;
	char	**wordstr;

	if (!s ||
		!(wordstr = (char **)malloc(sizeof(*wordstr) * (wordcount(s, c) + 1))))
		return (NULL);
	wcounter = -1;
	scounter = 0;
	while (++wcounter < wordcount(s, c))
	{
		i = 0;
		if (!(wordstr[wcounter] =
			(char *)ft_strnew(ft_wordlen(&s[scounter], c) + 1)))
			return (NULL);
		while (s[scounter] == c)
			scounter++;
		while (s[scounter] != c && s[scounter] != '\0')
			wordstr[wcounter][i++] = s[scounter++];
		wordstr[wcounter][i] = '\0';
	}
	wordstr[wcounter] = 0;
	return (wordstr);
}
