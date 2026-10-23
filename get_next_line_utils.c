/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:06:24 by alexgonz          #+#    #+#             */
/*   Updated: 2026/10/23 11:41:48 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strchr(char *str, char c)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_calloc(size_t n, size_t siz)
{
	size_t	len;
	char	*res;

	res = NULL;
	len = n * siz;
	if (n == 0 || len / n != siz)
		return (NULL);
	res = malloc(len);
	if (!res)
		return (NULL);
	ft_bzero(res, len);
	return (res);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*res;

	res = (char *)str;
	i = 0;
	while (i < n)
		res[i++] = '\0';
}

char	*ft_strjoin(char *end, char *init)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!end || !init)
		return (NULL);
	res = NULL;
	res = ft_calloc((ft_strlen(end) + ft_strlen(init) + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (init[i] != '\0')
	{
		res[i] = init[i];
		i++;
	}
	while (end[j] != '\0')
	{
		res[i + j] = end[j];
		j++;
	}
	res[i + j] = 0;
	return (res);
}
