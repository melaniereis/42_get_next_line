/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:56:25 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/07 16:13:56 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:56:25 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/08 16:30:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*is_file_in_folder(const char *filename, const char *folder_path,
		char *full_path, size_t path_size)
{
	size_t	folder_len;
	size_t	file_len;

	folder_len = strlen(folder_path);
	file_len = strlen(filename);
	if (folder_len + file_len + 2 > path_size)
		return (NULL);
	strcpy(full_path, folder_path);
	if (folder_path[folder_len - 1] != '/')
		strcat(full_path, "/");
	strcat(full_path, filename);
	return (full_path);
}

int	main(int argc, char **argv)
{
	const char	*folder_path;
	char		full_path[1024];
	char		*line;
	int			fd;

	folder_path = "files";
	if (argc == 2)
	{
		if (is_file_in_folder(argv[1], folder_path, full_path, sizeof(full_path)))
		{
			printf("Testing file: %s\n", full_path);
			printf("Testing get_next_line w/ BUFFER_SIZE = %d\n\n", BUFFER_SIZE);
			fd = open(full_path, O_RDONLY);
			if (fd == -1)
			{
				printf("Error opening file.\n");
				return (1);
			}
			while ((line = get_next_line(fd)) != NULL)
			{
				printf("%s", line);
				free(line);
			}
			close(fd);
		}
		else
			printf("'%s' is not a valid file in the 'files' folder.\n", argv[1]);
	}
	else
		printf("Please execute the program again with a valid filename.\n");
	return (0);
}
