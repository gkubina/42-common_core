/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/03/04 17:28:01 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	s_sleep(t_sopher *sopher)
{
	t_philos	*philos;

	philos = (t_philos *)sopher->philos;
	sopher->activity = SLEEPING;
	phil_log(philos, sopher->id, SLEEPING);
	ft_ms_sleep(philos->sleep_time);
}

void	think(t_sopher *sopher)
{
	t_philos	*philos;

	philos = (t_philos *)sopher->philos;
	sopher->activity = THINKING;
	phil_log(philos, sopher->id, THINKING);
	if (philos->nb_phil % 2 == 1
		&& (((2 * philos->eat_time) - philos->sleep_time) > 0))
		ft_ms_sleep(((((2 * philos->eat_time) - philos->sleep_time) * 4) / 10));
	else
		usleep(10);
}
