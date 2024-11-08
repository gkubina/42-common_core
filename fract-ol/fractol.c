/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/02/06 10:57:36 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_win	window;

	window.zoom = init_zoom();
	if (init_fractal(&window.fractal, argc, argv) != -1
		&& config_x(&window) != MALLOC_ERROR)
	{
		sleep(1);
	}
	else
	{
		ft_printf("Error! Allowed Arguments are :\n");
		ft_printf("Mandelbrot / Julia <Cr> <Ci> / Burning_Ship \n");
		ft_printf("Concerning 'Julia':\n");
		ft_printf("Cr and Ci should be the Real part and the imaginary part ");
		ft_printf("of a complex number used as a Constant for Julia.\n");
		ft_printf("Advise: Choose Cr and Ci between -2 and 2.\n");
		ft_printf("Example : ./fractol Julia -0.532 0.456\n");
	}
	return (0);
}

static int	double_ok(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if ((string[i] >= '0' && string[i] <= '9')
			|| string[i] == '-' || string[i] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

int	init_fractal(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
	{
		fractal->type = 1;
		return (0);
	}
	else if (argc == 4 && ft_strncmp(argv[1], "Julia", 6) == 0
		&& double_ok(argv[2]) && double_ok(argv[3]))
	{
		fractal->type = 2;
		fractal->julia_c.r = ft_atod(argv[2]);
		fractal->julia_c.i = ft_atod(argv[3]);
		return (0);
	}
	if (argc == 2 && ft_strncmp(argv[1], "Burning_Ship", 13) == 0)
	{
		fractal->type = 3;
		return (0);
	}
	fractal->colorshift = 3;
	return (-1);
}
