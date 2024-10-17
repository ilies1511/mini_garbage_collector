/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:44:11 by iziane            #+#    #+#             */
/*   Updated: 2024/10/17 23:46:35 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/garbage_collector/garbage_collector.h>

noreturn void	main_cleanup(uint8_t exit_stat)
{
	gc_free_all();
	ft_bzero(get_gc(), sizeof(t_garbage_collector));
	exit(exit_stat);
}


