/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:01:40 by mlaporte          #+#    #+#             */
/*   Updated: 2023/05/22 10:25:36 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*str;
	unsigned char	chr;

	chr = c;
	if (chr == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	str = 0;
	while (*s)
	{
		if (*s == chr)
			str = s;
		s++;
	}
	return ((char *)str);
}
