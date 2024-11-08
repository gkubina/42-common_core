/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:50:22 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/20 13:07:28 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*final;

	if (nmemb == 0 || size == 0)
	{
		final = malloc(1);
		if (final == NULL)
			return (NULL);
	}
	else
	{
		final = malloc(nmemb * size);
		if (final == NULL)
			return (NULL);
	}
	ft_memset(final, 0, nmemb * size);
	return (final);
}
