/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:21:15 by mbozzi            #+#    #+#             */
/*   Updated: 2022/11/17 12:37:26 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_exline(char *buff)
{
	int		i;
	int		x;
	int 	len;
	char	*ex;


	i = 0;
	x = 0;
	while (buff[i] && buff[i - 1] != '\n')
		i++;
	len = ft_strlen(buff) - i + 1;
	ex = ft_calloc(sizeof(char), len);
	if(!ex)
		return (NULL);
	while(buff[i])
	{
		ex[x] = buff[i];
		x++;
		i++;
	}
	free(buff);
	return(ex);
}

char	*ft_newline(char *buff)
{
	char	*tmp;
	int		i;

	i = 0;

	while(buff[i] && buff[i - 1] != '\n')
		i++;
	tmp = ft_calloc(sizeof(char), i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	free(tmp);
	while (buff[i] && buff [i - 1] != '\n')
	{
		tmp[i] = buff[i];
		i++;
	}
	return (tmp);
}

char	*ft_read(int fd)
{
	char	*tmp;
	int		flag;

	tmp = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	flag = read(fd, tmp, BUFFER_SIZE);
	if (flag < 0)
	{
		free (tmp);
		return (NULL);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buff = ft_read(fd);
	line = ft_newline(buff);
	buff = ft_exline(buff);
	return (line);
}