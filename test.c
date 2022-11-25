#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

int ft_strlen_line (char *s, char c, int i)
{
    int n;

    n = 0;
    while (s[i] != c)
    {
        n++;
        i++;
    }
    return (n);
}

int ft_strlen_colum (char *s, char c)
{
    int i;
    int b;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            b++;
        }
        
        i++;
    }
    return(b);
}

char **ft_split(char *s, char c)
{
    char    **p;
    int x;
    int i;

    x = 0;
    i = 0;
    p = malloc(ft_strlen_colum(s, c) * sizeof(char));
    while (i <= strlen(s))
    {
        if (s[i] == c && x == 0)
        {
            p[x] = ft_substr(s, 0, ft_strlen_line(s , c, 0));
            x++;
        }
        if (s[i] == c)
        {
            p[x] = ft_substr(s, i+1, ft_strlen_line(s, c, i+1));
            x++;
        }      
        i++;
    }
    if (!p)
    {
        return(0);
    }
    return(p);
}

int		main(void)
{
	int i;
	char **tab;
		
	tab = ft_split("brasil vai golear a suiça",' ');
    i = 0;
    while (i < 5)
	{
		printf("string %d : %s\n", i, tab[i]);
		i++;
	}
	return (0);
}