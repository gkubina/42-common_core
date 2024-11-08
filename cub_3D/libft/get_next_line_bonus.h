/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:06:45 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/22 11:29:40 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd);

//helpers
char	*ft_strchr_gnl(const char *s, int c);
size_t	ft_strlen_gnl(const char *s);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size);
char	*ft_strjoin_free(char *s1, char const *s2);

#endif
