#include "minishell.h"

static int  valid_simple_quote(char *str)
{
    int i;

    i = 0;
    while (str[++i])
        if (str[i] == '\'')
            return (1);
    return (0);
}

static int  valid_double_quote(char *str)
{
    int i;

    i = 0;
    while (str[++i])
        if (str[i] == '"')
            return (1);
    return (0);
}

char **ft_custom split(char *str)
{
    int i;

    i = 0;
    while (str[i] &&(str[i] != ' ' || str[i] != '"' || str[i] != '\''))
      i++; 
    if (str[i] == ' ')
    {
        valid_simple_quote(&str[i])
    }
}