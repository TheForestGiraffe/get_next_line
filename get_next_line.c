/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:12:01 by pecavalc          #+#    #+#             */
/*   Updated: 2025/06/22 06:49:51 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl_node	*lst_head = NULL;
	t_gnl_node			*node;
	char				*line;

	node = search_or_add_node_front(&lst_head, fd);
	if (!node)
		return (NULL);
	line = NULL;
	next_line(&node->file, &line);
	if ((!line) || (node->file.error_flag == -1))
	{
		delete_node(&lst_head, node);
		return (NULL);
	}
	else if (!line)
		return (NULL);
	return (line);
}

void	next_line(t_gnl_file *file, char **line)
{
	char	*c;
	size_t	position;
	size_t	length;

	position = 0;
	length = 0;
	c = next_char(file);
	while (c)
	{
		if (position >= length)
		{
			*line = realloc_line(file, *line, &length);
			if (!*line)
				return ;
		}
		(*line)[position++] = *c;
		if (*c == '\n')
		{
			(*line)[position++] = '\0';
			return ;
		}
		c = next_char(file);
	}
	last_line(&position, line);
}

void	last_line(size_t *position, char **line)
{
	if ((*position > 0) && (*line != NULL))
		(*line)[*position] = '\0';
	else
	{
		free(*line);
		*line = NULL;
	}
}

char	*realloc_line(t_gnl_file *file, char *line, size_t *length)
{
	char	*new_line;
	size_t	size;

	if (*length == 0)
	{
		if (BUFFER_SIZE < 2)
			size = 2;
		else
			size = BUFFER_SIZE + 1;
	}
	else
		size = (*length * 2 + 1);
	new_line = (char *)malloc(size);
	if (!new_line)
	{
		file->error_flag = -1;
		return (NULL);
	}
	if (line)
	{
		ft_memcpy(new_line, line, *length);
		free(line);
	}
	*length = size -1;
	return (new_line);
}

char	*next_char(t_gnl_file *file)
{
	char	*c;

	if (BUFFER_SIZE < 1)
		return (NULL);
	if (!file->buffer)
		file->buffer = (char *)malloc(BUFFER_SIZE);
	if (!file->buffer)
		return (NULL);
	if (file->position >= file->nr_bytes_read)
	{
		file->position = 0;
		file->nr_bytes_read = read(file->fd, file->buffer, BUFFER_SIZE);
		if (file->nr_bytes_read == -1)
		{
			file->error_flag = -1;
			free(file->buffer);
			file->buffer = NULL;
			return (NULL);
		}
		if (file->nr_bytes_read == 0)
			return (NULL);
	}
	c = &file->buffer[file->position];
	file->position++;
	return (c);
}
