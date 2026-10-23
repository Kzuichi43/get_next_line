/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:16:30 by alexgonz          #+#    #+#             */
/*   Updated: 2026/10/23 11:49:27 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

char	*correct(char *buffer);
char	*read_file(char *result, int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		ft_strchr(char *str, char c);
char	*ft_calloc(size_t n, size_t siz);
char	*ft_strjoin(char *end, char *init);
char	*append(char *buffer, char *append);
void	ft_bzero(void *str, size_t n);

#endif
