/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:45:54 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/03 17:10:56 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must be
// ended by a NULL pointer.

static char	**ft_malloc_error(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	ft_isspace(char ch, char c)
{
	if (ch == c)
		return (1);
	return (0);
}

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && ft_isspace(*s, c) == 1)
			s++;
		if (*s && ft_isspace(*s, c) == 0)
		{
			count++;
			while (*s && ft_isspace(*s, c) == 0)
				s++;
		}
	}
	return (count);
}

static char	*malloc_word(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && ft_isspace(s[i], c) == 0)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == (char *)(void *)0)
		return (NULL);
	i = 0;
	while (s[i] && ft_isspace(s[i], c) == 0)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	i = 0;
	if (!s)
		return (0);
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (arr == (char **)(void **)0)
		return (NULL);
	while (*s)
	{
		while (*s && ft_isspace(*s, c) == 1)
			s++;
		if (*s && ft_isspace(*s, c) == 0)
		{
			arr[i] = malloc_word(s, c);
			if (arr[i] == NULL)
				return (ft_malloc_error(arr));
			i++;
			while (*s && ft_isspace(*s, c) == 0)
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
