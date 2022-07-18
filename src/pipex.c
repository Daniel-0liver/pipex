/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:22:44 by dateixei          #+#    #+#             */
/*   Updated: 2022/07/18 01:21:49 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv)
{
	int id;
	// int n;
	// int i;
	
	(void) argc;
	(void) argv;
	id = 0;
	id = fork();
	if (id == 0)
		sleep(1);
	printf("ID :%d, %d\n", getpid(), id);
	int n = wait(NULL);
	if (n == -1)
		puts("Execution finished");
	else
		printf("Child finished, %d", n);
	return (0);
}
