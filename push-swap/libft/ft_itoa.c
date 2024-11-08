/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:18:02 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/24 11:48:19 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static long	negator(int n)
{
	long	nlong;

	nlong = (long)n;
	if (nlong < 0)
		return (nlong * -1);
	return (nlong);
}

static size_t	stringlength(long n)
{
	size_t	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	long	num;

	num = negator (n);
	len = stringlength(num) + is_negative(n);
	s = (char *) malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	while (--len > 0)
	{
		s[len] = '0' + (num % 10);
		num = num / 10;
	}
	if (is_negative(n) == 1)
		s[len] = '-';
	else
		s[len] = '0' + (num % 10);
	return (s);
}
