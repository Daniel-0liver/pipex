/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 00:22:44 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/03 18:27:43 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// will read from end[0], will start cmd 2
void    child_one(t_data *data, char **argv, char **envp)
{
    data->fdout = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (data->fdout == -1)
        return (perror("Open of File 2 failed"));
    close(data->end[1]);
    if (dup2(data->end[0], STDIN_FILENO) < 0)
        return (perror("dup2 failed"));
    close(data->end[0]);
    if (dup2(data->fdout, STDOUT_FILENO) < 0)
        return (perror("dup2 failed"));
    close(data->fdout);
    if (!data->flag2)
        execve(data->cmd_path2, data->cmd2, envp);
    exit(EXIT_FAILURE);
}
// will write to end[1], will start cmd 1
void    child_two(t_data *data, char **argv, char **envp)
{
    close(data->end[0]);
    if (dup2(data->end[1], STDOUT_FILENO) < 0)
        return (perror("dup2 failed"));
    close(data->end[1]);
    data->fdin = open(argv[1], O_RDONLY);
    if (data->fdin == -1)
        return (perror("Open of File 1 failed"));
    if (dup2(data->fdin, STDIN_FILENO) < 0)
        return (perror("dup2 failed"));
    close(data->fdin);
    if (!data->flag1)
        execve(data->cmd_path1, data->cmd1, envp);
    exit(EXIT_FAILURE);
}
