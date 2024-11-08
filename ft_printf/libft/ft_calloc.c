/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:34:24 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/20 10:38:32 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*ret;

	ret = malloc (nmemb * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return ((void *)ret);
}
