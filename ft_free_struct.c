/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:22:44 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/03 22:19:58 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Will free the given array and set it to NULL 
void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	while (str && str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

// Will free all allocated data of the data struct
void	ft_free_struct(t_data *data)
{
	ft_free_array(data->mypaths);
	ft_free_array(data->cmd1);
	ft_free_array(data->cmd2);
	free(data->cmd_path1);
	data->cmd_path1 = NULL;
	free(data->cmd_path2);
	data->cmd_path2 = NULL;
}
