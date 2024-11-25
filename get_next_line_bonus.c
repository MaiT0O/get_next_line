/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:50:45 by ebansse           #+#    #+#             */
/*   Updated: 2024/11/25 11:22:05 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*join_and_free(char *str1, char *str2)
{
	char	*temp;

	temp = ft_strjoin(str1, str2);
	free(str1);
	return (temp);
}

static char	*extract_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*extract_next_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	line = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	free(str);
	return (line);
}

static char	*read_line(int fd, char *content)
{
	char	*buffer;
	ssize_t	bytes_reads;

	if (!content)
		content = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_reads = 1;
	while (bytes_reads > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_reads = read(fd, buffer, BUFFER_SIZE);
		if (bytes_reads == -1)
		{
			free(buffer);
			free(content);
			return (NULL);
		}
		buffer[bytes_reads] = '\0';
		content = join_and_free(content, buffer);
	}
	free(buffer);
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = extract_next_line(buffer[fd]);
	return (line);
}

/*#include <stdio.h>

void main(void)
{
	int	fd;
	int fd2;
	int fd3;
	int	i;
	static char *str;
	static char *str2;
	static char *str3;

	fd = open("./test1.txt", O_RDONLY);
	fd2 = open("./test2.txt", O_RDONLY);
	fd3 = open("./test3.txt", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		str = get_next_line(fd);
		str2 = get_next_line(fd2);
		str3 = get_next_line(fd3);
		
		printf("%s%s%s", str, str2, str3);
		free(str);
		free(str2);
		free(str3);
		i++;
	}
}*/