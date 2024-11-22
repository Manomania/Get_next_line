/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:00:06 by maximart          #+#    #+#             */
/*   Updated: 2024/11/18 16:00:11 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

// int main(void)
// {
// 	int fd[2];
// 	char *line;
// 	fd[0] = open("test.txt", O_RDONLY);
// 	fd[1] = open("test2.txt", O_RDONLY);
// 	printf("====Contenu file====\n");
// 	while ((line = get_next_line(fd[0])) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	return (0);
// }

int	main(void)
{
	int fd;
	char *line;

	fd = open("giant_line.txt", O_RDONLY);
	printf("====Contenu file====\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		// usleep(1000000);
	}
	close(fd);
	return (0);
}
