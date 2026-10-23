/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:40:57 by alexgonz          #+#    #+#             */
/*   Updated: 2026/10/23 12:20:41 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append(char *buffer, char *append)
{
	char	*temp;

	temp = ft_strjoin(buffer, append);
	free(append);
	if (!temp)
		return (NULL);
	//printf("AFTER JOIN %s \n", temp);
	return (temp);
}

char	*correct(char *buffer)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;	
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i++;
	while (buffer[i])
		temp[j++] = buffer[i++]; 
	free(buffer);
	return (temp);
}

static char	*get_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = buffer[i];
	//printf("LINE: %s \n", line);
	return (line);
}

char	*read_file(char *result, int fd)
{
	char	*buffer;
	int		numbytes;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	numbytes = 1;
	while (numbytes > 0)
	{
		numbytes = read(fd, buffer, BUFFER_SIZE);
		//printf("READ %s \n NUMBYTES %d \n", buffer, numbytes);
		if (numbytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (numbytes > 0)
				result = append(buffer, result);
		if (ft_strchr(buffer, '\n') == 1 || (read(fd, 0, 0) <= 0 && BUFFER_SIZE != 1))
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || fd > 999 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(buffer, fd);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = correct(buffer);
	return (line);
}
