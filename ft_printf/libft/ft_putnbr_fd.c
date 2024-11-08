/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:55:07 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/24 16:22:46 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_unsig_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd('0' + n, fd);
	else
	{
		ft_putnbr_unsig_fd(n / 10, fd);
		ft_putnbr_unsig_fd(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_unsig_fd(n * -1, fd);
	}
	else
		ft_putnbr_unsig_fd(n, fd);
}
