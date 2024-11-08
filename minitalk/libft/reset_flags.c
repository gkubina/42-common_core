/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:22 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/07 17:12:25 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arginfo	reset_flags(t_arginfo old)
{
	t_arginfo	arginfo;

	arginfo = old;
	arginfo.spec = '0';
	arginfo.width = 0;
	arginfo.prec = 0;
	arginfo.preclen = 0;
	arginfo.flaglen = 0;
	arginfo.zeropad = 0;
	arginfo.alterf = 0;
	arginfo.leftad = 0;
	arginfo.blank = 0;
	arginfo.sign = 0;
	arginfo.is_zero = 0;
	arginfo.signer = 0;
	return (arginfo);
}
