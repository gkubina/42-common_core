/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/03/04 17:46:29 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parse_arguments(t_philos *philos, int argc, char **argv)
{
	philos->starttime = get_time();
	if (argc == 5 && ft_isnumber(argv[1]) && ft_isnumber(argv[2])
		&& ft_isnumber(argv[3]) && ft_isnumber(argv[4]))
	{
		philos->nb_phil = ft_atoi(argv[1]);
		philos->die_time = ft_atoi(argv[2]);
		philos->eat_time = ft_atoi(argv[3]);
		philos->sleep_time = ft_atoi(argv[4]);
		philos->max_eats = MAX_EATS;
		if (philos->nb_phil > 0 && philos->nb_phil < MAX_PHILS)
			return (0);
	}
	else if (argc == 6 && ft_isnumber(argv[1]) && ft_isnumber(argv[2])
		&& ft_isnumber(argv[3]) && ft_isnumber(argv[4])
		&& ft_isnumber(argv[5]))
	{
		philos->nb_phil = ft_atoi(argv[1]);
		philos->die_time = ft_atoi(argv[2]);
		philos->eat_time = ft_atoi(argv[3]);
		philos->sleep_time = ft_atoi(argv[4]);
		philos->max_eats = ft_atoi(argv[5]);
		if (philos->nb_phil > 0 && philos->nb_phil < MAX_PHILS)
			return (0);
	}
	return (-1);
}

static int	table_setup(t_philos *philos)
{
	size_t	i;

	i = 0;
	pthread_mutex_init(&(philos->log_mut), NULL);
	pthread_mutex_init(&(philos->end_mut), NULL);
	pthread_mutex_init(&(philos->stat_mut), NULL);
	pthread_mutex_init(&(philos->fork_mut), NULL);
	philos->end_game = 0;
	philos->starttime = get_time();
	while (i < philos->nb_phil)
	{
		philos->sopher[i].id = i;
		philos->sopher[i].status = ALIVE;
		philos->sopher[i].fork_1 = NOFORK;
		philos->sopher[i].fork_2 = NOFORK;
		philos->sopher[i].activity = THINKING;
		philos->sopher[i].philos = (void *)philos;
		philos->sopher[i].last_meal = philos->starttime;
		philos->sopher[i].nb_meals = 0;
		pthread_mutex_init(&(philos->sopher[i].eat_mut), NULL);
		i++;
	}
	return (0);
}

static int	fork_setup(t_philos *philos)
{
	size_t	i;

	i = 0;
	while (i < philos->nb_phil)
	{
		pthread_mutex_init(&(philos->fork[i].mut), NULL);
		philos->fork[i].status = AVAILABLE;
		i++;
	}
	return (0);
}

static int	cleanup(t_philos *philos)
{
	size_t	i;

	i = 0;
	while (i < philos->nb_phil)
	{
		pthread_mutex_destroy(&(philos->sopher[i].eat_mut));
		pthread_mutex_destroy(&(philos->fork[i].mut));
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philos	philos;

	if (parse_arguments(&philos, argc, argv) != -1)
	{
		table_setup(&philos);
		fork_setup(&philos);
		a_table(&philos);
		cleanup(&philos);
		pthread_mutex_destroy(&(philos.log_mut));
		pthread_mutex_destroy(&(philos.end_mut));
		pthread_mutex_destroy(&(philos.stat_mut));
		pthread_mutex_destroy(&(philos.fork_mut));
	}
	else
	{
		printf("Error! Arguments needed :\n");
		printf("./philo number_of_philosophers(1 up to %d)", MAX_PHILS);
		printf(" time_to_die time_to_eat time_to_sleep [number_of_");
		printf("times_each_philosopher_must_eat, (default: %d)]\n\n", MAX_EATS);
	}
	return (0);
}
