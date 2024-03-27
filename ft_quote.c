#include "minishell.h"

char *parse_token(char *input)
{
    char *token_end;

    token_end = input;
    if (*input == '"')
    {
        token_end++;
        while (*token_end != '"')
            token_end++;
    }
    else
         while (*token_end != ' ' && *token_end != '\t' && *token_end != '\0')
            token_end++;
    return token_end;
}

// static int	is_quote(char *input)
// {
// 	int	i;

// 	i = 0;
// 	while (input[i])
// 	{
// 		if (input[i] == '"')
// 			return (1);
// 	}
// 	return (0);
// }

// static int how_many_quotes(char *input)
// {
//     int i = 0;

//     while (input[++i])
//     {
//         if (input[i] == '"')
//             return (1);
//     }
//     return (i);
// }

// static int  valid_double_quote(input, i)
// {
//     if (input[i] != '"')
//         return (0);
//     if (i > 0 && input[i - 1] == '\\')
//         return (0);
//     return (1);
// }

// static int  g_quote(char *input)
// {
//     int i = 0;
//     while (input[i])
//     {
//         if (input[i] == '"' && !valid_double_quote(input, i))
//             return (0);
//     }
// }