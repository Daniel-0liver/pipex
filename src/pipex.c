/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:22:44 by dateixei          #+#    #+#             */
/*   Updated: 2022/07/13 00:46:29 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv)
{
	int id;
	int n;
	int i;
	
	(void) argc;
	(void) argv;
	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
	{
		wait(0);
	}
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		// fflush(stdout);
	}
	if (id != 0)
		puts("");
	return (0);
}

