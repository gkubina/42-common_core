/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/05/29 15:01:11 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

void	pixel_to_img(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->img_pixels_ptr + offset)) = color;
}

int	pixel_from_img(t_img *img, int x, int y)
{
	int	offset;
	int	color;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	color = *((unsigned int *)(img->img_pixels_ptr + offset));
	return (color);
}
