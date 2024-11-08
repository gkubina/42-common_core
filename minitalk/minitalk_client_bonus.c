/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/01/15 13:09:41 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_last_sig;

static void	send_char(unsigned char car, int pid)
{
	int				nb_bits;
	int				bit;
	unsigned char	c;

	c = car;
	nb_bits = 8;
	bit = 0;
	while (nb_bits > 0)
	{
		g_last_sig = -1;
		bit = ((c >> (nb_bits - 1)) & 1);
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		nb_bits--;
		while (g_last_sig != bit)
		{
			if (sleep(4) == 0)
				ft_printf("Connection to server slow. Restart server...\n");
		}
	}
}

static void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_last_sig = 0;
	if (sig == SIGUSR2)
		g_last_sig = 1;
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	struct sigaction	action;

	i = 0;
	action.sa_flags = SA_SIGINFO;
	action.sa_handler = sig_handler;
	sigemptyset(&action.sa_mask);
	if (argc == 3 && ft_atoi(argv[1]) > 0
		&& !(sigaction(SIGUSR1, &action, NULL) == -1
			|| sigaction(SIGUSR2, &action, NULL) == -1)
		&& kill (ft_atoi(argv[1]), 0) == 0)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_char(argv[2][i], pid);
			i++;
		}
		send_char('\0', pid);
		ft_printf("Message sent and received correctly!\n");
	}
	else
		ft_printf("Error!\n");
	return (0);
}
