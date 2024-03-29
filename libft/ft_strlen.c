/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 02:13:12 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/04 13:29:32 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// The strlen() function calculates the length of the string pointed to by s, 
// excluding the terminating null byte ('\0').

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	if(*(str) == (0))
		return (0);
	while (str[size])
		size++;
	return (size);
}

// int main(void) {
// 	char *str = {"abcde"};
// 	printf("%d\n", strlen(str));
// 	printf("%d\n", ft_strlen(str));
// 	return 0;
// }