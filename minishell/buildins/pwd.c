/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:47:20 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/18 10:27:26 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_pipex *pipex)
{
	char	*buf;
	int		size;

	size = 1024;
	buf = malloc(sizeof(char) * size);
	if (buf == NULL)
		error_handler(MALLOC_ERROR, pipex, 1);
	while (getcwd(buf, size) == NULL)
	{
		size += 1024;
		free (buf);
		buf = malloc(sizeof(char) * (size));
		if (buf == NULL)
			error_handler(MALLOC_ERROR, pipex, 1);
	}
	write (1, buf, ft_strlen(buf));
	write (1, "\n", 1);
	free(buf);
}
