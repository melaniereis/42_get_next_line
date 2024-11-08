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

#include "./get_next_line.h"
#include <unistd.h>

static char	*read_and_store(int fd, char *buff);
static char	*extract_line(char *buff);
static char	*update_buffer(char *buff);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_store(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = update_buffer(buffer);
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
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		buff = ft_strjoin(buff, buffer);
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
	line = malloc(sizeof(char) * (line_size + 1)); // +1 for '\0'
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
	char	*buffer;
	size_t i;
	size_t j;

	if (!buff)
		return (NULL);
	i = 0;
	while (buff[i] != '\n')
		i++;
	i++;
	buffer = malloc(sizeof(char) * i);
	if (!buffer)
		return (NULL);
	j = 0;
	while (buff[i])
		buffer[j++] = buff[i++];
	buffer[j] = '\0';
	free(buff);
	return (buffer);
}
