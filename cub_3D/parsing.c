/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:23:48 by daleliev          #+#    #+#             */
/*   Updated: 2024/06/29 10:37:22 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_checkpathanddupit(char *str, int size, t_element *el, int *fd)
{
	char	*path;
	char	*line;

	path = dup_with_a_size(str, size);
	if (*fd > 0)
		close(*fd);
	*fd = open(path, O_RDONLY);
	if (*fd < 0)
	{
		el->error++;
		free(path);
		return (NULL);
	}
	line = get_next_line(*fd);
	if (line && !ft_strncmp(line, "/* XPM */", 9))
	{
		free(line);
		return (path);
	}
	el->error++;
	if (line)
		free(line);
	free(path);
	return (NULL);
}

static void	*ft_add_t(char *str, char *path, t_element *element, int *fd)
{
	int	i;
	int	j;

	i = 0;
	if (str[i - 1] == 'D')
		element->bonus++;
	if (path)
	{
		element->error++;
		return (path);
	}
	while (ft_isspace_mod(str[i]))
		i++;
	j = i;
	while (str[j] != '\0' && str[j] != '\n' && !ft_isspace_mod(str[i]))
		j++;
	if (j - 4 < i && str[j - 4] != '.' && str[j - 3] != 'x'
		&& str[j - 2] != 'p' && str[j - 1] != 'm')
	{
		element->error++;
		return (path);
	}
	return (ft_checkpathanddupit(&str[i], j - i, element, fd));
}

static void	ft_check_line_for_element(char *str, t_element *el)
{
	int	i;

	i = 0;
	while (ft_isspace_mod(str[i]))
		i++;
	if (str[i] != '\0' || str[i] != '\n')
	{
		if (str[i] == 'C' && !el->is_ceiling)
			ft_add_color(&str[i + 1], el->ceiling, el, &el->is_ceiling);
		else if (str[i] == 'F' && !el->is_floor)
			ft_add_color(&str[i + 1], el->floor, el, &el->is_floor);
		else if (str[i] == 'W' && str[i + 1] == 'E' && !el->we_path)
			el->we_path = ft_add_t(&str[i + 2], el->we_path, el, &el->fd_we);
		else if (str[i] == 'E' && str[i + 1] == 'A' && !el->ea_path)
			el->ea_path = ft_add_t(&str[i + 2], el->ea_path, el, &el->fd_ea);
		else if (str[i] == 'S' && str[i + 1] == 'O' && !el->so_path)
			el->so_path = ft_add_t(&str[i + 2], el->so_path, el, &el->fd_so);
		else if (str[i] == 'N' && str[i + 1] == 'O' && !el->no_path)
			el->no_path = ft_add_t(&str[i + 2], el->no_path, el, &el->fd_no);
		else if (str[i] == 'D' && !el->d_path)
			el->d_path = ft_add_t(&str[i + 1], el->d_path, el, &el->fd_d);
		else
			el->error++;
		return ;
	}
}

int	ft_check_doc(int fd, char *line, t_element *el)
{
	while (line)
	{
		if (line_has_smthg(line) && (el->no_path == NULL || el->so_path == NULL
				|| el->we_path == NULL || el->ea_path == NULL
				|| el->is_floor == 0 || el->is_ceiling == 0))
			ft_check_line_for_element(line, el);
		free(line);
		line = get_next_line(fd);
		if (line && line_has_smthg(line) && el->no_path && el->so_path
			&& el->we_path && el->ea_path && el->is_floor && el->is_ceiling)
			break ;
	}
	el->lst = ft_calloc(sizeof(t_listb), 1);
	line = ft_start_lst(line, el, fd);
	while (line)
	{
		if (line_has_smthg(line))
			ft_map_to_lst(line, el);
		else
			el->error++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (el->error);
}

int	ft_parsing(char *doc, t_element *element)
{
	char	*line;
	int		fd;

	fd = open(doc, O_RDONLY);
	if (!ft_is_cub(doc) || fd < 0)
	{
		if (fd < 0)
			printf("Error\nArgument 1 can't be open.\n");
		return (1);
	}
	element->floor = ft_calloc(sizeof(t_values), 1);
	element->ceiling = ft_calloc(sizeof(t_values), 1);
	line = get_next_line(fd);
	ft_check_doc(fd, line, element);
	if (element->error)
		printf_error();
	return (element->error);
}
