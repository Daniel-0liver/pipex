/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:22:44 by dateixei          #+#    #+#             */
/*   Updated: 2022/09/20 16:23:05 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(void)
{
	int fd;
	int pipes[2];
	char path[] = "/usr/bin/ls";
	char *argVec[] = {"ls", "-la", NULL};
	char *envVec[] = {NULL};

	pipe(pipes);
	
	execve(path, argVec, envVec);
	fd = open("file2", O_WRONLY);
	dup2(fd, STDIN_FILENO);
	close(0);
	close(1);
	write(pipes[2], "1", 1);

	printf("Test");

	return 0;
}
