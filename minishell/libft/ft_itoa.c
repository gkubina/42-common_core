/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:13:46 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/21 18:29:34 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoabis(long long count, char *final, long long n, long long test)
{
	final[count] = '\0';
	while (count > 0)
	{
		count--;
		final[count] = n % 10 + '0';
		n = n / 10;
	}
	if (test == 1)
	{
		final[0] = '-';
	}
	return (final);
}

char	*ft_itoa(int n)
{
	char		*final;
	long long	count;
	long long	test;
	long long	bis;

	bis = (long long)n;
	test = 0;
	count = 1;
	while (bis / 10 != 0 && count++)
		bis = bis / 10;
	if ((long long)n < 0)
	{
		test = 1;
		count++;
		bis = (long long)n * (-1);
	}
	else
		bis = (long long)n;
	final = malloc((count + 1) * sizeof(char));
	if (!final)
		return (0);
	final = ft_itoabis(count, final, bis, test);
	return (final);
}
