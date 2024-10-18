/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:34:21 by iziane            #+#    #+#             */
/*   Updated: 2024/10/18 23:41:37 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

//Libs
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <strings.h>

//BEGIN: Structs
typedef struct s_gc_node
{
	void					*pointer;
	struct s_gc_node		*next;
}							t_gc_node;

typedef struct s_garbage_collector
{
	t_gc_node		*head;
	t_gc_node		*tail;
	size_t			size;
}					t_garbage_collector;
//END: Structs

//BEGIN: FNC-Prototyps
t_gc_node			*gc_create_node(void *pointer2mem);
void				gc_add_begin(void *pointer);
t_garbage_collector	*gc_init_garbage_collector(void);
void				gc_print_linked_list(t_garbage_collector *gc);
void				gc_free_all(void);
t_garbage_collector	*get_gc(void);
// void				*ft_malloc(size_t size);
void				*ft_malloc(size_t size);
void				main_cleanup(uint8_t exit_stat);
void				ft_error(char *msg, char *file, int line, uint8_t exit_stat);
//END: FNC-Prototyps

#endif
