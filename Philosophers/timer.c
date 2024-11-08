/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/03/04 17:27:44 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Returns number of milliseconds elapsed since start.
size_t	time_elapsed(size_t start_ms)
{
	size_t	now_ms;

	now_ms = get_time();
	if (start_ms > now_ms)
		return (((24 * 60 * 60 * 1000) - start_ms) + now_ms);
	return (now_ms - start_ms);
}

// Sleeps for ms Milliseconds
int	ft_ms_sleep(size_t ms)
{
	size_t	start;

	start = get_time();
	while (ms > time_elapsed(start))
		usleep(500);
	return (0);
}

size_t	get_time(void)
{
	struct timeval	now;
	size_t			now_ms;

	gettimeofday(&now, NULL);
	now_ms = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (now_ms);
}
