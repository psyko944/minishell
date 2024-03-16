/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:00:55 by mekherbo          #+#    #+#             */
/*   Updated: 2024/03/15 20:31:06 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	is_quote(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input == '"')
			return (1);
	}
	return (0);
}

static void choice(char *input)
{
	enum e_link_types choice;	
	
	if (!ft_strncmp(input, "<", 1))
		choice = IN_REDIRECT;
	else if (!ft_strncmp(input, ">", 1))
		choice = OUT_REDIRECT;
	else if (!ft_strncmp(input, "<<", 2))
		choice = HEREDOC;
	else if (!ft_strncmp(input, ">>", 2))
		choice = APPEND;
	else if (!ft_strncmp(input, "|", 1))
		choice = PIPE;
	else if (!ft_strncmp(input, "&&", 2))
		choice = AND_OPERATOR;
	else if (!ft_strncmp(input, "||", 2))
		choice = OR_OPERATOR;
	else
		choice = NONE;
	printf("choice = %d\n", choice);
}

int main()
{
	char *input;
	char **tab;
	int		i;

	while (1)
	{
		i = -1;
		input = readline("$ ");
		if (!input)
		{
			printf("readline error no display prompt\n");
			break ;
		}
		
		if (strcmp(input, "clear") == 0)
		{
			printf("clear history\n");
			rl_clear_history();
		}
		else
		{
			add_history(input);
			printf("you entered : %s\n", input);
		}
		tab = ft_split(input, ' ');
		if (!tab)
		{
			free(input);
			break ;
		}
		while (tab[++i])
			choice(tab[i]);
		free(input);
	}
	return (0);
}
