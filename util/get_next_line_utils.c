/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:31:33 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/06 12:19:54 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


char	*ft_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
char	*ft_read(char *str, int fd)
{
	char	*buff;
	int		s1;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	s1 = 1;
	while (!ft_strchr(str, '\n') && s1 != 0)
	{
		s1 = read(fd, buff, BUFFER_SIZE);
		if (s1 == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[s1] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}
