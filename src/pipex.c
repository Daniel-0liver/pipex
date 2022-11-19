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
    int id = fork();
    if (id != 0)
    {
    	int id2 = fork();
		if (id2 != 0)
        	fork();
    }
    
    printf("Hello world\n");
	
    return(0);
}
