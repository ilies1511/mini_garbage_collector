/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:49:19 by iziane            #+#    #+#             */
/*   Updated: 2024/10/17 23:49:21 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <garbage_collector.h>

// TODO: gc_overwrite();

t_garbage_collector	*get_gc(void)
{
	static t_garbage_collector	gc = {0};

	return (&gc);
}

void	gc_print_linked_list(t_garbage_collector *gc)
{
	if (!gc)
		return ;
	printf("Len of Linked List: %zu\n", gc->size);
	return ;
}

//TODO:
void	*ft_malloc(size_t len)
{
	void	*ptr;

	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	gc_add_begin(ptr);
	return (ptr);
}
