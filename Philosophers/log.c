/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/03/04 17:27:11 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_game(t_philos *philos)
{
	pthread_mutex_lock(&(philos->end_mut));
	philos->end_game = 1;
	pthread_mutex_unlock(&(philos->end_mut));
}

void	phil_log(t_philos *philos, int p, int message)
{
	pthread_mutex_lock(&(philos->log_mut));
	if (message == TAKEN_FORK && !(endnow(philos)))
		printf("%ld %d has taken a fork\n",
			time_elapsed(philos->starttime), p + 1);
	else if (message == EATING && !(endnow(philos)))
		printf("%ld %d is eating\n", time_elapsed(philos->starttime), p + 1);
	else if (message == SLEEPING && !(endnow(philos)))
		printf("%ld %d is sleeping\n", time_elapsed(philos->starttime), p + 1);
	else if (message == THINKING && !(endnow(philos)))
		printf("%ld %d is thinking\n", time_elapsed(philos->starttime), p + 1);
	else if (message == DIED)
		printf("%ld %d died\n", time_elapsed(philos->starttime), p + 1);
	pthread_mutex_unlock(&(philos->log_mut));
}
