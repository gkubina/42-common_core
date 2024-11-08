/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/01/02 18:33:01 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static unsigned char	*ft_stradd_char(unsigned char *s1, unsigned char c)
{
	size_t			len_s1;
	unsigned char	*join;

	len_s1 = 0;
	if (s1)
		len_s1 = ft_strlen_u(s1);
	join = malloc((len_s1 + 2) * sizeof(unsigned char));
	if (join == NULL)
	{
		if (s1)
			free (s1);
		return (NULL);
	}
	if (s1)
		ft_strlcpy_u(join, s1, len_s1 + 1);
	join[len_s1] = c;
	join[len_s1 + 1] = '\0';
	if (s1 != NULL)
		free (s1);
	return (join);
}

static void	print_message(unsigned char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		write(1, &(message[i]), 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

static void	receive_char(int bit)
{
	static int					nb_bits;
	static unsigned char		c;
	static unsigned char		*message;

	if (message == NULL && nb_bits == 0)
		ft_printf("Receiving message.\n");
	if (bit == 0)
		c = (c << 1);
	else if (bit == 1)
		c = ((c << 1) | 1);
	nb_bits++;
	if (nb_bits == 8)
	{
		message = ft_stradd_char(message, c);
		nb_bits = 0;
		if (c == '\0')
		{
			print_message(message);
			free(message);
			message = NULL;
		}
	}
}

static void	sig_action(int sig, siginfo_t *info, void *other)
{
	(void)other;
	if (sig == SIGUSR1)
	{
		receive_char(0);
		kill(info->si_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
		receive_char(1);
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = sig_action;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		ft_printf("Error!\n");
	else
	{
		ft_printf("PID :%i \n\n", pid);
		while (pid != -1)
		{
			sleep(1);
		}
	}
	return (0);
}
