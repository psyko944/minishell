/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:13:33 by mekherbo          #+#    #+#             */
/*   Updated: 2024/03/21 13:10:31 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <string.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft/libft.h"

enum	e_link_types {
	PIPE,
	NONE,
	IN_REDIRECT,
	OUT_REDIRECT,
	HEREDOC,
	APPEND,
	AND_OPERATOR,
	OR_OPERATOR
};

typedef struct s_command_symbol
{
	char					*content;
	enum e_link_types			link_prev;
	enum e_link_types			link_next;
	struct s_command_symbol	*next;
	struct s_command_symbol	*prev;
}	t_command_symbol;

typedef struct	s_data
{
	char	**envp;
	char	*cmd;
	int		exit_status;
	char	*pathname;
}	t_data;

typedef struct s_env
{
	char	*line;
	struct s_env   *prev;
	struct s_env   *next;
}	t_env;

typedef struct  s_data
{
	char *path;
}	t_data;


t_env	*get_env(char **envp);

#endif 
