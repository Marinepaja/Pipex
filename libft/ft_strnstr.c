/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:58:38 by mlaporte          #+#    #+#             */
/*   Updated: 2023/05/22 13:20:39 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lenlittle;

	lenlittle = ft_strlen(little);
	if (lenlittle == 0)
		return ((char *)big);
	else if (len == 0)
		return (NULL);
	while (*big && (lenlittle <= len--))
	{
		if (*big == *little
			&& ft_memcmp(big, little, lenlittle) == 0)
			return ((char *) big);
		big++;
	}
	return (NULL);
}
