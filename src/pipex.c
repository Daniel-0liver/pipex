/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:22:44 by dateixei          #+#    #+#             */
/*   Updated: 2022/08/14 23:23:56 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main()
{
	int array[] = {1, 2, 3, 4, 1, 2};
	int arrSize = sizeof(array) / sizeof(int);
	int start, end;
	int fd[2];
	if (pipe(fd) == -1)
		return (1);

	int id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		start = 0;
		end = start + arrSize / 2;
	} else 
	{
		start = arrSize / 2;
		end = arrSize;
	}

	int sum = 0;
	int i;
	for (i = start; i < end; i++)
		sum += array[i];

	wait(NULL);
	printf("Calculated partial sum: %d\n", sum);
	
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);	 
	} 
		else 
	{
		int sumFromChild;
		close(fd[1]);
		read(fd[0], &sumFromChild, sizeof(sumFromChild));
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf("Total sum is %d\n", totalSum);
	}
	
	return (0);
}

// I need help to continue this project 