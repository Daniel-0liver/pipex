/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:02:10 by dateixei          #+#    #+#             */
/*   Updated: 2022/12/03 22:20:28 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>    //  write, dup2, close
# include <fcntl.h>     //  O_RDONLY, O_...
# include <stdlib.h>    //  EXIT_FAILURE, malloc, free
# include <stdio.h>     //  STDIN
# include <sys/types.h> //	wait
# include <sys/wait.h>	//	wait

# define STDERR 2
//# define SWAP(A, B) A ^= B ^= A ^= B;

typedef struct s_data
{
	int		end[2];
	int		fdin;
	int		fdout;
	char	**mypaths;
	char	**cmd1;
	char	**cmd2;
	int		flag1;
	int		flag2;
	char	*cmd_path1;
	char	*cmd_path2;
}				t_data;

//LIBFT Functions
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2, char divider);
size_t	ft_strlen(const char *s);

//PIPEX Functions
void	ft_get_paths(t_data *data);
void	child_one(t_data *data, char **argv, char **envp);
void	child_two(t_data *data, char **argv, char **envp);
void	ft_free_struct(t_data *data);

#endif