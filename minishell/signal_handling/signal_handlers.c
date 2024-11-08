/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/05/17 13:25:37 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_exit_code(t_pipex *pipex)
{
	if (g_last_sig)
	{
		pipex->err_no = 128 + g_last_sig;
		g_last_sig = 0;
	}
}

static void	sig_handler_rl(int sig)
{
	if (sig == SIGINT)
	{
		g_last_sig = SIGINT;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

// 19/5removed the printf, remplacer par write?

static void	sig_handler_exe(int sig)
{
	if (sig == SIGQUIT)
	{
		g_last_sig = SIGQUIT;
		printf("\n");
	}
	else if (sig == SIGINT)
	{
		g_last_sig = SIGINT;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

// modifs ici

static void	sig_handler_hd(int sig)
{
	if (sig == SIGQUIT)
	{
		g_last_sig = SIGQUIT;
		write(1, "\b\b  \b\b", 6);
	}
	else if (sig == SIGINT)
	{
		g_last_sig = SIGINT;
		printf("\n");
	}
}

void	setup_signal_handling(int state)
{
	struct sigaction	s_action_int;
	struct sigaction	s_action_quit;

	s_action_int.sa_flags = SA_RESTART;
	s_action_quit.sa_flags = SA_RESTART;
	sigemptyset(&(s_action_int.sa_mask));
	sigemptyset(&(s_action_quit.sa_mask));
	if (state == READLINE)
	{
		s_action_int.sa_handler = sig_handler_rl;
		s_action_quit.sa_handler = SIG_IGN;
	}
	else if (state == EXECUTION)
	{
		s_action_int.sa_handler = sig_handler_exe;
		s_action_quit.sa_handler = sig_handler_exe;
	}
	else if (state == HEREDOC)
	{
		s_action_int.sa_handler = sig_handler_hd;
		s_action_quit.sa_handler = sig_handler_hd;
		s_action_int.sa_flags = 0;
	}
	sigaction(SIGQUIT, &s_action_quit, NULL);
	sigaction(SIGINT, &s_action_int, NULL);
}
