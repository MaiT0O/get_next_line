/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_netx_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:39:05 by ebansse           #+#    #+#             */
/*   Updated: 2024/11/20 17:18:52 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*to_return;
	size_t	bytes;

	bytes = nmemb * size;
	if (size != 0 && nmemb > (-1 / size))
		return (NULL);
	to_return = (void *)malloc(bytes);
	if (to_return == NULL)
		return (NULL);
	ft_bzero(to_return, bytes);
	return (to_return);
}

char	*ft_strchr(const char *string, int searchedChar)
{
	char	*str;

	str = (char *)string;
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		total_size;
	char	*result;
	int		i;
	int		j;

	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (total_size + 1));
	if (!result || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = 0;
	return (result);
}
