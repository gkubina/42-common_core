/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/03/04 18:43:35 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sec_fork(t_philos *philos, size_t fork)
{
	int	sec_fork;

	if (fork == philos->nb_phil - 1)
		sec_fork = 0;
	else
		sec_fork = fork + 1;
	return (sec_fork);
}

static void	pick_forks(t_philos *philos, int fork, size_t id)
{
	int	fork_2;

	fork_2 = sec_fork(philos, fork);
	pthread_mutex_lock(&(philos->fork_mut));
	pthread_mutex_lock(&(philos->fork[fork].mut));
	pthread_mutex_lock(&(philos->fork[fork_2].mut));
	if (philos->fork[fork].status == AVAILABLE
		&& philos->fork[fork_2].status == AVAILABLE)
	{
		philos->fork[fork].status = IN_USE;
		phil_log(philos, id, TAKEN_FORK);
		philos->fork[fork_2].status = IN_USE;
		phil_log(philos, id, TAKEN_FORK);
		philos->sopher[id].fork_1 = OK;
		philos->sopher[id].fork_2 = OK;
	}
	pthread_mutex_unlock(&(philos->fork[fork_2].mut));
	pthread_mutex_unlock(&(philos->fork[fork].mut));
	pthread_mutex_unlock(&(philos->fork_mut));
}

static void	pose_forks(t_philos *philos, size_t id)
{
	size_t	fork;
	size_t	fork_2;

	fork = id;
	fork_2 = sec_fork(philos, fork);
	pthread_mutex_lock(&(philos->fork_mut));
	pthread_mutex_lock(&(philos->fork[fork].mut));
	pthread_mutex_lock(&(philos->fork[fork_2].mut));
	philos->fork[fork].status = AVAILABLE;
	philos->sopher[id].fork_1 = NOFORK;
	philos->fork[fork_2].status = AVAILABLE;
	philos->sopher[id].fork_2 = NOFORK;
	pthread_mutex_unlock(&(philos->fork[fork_2].mut));
	pthread_mutex_unlock(&(philos->fork[fork].mut));
	pthread_mutex_unlock(&(philos->fork_mut));
}

void	eat(t_sopher *sopher)
{
	t_philos	*philos;

	philos = (t_philos *)sopher->philos;
	while (sopher->fork_1 == NOFORK && sopher->fork_2 == NOFORK)
	{
		pick_forks(philos, (int)sopher->id, sopher->id);
		usleep(1);
	}
	pthread_mutex_lock(&(sopher->eat_mut));
	sopher->last_meal = get_time();
	pthread_mutex_unlock(&(sopher->eat_mut));
	sopher->activity = EATING;
	phil_log(philos, sopher->id, EATING);
	ft_ms_sleep(philos->eat_time);
	pose_forks(philos, sopher->id);
	sopher->nb_meals++;
	if (sopher->nb_meals == philos->max_eats)
	{
		pthread_mutex_lock(&(sopher->eat_mut));
		sopher->status = FILLED;
		pthread_mutex_unlock(&(sopher->eat_mut));
	}
}
