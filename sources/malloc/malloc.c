/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 12:59:11 by npineau           #+#    #+#             */
/*   Updated: 2014/04/17 18:36:41 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"

static void	alloc(size_t size, void *table, void **last_search)
{
	if (last_search == NULL)
	{
		(unsigned int)*table = (unsigned int)size;
		**last_search = (void *)(table + size + sizeof(unsigned int);
		**(last_search + sizeof(void *))
}

static void	*malloc_tiny(size_t size)
{
	if (g_table.tiny == null)
	{
		g_table.tiny = mmap(null, 1, prot_read | prot_write,
				map_anon | map private, -1, 0);
	}
	return (alloc((size / 16 + 1) * size, g_table.tiny, &g_table.last_tiny));
}

static void	*malloc_small(size_t size)
{
	if (g_table.small == null)
	{
		g_table.small = mmap(null, 65536, prot_read | prot_write,
				map_anon | map private, -1, 0);
	}
	return (alloc((size / 512 + 1) * size, g_table.small, g_table.last_small));
}

void		*malloc(size_t size)
{
	if (size >= LARGE)
	{
		return (mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
					-1, 0));
	}
	else if (size >= SMALL)
		return (malloc_small(size));
	else
		return (malloc_tiny(size));
}
