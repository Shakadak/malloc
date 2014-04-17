/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 13:08:02 by npineau           #+#    #+#             */
/*   Updated: 2014/04/17 13:16:13 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

#include <sys/type.h>

typedef struct		s_mem
{
	size_t			size;
	void			*target;
	struct s_mem	*next;
}					t_mem;

typedef struct		s_table
{
	t_mem			*tiny;
	t_mem			*small;
	t_mem			*large;
}					t_table;

void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				free(void *ptr);
void				show_alloc_mem(void);

#endif /* ! MALLOC_H */
