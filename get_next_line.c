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

static char	*extract_line(char	*bloc)
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

static char	*update_line(char	*bloc)
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

static char *read_storage(int fd, char *temp)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	b_read;

	b_read = read(fd, buffer, BUFFER_SIZE);
	while (b_read > 0)
	{
		buffer[b_read] = '\0';
		if (!temp)
			temp = ft_strdup("");
		temp = ft_strjoin(temp, buffer);
		if (!temp)
		{
			free(temp);
			return (NULL);
		}
		if (ft_strchr(temp, '\n'))
			break ;
		b_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_storage(fd, temp);
	if (!temp || !*temp)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	line = extract_line(temp);
	temp = update_line(temp);
	return (line);
}