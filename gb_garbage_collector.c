/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:49:05 by iziane            #+#    #+#             */
/*   Updated: 2024/10/19 01:12:21 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	gc_free_all(void)
{
	int					len;
	int					i;
	t_gc_node			*temp;
	t_gc_node			*current;
	t_garbage_collector	*gc;

	gc = get_gc();
	current = gc->head;
	len = gc->size;
	i = -1;
	while (++i < len && current)
	{
		temp = current->next;
		free(current->pointer);
		current->pointer = NULL;
		free(current);
		current = NULL;
		current = temp;
	}
	gc = NULL;
}

t_gc_node	*gc_create_node(void *pointer2mem)
{
	t_gc_node	*new_node;

	new_node = (t_gc_node *)malloc(sizeof(t_gc_node) * 1);
	if (!new_node)
		return (NULL);
	new_node->pointer = pointer2mem;
	return (new_node);
}

/*
	Function that will be used after Malloc
*/
void	gc_add_begin(void *pointer)
{
	t_gc_node			*new_node;
	t_garbage_collector	*gc;

	if (!pointer)
		return ;
	gc = get_gc();
	new_node = gc_create_node(pointer);
	if (!new_node)
		ft_error("malloc fail", __FILE__, __LINE__, 1);
	if (gc->head == NULL)
	{
		new_node->next = NULL;
		gc->head = new_node;
		gc->tail = new_node;
	}
	else
	{
		new_node->next = (gc->head);
		gc->head = new_node;
	}
	gc->size++;
}

t_garbage_collector	*gc_init_garbage_collector(void)
{
	t_garbage_collector	*gc;

	gc = get_gc();
	gc->head = NULL;
	gc->tail = NULL;
	gc->size = 0;
	return (gc);
}

// int	main(void)
// {
// 	int	*arr;

// 	gc_init_garbage_collector();
// 	arr = (int *)ft_malloc(sizeof(int) * 10);
// 	if (!arr)
// 		return (1);
// 	arr[0] = 42;
// 	printf("First element: %d\n", arr[0]);
// 	main_cleanup(0);
// 	return (0);
// }
