/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:42:44 by alegreci          #+#    #+#             */
/*   Updated: 2022/10/27 17:42:46 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjin(char *s1, char const *s2);
char	*ft_get_line(char *storage);
char	*ft_freejoin(char *buffer, char *storage);
char	*ft_reader(char *storage, int fd);
char	*get_next_line(int fd);
#endif
