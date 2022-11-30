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
	int dupfile;
	int pipes[2];
	char path[] = "/usr/bin/ls";
	char *argVec[] = {"ls", "-la", NULL};
	char *envVec[] = {NULL};

	pipe(pipes);
	
	int fd = open("file2", O_WRONLY | O_CREAT, 0777);
	dupfile = dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("Before the execve");
	execve(path, argVec, envVec);

	printf("Test");

	return 0;
}
