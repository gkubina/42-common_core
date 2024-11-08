/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:06:35 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/14 12:06:37 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *file)
{
	ssize_t	bytes;
	char	*buffer;

	bytes = 1;
	buffer = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		free (file);
		return (NULL);
	}
	while (!(ft_strchr_gnl(file, '\n')) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(file);
			return (NULL);
		}
		buffer[bytes] = '\0';
		file = ft_strjoin_free(file, buffer);
	}
	free(buffer);
	return (file);
}

static char	*get_line(char *file)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!file)
		return (NULL);
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	if (file[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = (char *)malloc ((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line [j] = file[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*move_to_next_line(char *file)
{
	size_t	i;
	size_t	len;
	char	*next;

	i = 0;
	while (file && file[i] != '\0' && file[i] != '\n')
		i++;
	if (file && file[i] == '\n')
		i++;
	if (file && file[i] == '\0')
	{
		free(file);
		return (NULL);
	}
	len = ft_strlen_gnl(file);
	next = (char *)malloc ((len - i + 1) * sizeof(char));
	if (!next)
	{
		if (file)
			free(file);
		return (NULL);
	}
	ft_strlcpy_gnl(next, (char *)(file + i), len - i + 1);
	free (file);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*file[FD_MAX + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FD_MAX)
		return (NULL);
	file[fd] = read_file(fd, file[fd]);
	if (!file[fd])
		return (NULL);
	line = get_line(file[fd]);
	file[fd] = move_to_next_line(file[fd]);
	return (line);
}
