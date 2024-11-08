/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:41:15 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/22 13:29:51 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_find_home(char **env)
{
	int	i;

	i = 0;
	while (env[i] && ft_strncmp("HOME=", env[i], 5) != 0)
		i++;
	return (env[i]);
}

void	ft_cd(t_pipex *pipex)
{
	int		i;
	char	*oldcwd;
	char	*env;

	i = 0;
	oldcwd = getcwd(NULL, 0);
	env = ft_find_home(pipex->env);
	if (oldcwd == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	while (pipex->commands->args[i] != NULL)
		i++;
	if (i > 2)
	{
		write(2, "too many arguments.\n", 20);
		pipex->err_no = 1;
		ft_update_oldpwd_pwd(pipex, oldcwd);
	}
	else
		ft_cd_suite(pipex, oldcwd, i, env);
}
