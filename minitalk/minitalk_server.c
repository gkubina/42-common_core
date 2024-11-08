/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/01/02 16:38:21 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_stradd_char(char *s1, char c)
{
	size_t		len_s1;
	char		*join;

	len_s1 = 0;
	if (s1)
		len_s1 = ft_strlen(s1);
	join = malloc(len_s1 + 2);
	if (join == NULL)
	{
		if (s1)
			free (s1);
		return (NULL);
	}
	if (s1)
		ft_strlcpy(join, s1, len_s1 + 1);
	join[len_s1] = c;
	join[len_s1 + 1] = '\0';
	if (s1 != NULL)
		free (s1);
	return (join);
}

void	receive_char(int bit)
{
	static int		nb_bits;
	static char		c;
	static char		*message;

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
			write(1, message, ft_strlen(message));
			ft_putchar_fd('\n', 1);
			free(message);
			message = NULL;
		}
	}
}

static void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		receive_char(0);
	}
	else if (sig == SIGUSR2)
	{
		receive_char(1);
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("PID :%i \n\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (pid != -1)
	{
		sleep(1);
	}
	return (0);
}
