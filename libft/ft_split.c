/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:27:00 by mlaporte          #+#    #+#             */
/*   Updated: 2024/01/18 11:06:13 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenwords(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			i += ft_lenwords((const char *)(s + i), c);
		}
		else
			i++;
	}
	return (nb);
}

void	*free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	return (NULL);
}

static char	**tab_init(int count)
{
	char		**tab;

	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	tab[count] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	int			count;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_countwords(s, c);
	tab = tab_init(count);
	if (!tab)
		return (NULL);
	while (i < count)
	{
		while (*s == c)
			s++;
		tab[i] = ft_substr(s, 0, ft_lenwords(s, c));
		if (!tab[i])
		{
			return (free_tab(tab));
		}
		s += ft_lenwords(s, c);
		i++;
	}
	return (tab);
}
