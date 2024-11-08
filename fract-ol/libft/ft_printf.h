/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:22:08 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/09 09:05:17 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_arginfo
{
	int		zeropad;
	int		alterf;
	int		leftad;
	int		blank;
	int		sign;
	int		is_zero;
	int		len;
	int		width;
	int		prec;
	int		preclen;
	char	signer;
	char	spec;
	size_t	flaglen;
	size_t	count;
}			t_arginfo;

//int			ft_printf(const char *format, ...);
int			ft_printarg(t_arginfo arginfo, va_list args);
int			printstr(char *s, t_arginfo arginfo);
int			printperc(void);
int			printchar(char c, t_arginfo arginfo);
int			printint(int i, t_arginfo arginfo);
int			printhex_min(unsigned int i, t_arginfo arginfo);
int			printhex_maj(unsigned int i, t_arginfo arginfo);
int			printuint(unsigned int i, t_arginfo arginfo);
int			printpoint(unsigned long i, t_arginfo arginfo);
t_arginfo	fill_arginfo(const char *s, t_arginfo old);
t_arginfo	reset_flags(t_arginfo old);
t_arginfo	init_arginfo(void);
void		ft_putnbr_unsig_fd(unsigned int n, int fd);
int			intlength(int n);
void		ft_putnbr_base_16(unsigned int nbr, char *base);

#endif
