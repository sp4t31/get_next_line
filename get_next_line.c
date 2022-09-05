/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:59:14 by spatel            #+#    #+#             */
/*   Updated: 2022/08/21 14:59:14 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Write a function that returns one line read from 
	the text file pointed to by the file descriptor
	parameter
*/

#include "get_next_line.h"

char	*get_next_line(int fd);
{
	char		*line;
	char		*buffer;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		//fd < 0 ?
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = find_newline(fd, buffer, backup);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (line);
	backup = extract_newline(line);
	return (line);
}

static char	*find_newline(int fd, char *buffer, char *backup)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'));
			break;
	}
	return (backup);
}

static char	*extract_newline(char *line)
{
	char	*leftover;
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i] == '\0')
		return (NULL);
	leftover = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*leftover == '\0')
	{
		free(leftover);
		leftover = NULL;
	}
	line[i + 1] = '\0';
	return (leftover);
}


//Extra Notes

//Read function