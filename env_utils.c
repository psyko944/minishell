#include "minishell.h"

char    *get_path(char **envp)
{
    int     i;
    char    *path;

    i = -1;
    while (envp[++i])
	{
		path = ft_strnstr(envp[i], "PATH=", 5);
		if (path)
		{
			path = path + 5;
			return (path);
		}
	}
    return (NULL);
}