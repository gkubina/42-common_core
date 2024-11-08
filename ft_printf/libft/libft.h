/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:22:08 by gkubina           #+#    #+#             */
/*   Updated: 2023/10/30 10:55:04 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

// *** Define a struct for a linked list node.
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
// Pointer to data content of the node.
// Pointer to the next node in the list.

// *** Part 1 - Libc functions

// ** Character classification functions:

int		ft_isalpha(int c);
// Args: c - the character to check.
// Returns: 1 if 'c' is alphabetic, 0 otherwise.

int		ft_isdigit(int c);
// Args: c - the character to check.
// Returns: 1 if 'c' is a digit, 0 otherwise.

int		ft_isalnum(int c);
// Args: c - the character to check.
// Returns: 1 if 'c' is alphanumeric, 0 otherwise.

int		ft_isascii(int c);
// Args: c - the character to check.
// Returns: 1 if 'c' is valid ASCII, 0 otherwise.

int		ft_isprint(int c);
// Args: c - the character to check.
// Returns: 1 if 'c' is printable, 0 otherwise.

int		ft_toupper(int c);
// Args: c - the character to convert to uppercase.
// Returns: Uppercase 'c' or 'c' unchanged if not lowercase.

int		ft_tolower(int c);
// Args: c - the character to convert to lowercase.
// Returns: Lowercase 'c' or 'c' unchanged if not uppercase.

// ** String and memory manipulation functions:

size_t	ft_strlen(const char *s);
// Args: s - the string to calculate length of.
// Returns: The length of the string 's'.

void	*ft_memset(void *s, int c, size_t n);
// Args: s - pointer to memory area to fill.
//       c - the byte to fill memory with.
//       n - number of bytes to fill.
// Returns: Pointer to the memory area 's'.

void	ft_bzero(void *s, size_t n);
// Args: s - pointer to memory area to set to zero.
//       n - number of bytes to set to zero.
// Returns: None (void).

void	*ft_memcpy(void *dest, const void *src, size_t n);
// Args: dest - pointer to destination memory area.
//       src - pointer to source memory area.
//       n - number of bytes to copy.
// Returns: Pointer to the destination memory area 'dest'.

void	*ft_memmove(void *dest, const void *src, size_t n);
// Args: dest - pointer to destination memory area.
//       src - pointer to source memory area.
//       n - number of bytes to copy.
// Returns: Pointer to the destination memory area 'dest'.

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// Args: dst - pointer to destination buffer.
//       src - source string.
//       size - size of the destination buffer.
// Returns: Length of 'src'.

size_t	ft_strlcat(char *dst, const char *src, size_t size);
// Args: dst - pointer to destination buffer.
//       src - source string.
//       size - size of the destination buffer.
// Returns: Total length of the string.

char	*ft_strchr(const char *s, int c);
// Args: s - string to search in.
//       c - the character to locate.
// Returns: Pointer to the first occurrence of 'c' in 's' or NULL if not found.

char	*ft_strrchr(const char *s, int c);
// Args: s - string to search in.
//       c - the character to locate.
// Returns: Pointer to the last occurrence of 'c' in 's' or NULL if not found.

int		ft_strncmp(const char *s1, const char *s2, size_t n);
// Args: s1 - first string to compare.
//       s2 - second string to compare.
//       n - max number of characters to compare.
// Returns: 0 if equal, >0 if s1 > s2, <0 if s2 > s1.

void	*ft_memchr(const void *s, int c, size_t n);
// Args: s - memory area to search in.
//       c - the character to locate.
//       n - number of bytes to search.
// Returns: Pointer to first occurrence of 'c' in 's' or NULL if not found.

int		ft_memcmp(const void *s1, const void *s2, size_t n);
// Args: s1 - first memory area to compare.
//       s2 - second memory area to compare.
//       n - number of bytes to compare.
// Returns: 0 if equal, >0 if s1 > s2, <0 if s2 > s1.

char	*ft_strnstr(const char *big, const char *little, size_t len);
// Args: big - string to search in.
//       little - substring to find.
//       len - max number of characters to search.
// Returns: Pointer to first occurrence of 'little' in 'big' or
// NULL if not found.

int		ft_atoi(const char *nptr);
// Args: nptr - string to convert to an integer.
// Returns: The converted integer value.

char	*ft_strdup(const char *s);
// Args: s - string to duplicate.
// Returns: Dynamically allocated duplicate of 's'.

// * 2 functions using malloc as well

void	*ft_calloc(size_t nmemb, size_t size);
// Args: nmemb - number of elements.
//       size - size of each element.
// Returns: Pointer to allocated memory, initialized to zero.

char	*ft_substr(char const *s, unsigned int start, size_t len);
// Args: s - string to extract from.
//       start - starting index of the substring.
//       len - max length of the substring.
// Returns: Dynamically allocated substring.

// *** Part 2 - Additional functions

// ** String manipulation functions (extended):

char	*ft_strjoin(char const *s1, char const *s2);
// Args: s1 - first string.
//       s2 - second string.
// Returns: Dynamically allocated concatenation of 's1' and 's2'.

char	*ft_strtrim(char const *s1, char const *set);
// Args: s1 - string to trim.
//       set - set of characters to trim from 's1'.
// Returns: Dynamically allocated trimmed string.

char	**ft_split(char const *s, char c);
// Args: s - string to split.
//       c - character to split the string by.
// Returns: NULL-terminated array of substrings.

char	*ft_itoa(int n);
// Args: n - integer to convert to a string.
// Returns: Dynamically allocated string representing 'n'.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Args: s - string to apply 'f' to.
//       f - mapping function.
// Returns: Dynamically allocated string with 'f' applied to each character.

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// Args: s - string to apply 'f' to.
//       f - function to apply to each character in 's'.
// Returns: None (void).

// ** Output functions

void	ft_putchar_fd(char c, int fd);
// Args: c - character to output.
//       fd - file descriptor to write to.
// Returns: None (void).

void	ft_putstr_fd(char *s, int fd);
// Args: s - string to output.
//       fd - file descriptor to write to.
// Returns: None (void).

void	ft_putendl_fd(char *s, int fd);
// Args: s - string to output.
//       fd - file descriptor to write to.
// Returns: None (void).

void	ft_putnbr_fd(int n, int fd);
// Args: n - integer to output.
//       fd - file descriptor to write to.
// Returns: None (void).

// *** Bonus part

// ** List manipulations

t_list	*ft_lstnew(void *content);
// Args: content - data content of the new node.
// Returns: Pointer to a new list node.

void	ft_lstadd_front(t_list **lst, t_list *new);
// Args: lst - pointer to the address of the list.
//       new - node to add to the front.
// Returns: None (void).

int		ft_lstsize(t_list *lst);
// Args: lst - list to calculate the size of.
// Returns: Number of elements in the list.

t_list	*ft_lstlast(t_list *lst);
// Args: lst - list to find the last node of.
// Returns: Pointer to the last node in the list.

void	ft_lstadd_back(t_list **lst, t_list *new);
// Args: lst - pointer to the address of the list.
//       new - node to add to the end.
// Returns: None (void).

void	ft_lstdelone(t_list *lst, void (*del)(void*));
// Args: lst - node to delete.
//       del - function to delete the content of the node.
// Returns: None (void).

void	ft_lstclear(t_list **lst, void (*del)(void*));
// Args: lst - pointer to the address of the list.
//       del - function to delete the content of the nodes.
// Returns: None (void).

void	ft_lstiter(t_list *lst, void (*f)(void *));
// Args: lst - list to apply 'f' to.
//       f - function to apply to each node in the list.
// Returns: None (void).

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// Args: lst - list to map.
//       f - mapping function to apply to each node's content.
//       del - function to delete the content of the nodes.
// Returns: New list created by applying 'f' to the nodes in 'lst'.

#endif
