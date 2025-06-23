/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:14:43 by pecavalc          #+#    #+#             */
/*   Updated: 2025/06/23 02:35:11 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include <stddef.h>

typedef struct s_file {
	int				fd;
	char			*buffer;
	ssize_t			position;
	ssize_t			bytes_read;
}					t_gnl_file;

typedef struct s_node {
	t_gnl_file		file;
	struct s_node	*previous;
	struct s_node	*next;
}					t_gnl_node;

char		*get_next_line(int fd);
void		next_line(t_gnl_file *file, char **line);
char		*next_char(t_gnl_file *file);
void		realloc_line(char **line, size_t *length);
void		last_line(size_t *position, char **line);

// Utils
t_gnl_node	*search_or_add_node_front(t_gnl_node **lst_head, int fd);
void		delete_node(t_gnl_node **lst_head, t_gnl_node *node);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif
