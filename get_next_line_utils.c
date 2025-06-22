/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:12:01 by pecavalc          #+#    #+#             */
/*   Updated: 2025/06/22 06:09:45 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

t_gnl_node	*search_or_add_node_front(t_gnl_node **lst_head, int fd)
{
	t_gnl_node			*node;

	if (fd < 0)
		return (NULL);
	node = *lst_head;
	while (node)
	{
		if (node->file.fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_gnl_node *)malloc(sizeof(t_gnl_node));
	if (!node)
		return (NULL);
	node->file.fd = fd;
	node->file.buffer = NULL;
	node->file.position = 0;
	node->file.nr_bytes_read = 0;
	node->file.error_flag = 1;
	node->previous = NULL;
	node->next = *lst_head;
	if (*lst_head)
		(*lst_head)->previous = node;
	*lst_head = node;
	return (node);
}

void	delete_node(t_gnl_node **lst_head, t_gnl_node *node)
{
	if (!node)
		return ;
	if (node->previous != NULL)
		node->previous->next = node->next;
	else
		*lst_head = node->next;
	if (node->next != NULL)
		node->next->previous = node->previous;
	if (node->file.buffer != NULL)
	{
		free (node->file.buffer);
		node->file.buffer = NULL;
	}
	free(node);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
