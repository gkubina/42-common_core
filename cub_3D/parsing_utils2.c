/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:47:00 by daleliev          #+#    #+#             */
/*   Updated: 2024/06/29 13:11:26 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	printf_error(void)
{
	printf("Error.\nYour ARGV[1] should be a file with authorisation who end");
	printf("in '.cub'.\nThe 1st part of your file should be the textures of ");
	printf("the walls with the 2 first letters\nof the direction follow by ");
	printf("their path in '.xpm' AND the color of the floor F and ceiling C");
	printf("\nFollow by their RGB values separated by ','.\n");
	printf("The second part will work only if the first one is correct. ");
	printf("It should be a map with ' ',\n1, 0 and one letter(E, W, S, N).");
	printf("All '0' should be surrounded by '1'. Your file should end with ");
	printf("the last line of your map.\nIf you put doors in the map :\n");
	printf("\t-The path to the texture should be like the others textures");
	printf(" precede by a 'D'\n\t-The line of the doors should NOT be the ");
	printf("last line of the 1st part.\n\t-In the second part, your doors");
	printf("should be represented with '2'\n\tYour doors should follow the");
	printf(" same rules of the '0'\n");
}

int	ft_atoi_color(char *str, int i, t_element *element, int *color)
{
	int				resultat;

	resultat = 0;
	while (ft_isspace_mod(str[i]) && str[i] != '\n')
		i++;
	if (str[i] < '0' || str[i] > '9')
		element->error++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + (str[i] - '0');
		if (resultat > 1000)
		{
			element->error++;
			return (0);
		}
		i++;
	}
	*color = resultat;
	return (i);
}

void	*ft_check_cl(char *str, t_element *element, t_values *color, int *ok)
{
	int	i;

	i = 0;
	if (!ft_isdigit(str[i]))
		element->error++;
	i = ft_atoi_color(str, i, element, &color->r);
	if (i == 0)
		return (NULL);
	i = move_to_next_nb(str, i, element);
	i = ft_atoi_color(str, i, element, &color->g);
	if (i == 0)
		return (NULL);
	i = move_to_next_nb(str, i, element);
	i = ft_atoi_color(str, i, element, &color->b);
	if (i == 0)
		return (NULL);
	if ((color->r >= 0 && color->r <= 255) && (color->g >= 0 && color->g <= 255)
		&& (color->b >= 0 && color->b <= 255))
	{
		*ok = 1;
		return (color);
	}
	element->error++;
	return (NULL);
}

void	ft_check_if_you_can_add_color(char *str, int *i, int *nb, int *coma)
{
	if (ft_isdigit(str[*i]))
	{
		*nb += 1;
		while (ft_isdigit(str[*i]))
			*i += 1;
	}
	if (str[*i] == ',')
		*coma += 1;
	*i += 1;
}

void	*ft_add_color(char *str, t_values *color, t_element *el, int *ok)
{
	int	i;
	int	j;
	int	coma;
	int	nb;

	i = 0;
	coma = 0;
	nb = 0;
	if (*ok)
	{
		el->error++;
		return (color);
	}
	while (ft_isspace_mod(str[i]))
		i++;
	j = i;
	while ((str[i] != '\n') && (ft_isdigit(str[i]) || str[i] == ','
			|| ft_isspace_mod(str[i])))
		ft_check_if_you_can_add_color(str, &i, &nb, &coma);
	if (nb == 3 && coma == 2 && (str[i] == '\n' || str[i] == '\0'))
		return (ft_check_cl(&str[j], el, color, ok));
	el->error++;
	return (NULL);
}
