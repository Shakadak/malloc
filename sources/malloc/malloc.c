/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 12:59:11 by npineau           #+#    #+#             */
/*   Updated: 2014/04/17 17:19:02 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"

static void	*malloc_tiny(size_t size)
{
	if (g_content_table.tiny == null)
	{
		g_content_table.tiny = mmap(null, 1, prot_read | prot_write,
				map_anon | map private, -1, 0);
	}
	return (get_free_space((size / 16 + 1) * size));
}

void	*malloc_small(size_t size)
{
	if (g_content_table.small == null)
	{
		g_content_table.small = mmap(null, 65536, prot_read | prot_write,
				map_anon | map private, -1, 0);
	}
	return (get_free_space((size / 512 + 1) * size));
}

void	*malloc(size_t size)
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
