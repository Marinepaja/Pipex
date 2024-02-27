/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:50:50 by mlaporte          #+#    #+#             */
/*   Updated: 2023/12/18 22:48:44 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}*/

char	*get_res(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (i == (int)ft_strlen(str))
	{
		free(str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!res)
	{
		free(str);
		return (NULL);
	}
	ft_memcpy(res, str + i + 1, ft_strlen(str) - i);
	free(str);
	return (res);
}

char	*get_txt(int fd, char *res)
{
	char	*buf;
	int		char_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	char_read = 1;
	while (char_read != 0 && !ft_strchr(res, '\n'))
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[char_read] = 0;
		res = ft_strjoin(res, buf);
	}
	free(buf);
	return (res);
}

char	*get_line(char *res)
{
	char		*line;
	int			i;

	i = 0;
	while (res[i])
	{
		if (res[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, res, i);
	line[i] = 0;
	if (*line == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = get_txt(fd, res);
	if (!res)
		return (NULL);
	str = get_line(res);
	res = get_res(res);
	return (str);
}
