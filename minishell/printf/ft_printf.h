/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:19:04 by daleliev          #+#    #+#             */
/*   Updated: 2024/04/08 10:21:56 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int	ft_search(const char f, va_list ap);
int	ft_printf(const char *str, ...);
int	ft_printp(void *f, int len, int b);
int	ft_printx(unsigned int n, int len);
int	ft_printupperx(unsigned int n, int len);
int	ft_putchar(char c);
int	ft_putnbr(long long n, int len);
int	ft_putstr(char *s);
int	ft_putnbru_fd(unsigned long long n, int len);
#endif 
