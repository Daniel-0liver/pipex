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

int main(int arc, char* argv[])
{
    int pids[PROCESS_NUM];
    int pipes[PROCESS_NUM + 1][2];
    int i;

    for (i = 0; i < PROCESS_NUM + 1; i++)
    {
        if (pipe(pipes[i]) == -1)
            printf("Error with creating pipe\n");
    }
    
    for (i = 0; i < PROCESS_NUM; i++)
    {
        fork();
    }
    

    return 0;
}
