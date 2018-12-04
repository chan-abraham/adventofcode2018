/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:46:24 by abchan            #+#    #+#             */
/*   Updated: 2018/04/24 21:12:19 by abchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** this is the main function that checks for the end of a line.
** a pointer points to save, and iterates until it gets to a newline or a null
** terminator. if it is a newline, it saves it to line, and sets the save 
** as whatever is remainder after the newline.
*/

int				check_it(char **line, char **save)
{
	char		*theline;

	theline = *save;
	while (*theline != '\n' && *theline != '\0')
		theline++;
	if (*theline == '\n')
	{
		*line = ft_strsub(*save, 0, theline - *save);
		ft_memmove(*save, theline + 1, ft_strlen(theline));
		return (1);
	}
	return (0);
}

/*
** this function is necessary for the way i wrote gnl. if there is no newline
** ending the file, this would save that information to the line, and clear the save
*/

int				doublecheck_it(char **line, char **save, const int fd)
{
	if (!(check_it(line, &save[fd])))
	{
		if (save[fd][0] == '\0')
			return (0);
		*line = ft_strdup(save[fd]);
		ft_strclr(save[fd]);
	}
	return (1);
}

/*
** this function merges existing save with buf. the whole thing with creating
** a tmp and all that messy garbage is so the previous save can be properly deleted.
** i think there is a cleaner way to do it but im a noob and this makes sense to me and
** this works and i can't be bothered
*/

static char		*copy_it(char *buf, char *save)
{
	char		*tmp;

	tmp = ft_strjoin(save, buf);
	ft_memdel((void **)&save);
	save = ft_strdup(tmp);
	ft_memdel((void **)&tmp);
	return (save);
}

/*
** this function creates a new "save" from what was read if one didnt exist
** or sends existing save and newly read to the merging function
*/

char			*save_it(char **save, char *buf, int readit)
{
	if (*save)
	{
		*save = copy_it(buf, *save);
		return (*save);
	}
	if (!*save)
	{
		*save = ft_strnew(readit);
		ft_memcpy(*save, buf, readit);
		return (*save);
	}
	return (0);
}

/*
** this function reads and sends stuff to their functions and checks crap
** the save array is 5000, apparently this is around max fd
** i didn't really do much research into this but some guy told me
** hes really smart so i believed him. 
*/

int				get_next_line(const int fd, char **line)
{
	static char	*save[5000];
	char		buf[BUFF_SIZE + 1];
	int			readit;

	while ((readit = read(fd, buf, BUFF_SIZE)))
	{
		if (fd < 0 || !line || readit < 0)
			return (-1);
		buf[readit] = '\0';
		save[fd] = save_it(&save[fd], buf, readit);
		if ((readit = check_it(line, &save[fd])) != 0)
			return (1);
	}
	if (readit == 0 && save[fd])
	{
		if (!(doublecheck_it(line, save, fd)))
			return (0);
		return (1);
	}
	return (readit);
}
