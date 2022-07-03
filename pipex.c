/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:22:44 by dateixei          #+#    #+#             */
/*   Updated: 2022/07/04 00:32:33 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
    char *cmd_path;
    char *options[3] = {"ls", "-la", NULL};
    char *cmd = "ls";

    (void)argc;
    (void)argv;
    cmd_path = get_cmd_path(cmd, envp);
    // The get_cmd_path function is the one
    // that parses envp to find the correct path
    // for the ls command (ex. /usr/bin/ls)
    if (!cmd_path)
    {
        perror(cmd_path);
        return(-1);
    }
    execve(cmd_path, options, envp);
    printf("Victory!");
    free(cmd_path);
    return(0);
	
}

