/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:24:35 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/27 13:33:35 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_hd(t_commands *cmd)
{
	unlink(cmd->input);
	free(cmd->input);
	cmd->input = NULL;
	cmd->is_hd = 0;
}
