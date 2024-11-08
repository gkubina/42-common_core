/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:49:15 by daleliev          #+#    #+#             */
/*   Updated: 2024/04/23 11:58:14 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	next_c(char c, char *word, int start)
{
	int	i;

	i = start;
	while (word[++i] != '\0')
	{
		if (word[i] == c)
			return (i);
	}
	return (start + 1);
}

static char	*remove_2_chars(char *word, int first, int second)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(word);
	i = -1;
	j = -1;
	while (++i <= len - 1)
	{
		if (i != first && i != second)
			word[++j] = word[i];
	}
	word[++j] = '\0';
	return (word);
}

void	remove_quotes(t_pipex *pipex)
{
	int				i;
	int				j;
	int				k;

	i = -1;
	while (++i < pipex->token->size)
	{
		if (pipex->token->type[i] != PIPE
			&& pipex->token->type[i] != REDIRECTION)
		{
			j = -1;
			while (pipex->token->word[i][++j] != '\0')
			{
				if (pipex->token->word[i][j] == 34
					|| pipex->token->word[i][j] == 39)
				{
					k = next_c(pipex->token->word[i][j],
							pipex->token->word[i], j);
					pipex->token->word[i]
						= remove_2_chars(pipex->token->word[i], j, k);
					j = k - 2;
				}
			}
		}
	}
}
