/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:26:00 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/18 12:44:47 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (void *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

/*
int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		size_t n = 10;
		int c = 'h';
		char *str = argv[1];
		void *result = ft_memchr(str, c, n);
		printf(result, "%ld");
		void *resultBis = memchr(str, c, n);
		printf(resultBis, "%ld");
	}
}*/
