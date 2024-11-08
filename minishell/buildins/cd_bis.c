/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:41:15 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/22 13:30:16 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_add_to_env(char *str, t_pipex *pipex)
{
	char	**temp;
	int		size;
	int		i;

	size = 0;
	while (pipex->env[size] != NULL)
		size++;
	temp = ft_calloc(sizeof(char *), (size + 2));
	if (temp == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	i = -1;
	while (++i < size)
		temp[i] = pipex->env[i];
	temp[i] = ft_strdup(str);
	if (temp[i] == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	temp[i + 1] = NULL;
	free(pipex->env);
	pipex->env = temp;
}

static void	ft_update_env(t_pipex *pipex, char *value)
{
	int	j;
	int	c;

	c = 0;
	while (value[c] != '=' && value[c] != '\0')
		c++;
	j = -1;
	while (pipex->env[++j] != NULL)
	{
		if (!ft_strncmp(pipex->env[j], value, c))
		{
			free(pipex->env[j]);
			pipex->env[j] = ft_strdup(value);
			if (pipex->env[j] == NULL)
				error_handler(MALLOC_ERROR, pipex, 1);
			return ;
		}
	}
	if (pipex->env[j] == NULL)
		ft_add_to_env(value, pipex);
}

void	ft_update_oldpwd_pwd(t_pipex *pipex, char *oldpwd)
{
	char	*env;
	char	*pwd;

	env = (char *) malloc ((8 + ft_strlen(oldpwd)) * sizeof(char));
	if (env == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	env[0] = '\0';
	ft_strlcat(env, "OLDPWD=", 8);
	ft_strlcat(env, oldpwd, ft_strlen(oldpwd) + 8);
	ft_update_env(pipex, env);
	free(env);
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	env = (char *) malloc ((5 + ft_strlen(pwd)) * sizeof(char));
	if (env == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	env[0] = '\0';
	ft_strlcat(env, "PWD=", 5);
	ft_strlcat(env, pwd, ft_strlen(pwd) + 5);
	ft_update_env(pipex, env);
	free(env);
	free(pwd);
	free(oldpwd);
}

static char	*ft_find_home(char **env)
{
	int	i;

	i = 0;
	while (env[i] && ft_strncmp("HOME=", env[i], 5) != 0)
		i++;
	return (env[i]);
}

void	ft_cd_suite(t_pipex *pipex, char *oldcwd, int i, char *env)
{
	if (i == 2)
	{
		if (chdir(pipex->commands->args[1]) == -1)
		{
			write(2, "not a valid identifier\n", 23);
			free(oldcwd);
			pipex->err_no = 1;
			return ;
		}
	}
	else
	{
		env = ft_find_home(pipex->env);
		if (!env || chdir(env + 5) == -1)
		{
			perror("cd");
			pipex->err_no = errno;
			free(oldcwd);
			return ;
		}
	}
	ft_update_oldpwd_pwd(pipex, oldcwd);
}
