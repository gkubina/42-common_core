/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:39:26 by gkubina           #+#    #+#             */
/*   Updated: 2024/03/04 17:27:35 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>

# define MAX_EATS   10000
# define MAX_PHILS   500
# define IN_USE     1
# define AVAILABLE   0
# define ALIVE     1
# define DEAD   0
# define FILLED   2
# define TAKEN_FORK   1
# define EATING   2
# define SLEEPING   3
# define THINKING   4
# define DIED   5
# define OK   1
# define NOFORK   0

typedef struct s_sopher
{
	int					id;
	int					status;
	int					fork_1;
	int					fork_2;
	int					activity;
	size_t				nb_meals;
	size_t				last_meal;
	pthread_t			tr;
	void				*philos;
	pthread_mutex_t		eat_mut;
}				t_sopher;

typedef struct s_fork
{
	int				status;
	pthread_mutex_t	mut;
}				t_fork;

typedef struct s_philos
{
	size_t			starttime;
	size_t			nb_phil;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			max_eats;
	size_t			end_game;
	pthread_t		doctor;
	pthread_mutex_t	log_mut;
	pthread_mutex_t	end_mut;
	pthread_mutex_t	stat_mut;
	pthread_mutex_t	fork_mut;
	t_sopher		sopher[MAX_PHILS];
	t_fork			fork[MAX_PHILS];
}				t_philos;

int		a_table(t_philos *philos);
void	eat(t_sopher *sopher);
void	s_sleep(t_sopher *sopher);
void	think(t_sopher *sopher);
int		endnow(t_philos *philos);
void	end_game(t_philos *philos);

void	phil_log(t_philos *philos, int p, int message);

size_t	time_elapsed(size_t start_ms);
int		ft_ms_sleep(size_t ms);
size_t	get_time(void);

int		ft_atoi(const char *nptr);
int		ft_isnumber(char *s);

#endif
