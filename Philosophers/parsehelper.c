/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsehelper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:47:40 by gkubina           #+#    #+#             */
/*   Updated: 2024/03/04 17:27:19 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c)
{
	if ((c > 47 && c < 58))
		return (1);
	return (0);
}

static int	ft_is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && ft_isdigit(s[i]) == 1)
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				negative;
	int				resultat;

	i = 0;
	negative = 1;
	resultat = 0;
	while (ft_is_space(nptr[i]) == 1 && nptr[i] != '\0')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative = negative * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		resultat = (resultat * 10) + (nptr[i] - '0');
		i++;
	}
	return (resultat * negative);
}
