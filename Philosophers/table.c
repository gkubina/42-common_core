/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/03/04 18:07:15 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	endnow(t_philos *philos)
{
	pthread_mutex_lock(&(philos->end_mut));
	if (philos->end_game)
	{
		pthread_mutex_unlock(&(philos->end_mut));
		return (1);
	}
	pthread_mutex_unlock(&(philos->end_mut));
	return (0);
}

static int	all_filled(t_philos *philos)
{
	size_t	i;

	i = 0;
	while (i < philos->nb_phil)
	{
		pthread_mutex_lock(&(philos->sopher[i].eat_mut));
		if (philos->sopher[i].status == ALIVE)
		{
			pthread_mutex_unlock(&(philos->sopher[i].eat_mut));
			return (0);
		}
		pthread_mutex_unlock(&(philos->sopher[i].eat_mut));
		i++;
	}
	return (1);
}

static void	*doctor(void *param)
{
	t_philos		*philos;
	size_t			i;

	i = 0;
	philos = (t_philos *)param;
	while (!(endnow(philos)))
	{
		pthread_mutex_lock(&(philos->sopher[i].eat_mut));
		if ((get_time() - philos->sopher[i].last_meal) > philos->die_time
			&& !(philos->sopher[i].status == FILLED))
		{
			philos->sopher[i].status = DEAD;
			end_game(philos);
			phil_log(philos, i, DIED);
		}
		pthread_mutex_unlock(&(philos->sopher[i].eat_mut));
		if (i < philos->nb_phil - 1)
			i++;
		else
			i = 0;
		if (all_filled(philos))
			end_game(philos);
		usleep(20);
	}
	return (0);
}

static void	*philosoph(void *param)
{
	t_philos	*philos;
	t_sopher	*sopher;

	sopher = (t_sopher *)param;
	philos = (t_philos *)sopher->philos;
	if (philos->nb_phil == 1)
		ft_ms_sleep(philos->die_time + 5);
	else
	{
		if (philos->nb_phil % 2 == 0 && sopher->id % 2 != 0)
			ft_ms_sleep(5);
		else if (philos->nb_phil % 2 == 1 && sopher->id % 2 != 0
			&& (((2 * philos->eat_time) - philos->sleep_time) > 0))
			ft_ms_sleep(((((2 * philos->eat_time)
							- philos->sleep_time) * 4) / 10));
		while (!endnow(philos))
		{
			eat(sopher);
			s_sleep(sopher);
			think(sopher);
		}
	}
	return (0);
}

int	a_table(t_philos *philos)
{
	size_t	i;

	i = 0;
	pthread_create(&(philos->doctor), NULL, &doctor, (void *)philos);
	while (i < philos->nb_phil)
	{
		if (pthread_create(&(philos->sopher[i].tr), NULL, &philosoph,
				(void *)&(philos->sopher[i])) != 0)
		{
			printf("Problem Creating Thread.\n");
			break ;
		}
		i++;
	}
	while (i > 0)
	{
		i--;
		if (pthread_join(philos->sopher[i].tr, NULL) != 0)
		{
			printf("Problem Joining Thread.\n");
			break ;
		}
	}
	pthread_join(philos->doctor, NULL);
	return (0);
}
