/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:39:06 by mbozzi            #+#    #+#             */
/*   Updated: 2022/11/15 16:24:38 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define  BUFFER_SIZE 42
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *str, int c);

#endif