/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:58:50 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/19 10:06:24 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// remplir les premiers n bytes de memoire pointe par s avec c
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main(int argc, char **argv) 
{
	if (argc)
	{
		void *s = argv[1];
		int c = 'W';
		size_t n = 3;
		void *result = ft_memset(s,c,n);
		printf(result, "ld");
		void *resultBis = memset(s,c,n);
		printf(resultBis, "ld");
	}
}*/
