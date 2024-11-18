/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:22:23 by maximart          #+#    #+#             */
/*   Updated: 2024/11/18 15:11:28 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char	*bloc)
{
	size_t	i;
	char	*line;

	if (!bloc || !*bloc)
		return (NULL);
	i = 0;
	while (bloc[i] && bloc[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + (bloc[i] == '\n') + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (bloc[i] && bloc[i] != '\n')
	{
		line[i] = bloc[i];
		i++;
	}
	if (bloc[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_line(char	*bloc)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!bloc || !*bloc)
		return (NULL);
	i = 0;
	while (bloc[i] && bloc[i] != '\n')
		i++;
	if (!bloc[i])
	{
		free(bloc);
		return (NULL);
	}
	new = malloc(ft_strlen(bloc) - i + 1);
	if (!new)
	{
		free(bloc);
		return (NULL);
	}
	i++;
	j = 0;
	while (bloc[i])
		new[j++] = bloc[i++];
	new[j] = '\0';
	free(bloc);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	b_read;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	b_read = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(temp, '\n') && (b_read > 0))
	{
		buffer[b_read] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (!temp)
			return (NULL);
	}
	if (b_read == -1)
	{
		free(temp);
		return (NULL);
	}
	line = extract_line(temp);
	temp = update_line(temp);
	return (line);
}