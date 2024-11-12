/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:28:27 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/07 13:28:45 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/get_next_line_bonus.h"
#include <unistd.h>

static char	*read_and_store(int fd, char *buff);
static char	*extract_line(char *buff);
static char	*update_buffer(char *buff);

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (!buffer[fd])
	{
		buffer[fd] = malloc(1);
		if (!buffer[fd])
			return (NULL);
		buffer[0] = NULL;
	}
	buffer[fd] = read_and_store(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}

static char	*read_and_store(int fd, char *buff)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buff, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			free (buff);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		buff = ft_strjoin(buff, buffer);
	}
	if (bytes_read == 0 && buff[0] == '\0')
	{
		free(buff);
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (buff);
}

static char	*extract_line(char *buff)
{
	size_t	line_size;
	size_t	i;
	char	*line;

	line_size = 0;
	if (!buff)
		return (NULL);
	while (buff[line_size] && buff[line_size] != '\n')
		line_size++;
	line_size++;
	line = malloc(sizeof(char) * (line_size + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < line_size)
		line[i] = buff[i];
	line[i] = '\0';
	return (line);
}

static char	*update_buffer(char *buff)
{
	size_t	i;
	size_t	j;
	char	*buffer;

	if (!buff)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (ft_strlen(buff) - i));
	if (!buffer)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		buffer[j++] = buff[i++];
	buffer[j] = '\0';
	free(buff);
	return (buffer);
}
