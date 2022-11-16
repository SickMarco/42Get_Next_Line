/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:21:15 by mbozzi            #+#    #+#             */
/*   Updated: 2022/11/15 16:27:07 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_newline(char *buff)
{
	char	*tmp;
	int		len;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	len = ft_strlen(buff) - i + 1;
	tmp = ft_calloc(sizeof(char), len);
	if (!tmp)
		return (NULL);
	while (buff[i])
	{
		tmp[x] = buff[i];
		x++;
		i++;
	}
	free (buff);
	return (tmp);
}
char	*ft_exline(char *buff)
{
	char	*tmp;
	int		i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	tmp = ft_calloc(sizeof(char), i + 1);
	if(!tmp)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i - 1] != '\n')
	{
		tmp[i] = buff[i];
		i++;
	}
	return (tmp);
}

char	*ft_read(int fd, char *buff)
{
	char	*tmp;
	int		flag;

	flag = 1;
	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(buff, '\n') && flag != 0)
	{
		flag = read(fd, tmp, BUFFER_SIZE);
		if (flag == -1)
		{
			free(tmp);
			return (NULL);
		}
		buff = ft_strjoin(buff, tmp);
	}
	free(tmp);
	return (buff);
}


char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buff = malloc(BUFFER_SIZE);
	buff = ft_read(fd, buff);
	line = ft_exline(buff);
	buff = ft_newline(buff);
	return (line);
}