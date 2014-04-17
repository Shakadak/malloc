/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 13:08:02 by npineau           #+#    #+#             */
/*   Updated: 2014/04/17 17:27:12 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/type.h>

typedef struct	s_table
{
	void		*tiny;
	void		*last_tiny;
	void		*small;
	void		*last_small;
}				t_table;

extern t_table	g_table;

void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			free(void *ptr);
void			show_alloc_mem(void);

#endif
