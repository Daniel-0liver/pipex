/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:02:10 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/03 17:03:54 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// will search for the correct path of command 1, print error if not found
static void	ft_get_path_1(t_data *data)
{
	int		i;
	char	*temp;

	if (access(data->cmd1[0], F_OK) == 0)
	{
		data->cmd_path1 = ft_strdup(data->cmd1[0]);
		temp = ft_strrchr(data->cmd1[0], '/') + 1;
		data->cmd1[0] = ft_strdup(temp);
		return ;
	}
	i = 0;
	while (data->mypaths[i])
	{
		data->cmd_path1 = ft_strjoin(data->mypaths[i++], data->cmd1[0], '/');
		if (access(data->cmd_path1, F_OK) == 0)
		{
			return ;
		}
		free(data->cmd_path1);
		data->cmd_path1 = NULL;
	}
	write(STDERR_FILENO, "pipex: ", 7);
	write(STDERR_FILENO, data->cmd1[0], ft_strlen(data->cmd1[0]));
	write(STDERR_FILENO, ": command not found\n", 20);
	data->flag1 = 1;
}

// will search for the correct path of command 2, print error if not found
static void	ft_get_path_2(t_data *data)
{
	int		i;
	char	*temp;

	if (access(data->cmd2[0], F_OK) == 0)
	{
		data->cmd_path2 = ft_strdup(data->cmd2[0]);
		temp = ft_strrchr(data->cmd1[0], '/') + 1;
		data->cmd2[0] = ft_strdup(temp);
		return ;
	}
	i = 0;
	while (data->mypaths[i])
	{
		data->cmd_path2 = ft_strjoin(data->mypaths[i++], data->cmd2[0], '/');
		if (access(data->cmd_path2, F_OK) == 0)
		{
			return ;
		}
		free(data->cmd_path2);
		data->cmd_path2 = NULL;
	}
	write(STDERR_FILENO, "pipex: ", 7);
	write(STDERR_FILENO, data->cmd2[0], ft_strlen(data->cmd2[0]));
	write(STDERR_FILENO, ": command not found\n", 20);
	data->flag2 = 1;
}

// will find the correct path of the function
// print error if not found
void	ft_get_paths(t_data *data)
{
    ft_get_path_1(data);
    ft_get_path_2(data);
}
