/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/02/06 10:57:23 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex complex)
{
	int			i;
	t_complex	mandelbrot;

	mandelbrot.i = 0;
	mandelbrot.r = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		mandelbrot = calc_complex(calc_complex(mandelbrot, mandelbrot,
					COMPL_MUL), complex, COMPL_ADD);
		if ((mandelbrot.i * mandelbrot.i + mandelbrot.r * mandelbrot.r)
			>= INFINI)
			break ;
		i++;
	}
	if (i == MAX_ITER)
		return (0);
	else
		return (i);
}

int	julia(t_complex complex, t_complex c)
{
	int		i;

	i = 0;
	while (i < MAX_ITER)
	{
		complex = calc_complex(calc_complex(complex, complex, COMPL_MUL),
				c, COMPL_ADD);
		if ((complex.i * complex.i + complex.r * complex.r) >= INFINI)
			break ;
		i++;
	}
	if (i == MAX_ITER)
		return (0);
	else
		return (i);
}

int	burning_ship(t_complex complex)
{
	int			i;
	t_complex	burn;

	burn.i = 0;
	burn.r = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		burn.i = ft_abs(0, burn.i);
		burn.r = ft_abs(0, burn.r);
		burn = calc_complex(calc_complex(burn, burn, COMPL_MUL),
				complex, COMPL_ADD);
		if ((burn.i * burn.i + burn.r * burn.r) >= INFINI)
			break ;
		i++;
	}
	if (i == MAX_ITER)
		return (0);
	else
		return (i);
}

t_complex	next_mandel(t_win *window)
{
	static int	x;
	static int	y;
	t_complex	complex;

	while (y < HGT)
	{
		while (x < WID)
		{
			complex = get_complex(x, y, window->zoom);
			if (mandelbrot(complex) == 0)
				return (complex);
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
	return (complex);
}
