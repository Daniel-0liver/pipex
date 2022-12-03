/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:40:03 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/03 17:11:15 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.
// this is a modified version, it will ad a '/' between the strings

char	*ft_strjoin(char const *s1, char const *s2, char divider)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	buffer = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (buffer == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i++] = divider;
	while (s2[j] != '\0')
	{
		buffer[i] = s2[j];
		i++;
		j++;
	}
	buffer[i] = '\0';
	return (buffer);
}
