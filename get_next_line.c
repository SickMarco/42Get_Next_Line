/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:21:15 by mbozzi            #+#    #+#             */
/*   Updated: 2022/11/20 18:00:46 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_exline(char *buff)
{
	int		i;
	int		x;
	int		len;
	char	*ex;

	i = 0;
	x = 0;
	while (buff[i] && buff[i - 1] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	len = ft_strlen(buff) - i + 1;
	ex = ft_calloc(sizeof(char), len);
	if (!ex)
		return (NULL);
	while (buff[i])
		ex[x++] = buff[i++];
	free(buff);
	return (ex);
}

char	*ft_newline(char *buff)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i - 1] != '\n')
		i++;
	tmp = ft_calloc(sizeof(char), i + 1);
	i = 0;
	while (buff[i] && buff [i - 1] != '\n')
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

	if (!buff)
		buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	flag = 1;
	while (flag > 0)
	{
		flag = read(fd, tmp, BUFFER_SIZE);
		if (flag == -1)
		{
			free (tmp);
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

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buff = ft_read(fd, buff);
	line = ft_newline(buff);
	buff = ft_exline(buff);
	return (line);
}
