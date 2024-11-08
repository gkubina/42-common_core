/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:25:34 by daleliev          #+#    #+#             */
/*   Updated: 2024/05/17 13:24:48 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// modif ici dqns les @ foncts

void	*ft_read(char **nl, char *save, int fd)
{
	ssize_t		read_size;

	read_size = BUFFER_SIZE;
	while (!ft_search_n(save))
	{
		read_size = read(fd, save, BUFFER_SIZE);
		if (read_size == -1)
		{
			save[0] = '\0';
			free(*nl);
			return (NULL);
		}
		else if (read_size == 0 && ft_strleni(*nl) == 0)
			break ;
		else if (read_size == 0 && ft_strleni(*nl) > 0)
			continue ;
		save[read_size] = '\0';
		ft_add_save_to_nl(nl, save);
	}
	return (*nl);
}

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE] = {};
	char		*nl;

	nl = NULL;
	if (save[0] && ft_search_n(save))
	{
		ft_add_save_to_nl(&nl, save);
		fd_clean_nl(&nl);
		ft_clean_save(save);
		return (nl);
	}
	else if (save[0])
	{
		ft_add_save_to_nl(&nl, save);
		ft_clean_save(save);
	}
	if (!ft_read(&nl, save, fd) && (!nl || !*nl))
		return (NULL);
	fd_clean_nl(&nl);
	ft_clean_save(save);
	return (nl);
}

/*
int	main()
{
	int	fd;

	fd = open("file.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//		printf("%s", get_next_line(fd));

}*/
