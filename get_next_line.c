/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logname <logname@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:22:23 by logname           #+#    #+#             */
/*   Updated: 2024/11/17 11:24:50 by logname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*file;
	char	buffer[256];
	ssize_t	bytesread;

	file = open("test.txt", O_RDONLY);
	if (!file)
		return (1);
	while ((bytesread = read(file, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer(bytesread) = '\0';
		printf("%s", buffer);
	}
	if (bytesread > 0)
		return (1);
	close(file);
	return (0);
}