/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:49:15 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/22 11:11:44 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	next_39(char *word, int start, int in_34)
{
	int	i;

	i = start;
	if (!(word[start] == 39 && !in_34))
		return (start + 1);
	while (word[++i] != '\0')
	{
		if (word[i] == 39)
			return (i);
	}
	return (start + 1);
}

static char	*expand(char *word, char *var, int start, t_pipex *pipex)
{
	char	*value;
	int		len_val;
	int		len_var;
	char	*new_word;

	value = get_value_from_env(var, pipex);
	len_val = ft_strlen(value);
	if (!ft_strncmp("''", value, 2) && len_val == 2)
		len_val = 0;
	len_var = ft_strlen(var);
	new_word = (char *) malloc ((ft_strlen(word)
				- len_var + len_val) * sizeof(char));
	if (new_word == NULL)
	{
		free(word);
		free(value);
		error_handler(MALLOC_ERROR, pipex, 1);
	}
	ft_strlcpy(new_word, word, start + 1);
	ft_strlcat(new_word, value, start + len_val + 1);
	ft_strlcat(new_word, word + start + len_var + 1,
		ft_strlen(word) - len_var + len_val);
	free(word);
	free(value);
	return (new_word);
}

static char	*variable(char *word, int start, t_pipex *pipex)
{
	int		i;
	int		end;
	char	*var;

	i = start + 1;
	if (word[i] == '?')
		end = i;
	else
	{
		while (word[i] == '_' || ft_isalnum(word[i]))
			i++;
		if (word[i] != '\0')
			i--;
		end = i;
	}
	var = (char *) malloc ((end - start + 1) * sizeof (char));
	if (var == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	i = -1;
	while (start < end)
	{
		var[++i] = word[++start];
	}
	var[++i] = '\0';
	return (var);
}

int	is_in_34(char *word, int i, int in_34)
{
	if (word[i] == 34 && !in_34)
		return (1);
	else if (word[i] == 34 && in_34)
		return (0);
	return (in_34);
}

char	*replace_vars(char *word, t_pipex *pipex)
{
	int		i;
	char	*var;
	char	*value;
	int		in_34;

	in_34 = 0;
	i = -1;
	while (word && word[++i] != '\0')
	{
		in_34 = is_in_34(word, i, in_34);
		i = next_39(word, i, in_34) - 1;
		if (word[i] == '$')
		{
			var = variable(word, i, pipex);
			value = get_value_from_env(var, pipex);
			word = expand(word, var, i, pipex);
			if (ft_strncmp("''", value, 2) != 0 && ft_strlen(value) != 2)
				i = i + ft_strlen(value) - 1;
			else
				i--;
			free(value);
			free(var);
		}
	}
	return (word);
}
