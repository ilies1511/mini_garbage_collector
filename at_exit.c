/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:44:11 by iziane            #+#    #+#             */
/*   Updated: 2024/10/18 20:21:27 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	main_cleanup(uint8_t exit_stat)
{
	gc_free_all();
	bzero(get_gc(), sizeof(t_garbage_collector));
	exit(exit_stat);
}

void	ft_error(char *msg, char *file, int line, uint8_t exit_stat)
{
	fprintf(stderr, "Error: File %s line %d: %s\n", file, line, msg);
	main_cleanup(exit_stat);
}
