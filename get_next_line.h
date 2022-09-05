/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:59:52 by spatel            #+#    #+#             */
/*   Updated: 2022/08/21 14:59:52 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h> //null
# include <stdlib.h> //maloc
# include <unistd.h>

// SRC
char		*get_next_line(int fd);
static char	*find_newline(int fd, char *buffer, char *backup);
static char	*extract_newline(char *line);

//UTILS
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
