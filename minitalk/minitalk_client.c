/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/01/02 16:38:27 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(char car, int pid)
{
	int		nb_bits;
	int		bit;
	char	c;

	c = car;
	nb_bits = 8;
	bit = 0;
	while (nb_bits > 0)
	{
		bit = ((c >> (nb_bits - 1)) & 1);
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		nb_bits--;
		usleep(WAITTIME);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		pid;

	i = 0;
	pid = 0;
	if (argc == 3 && ft_atoi(argv[1]) > 0 && kill (ft_atoi(argv[1]), 0) == 0)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_char(argv[2][i], pid);
			i++;
		}
		send_char('\0', pid);
	}
	else
		ft_printf("Error!\n");
	return (0);
}
