/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:40:32 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/27 13:16:14 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

# define MALLOC_ERROR 1
# define FORK_ERROR 2
# define PIPE_ERROR 3
# define ARG_ERROR 5
# define SIGNAL_ERROR 10

# define READLINE 1
# define EXECUTION 2
# define HEREDOC 3

# define IN 1
# define OUT 0

# define WORD 1
# define SEPARATOR 2
# define COMMAND 3
# define ARGUMENT 4
# define PIPE 5
# define REDIRECTION 6
# define INPUT_FILE 7
# define OUTPUT_FILE 8
# define IN_REDIR 9
# define IN_REDIR_HD 10
# define OUT_REDIR_AP 11
# define OUT_REDIR_OV 12
# define REDIR_FILE 13
# define LIMITER 14

extern volatile int	g_last_sig;

typedef struct s_commands
{
	struct s_commands	*next;
	struct s_commands	*prev;
	pid_t				pid;
	int					position;
	char				*cmd;
	char				**args;
	int					is_hd;
	char				*input;
	int					fd_input;
	char				*output;
	int					fd_output;
	int					error;
	int					fd[2];
}	t_commands;

typedef struct s_token
{
	char	**word;
	int		*type;
	int		size;
}	t_token;

typedef struct s_tokenlist
{
	char					*word;
	int						type;
	struct s_tokenlist		*next;
}	t_tokenlist;

typedef struct s_pipex
{
	t_commands	*commands;
	char		**lines;
	char		**env;
	char		**path;
	char		*tab;
	char		*entry;
	int			count;
	int			err_no;
	t_tokenlist	*tokenlist;
	t_token		*token;
}	t_pipex;

char		**ft_split_path(t_pipex *pipex);

int			create_tokenlist(char *line, t_pipex *pipex);
int			get_tokens(t_pipex *pipex);
int			precise_tokens(t_pipex *pipex);
char		*replace_vars(char *word, t_pipex *pipex);
void		remove_quotes(t_pipex *pipex);
char		*ft_add_quotes(char *s);
char		*get_value_from_env(char *var, t_pipex *pipex);

int			error_handler(int error, t_pipex *pipex, int close_prog);

void		destroy_all_allocations(t_pipex *pipex);
int			destroy_token(t_pipex *pipex);
int			destroy_tokenlist(t_pipex *pipex);
int			destroy_env(t_pipex *pipex);
int			destroy_path(t_pipex *pipex);
void		destroy_commands(t_pipex *pipex);
void		destroy_three_structs(t_pipex *pipex);

void		check_exit_code(t_pipex *pipex);
void		setup_signal_handling(int state);

void		shell(t_pipex *pipex);
int			ft_manage_entry(char *entry, t_pipex *pipex);
int			ft_check_separators(char *str);
int			ft_move_to_the_next_similar_c(char *str, int i, char c);
int			only_spaces(char *line);
int			ft_isspace(char c);
void		free_hd(t_commands *cmd);

void		ft_unset(t_pipex *pipex);
void		ft_pwd(t_pipex *pipex);
void		ft_export(t_pipex *pipex);

void		ft_cd_suite(t_pipex *pipex, char *oldcwd, int i, char *env);
void		ft_cd(t_pipex *pipex);
void		ft_update_oldpwd_pwd(t_pipex *pipex, char *oldpwd);
void		ft_echo(t_pipex *pipex);
void		ft_exit(t_pipex *pipex);
void		ft_env(t_pipex *pipex);

void		ft_manage_tokens(t_token *tokens, t_pipex *pipex, int i);
void		ft_open_files(t_commands *cmd,
				t_token *tokens, int i, t_pipex *pipex);

void		ft_execute(t_pipex *pipex);
void		ft_execute_builtins(t_pipex *pipex);
int			ft_is_builtins(char *str);
int			ft_handle_error(t_pipex *pipex);
void		ft_execcmd(t_pipex *pipex);
void		ft_manage_fd_in(t_pipex *pipex);
void		ft_manage_fd_out(t_pipex *pipex);
void		ft_manage_fd_onlychild(t_pipex *pipex);
void		ft_manage_fd_only_child_no_fork(t_pipex *pipex);
void		wait_children(t_pipex *pipex);

#endif
