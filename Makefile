# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 18:35:35 by mekherbo          #+#    #+#              #
#    Updated: 2024/03/20 10:33:42 by mekherbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
NAME_BONUS = minishell_bonus

SRCS = main.c \
ft_env.c

OBJS := ${SRCS:.c=.o}

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
PURPLE= \033[38;2;255;105;180m
RESET= \033[0m

CC = clang

RM = rm -f

INC_DIR = includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror -g3

.c.o:
	@${CC} ${CFLAGS} -c -I ${INC_DIR} $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

all:	$(NAME)
	@echo "$(GREEN)minishell compiled!$(DEF_COLOR)"

${LIBFT}:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): ${OBJS} ${LIBFT}
		${CC} $(CFLAGS) ${OBJS} ${LIBFT} -o $(NAME) -lreadline

$(NAME_BONUS): ${OBJS} ${LIBFT}
	${CC} $(CFLAGS) ${OBJS} ${LIBFT} -o $(NAME_BONUS)

bonus: $(NAME_BONUS)
		@echo "$(GREEN)minishell_bonus compiled!$(DEF_COLOR)"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@${RM} ${OBJS}
	@echo "$(BLUE)minshell object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@${RM} $(NAME) $(NAME_BONUS) 
	@echo "$(CYAN) ${NAME}mishell executable have been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for minishell!$(DEF_COLOR)"

.PHONY: all clean fclean re libft bonus 
