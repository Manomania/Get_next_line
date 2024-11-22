/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:29:01 by maximart          #+#    #+#             */
/*   Updated: 2024/11/20 16:30:31 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (!bloc[i] || !bloc[i + 1])
		return (free(bloc), NULL);
	i++;
	new = malloc(ft_strlen(bloc) - i + 1);
	if (!new)
		return (free(bloc), NULL);
	j = 0;
	while (bloc[i])
		new[j++] = bloc[i++];
	new[j] = '\0';
	free(bloc);
	return (new);
}

static char	*read_storage(int fd, char *temp)
{
	char	*buffer;
	char	*old_temp;
	ssize_t	b_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(temp), NULL);
	b_read = read(fd, buffer, BUFFER_SIZE);
	while (b_read > 0)
	{
		buffer[b_read] = '\0';
		old_temp = temp;
		temp = ft_strjoin(temp, buffer);
		free(old_temp);
		if (ft_strchr(temp, '\n'))
			break ;
		b_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (b_read < 0)
		return (free(temp), NULL);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = read_storage(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	line = extract_line(temp[fd]);
	if (!line)
	{
		free(temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	temp[fd] = update_line(temp[fd]);
	return (line);
}
