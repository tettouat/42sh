#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelola <aelola@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 15:24:13 by aelola            #+#    #+#              #
#    Updated: 2014/06/06 16:19:08 by aelola           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: clean fclean re debug leaks

NAME = 42sh

FLAGS = -Wall -Wextra -Werror

SRC = ft_pipex.c \
	ft_promt.c \
	ft_setenv.c \
	ft_sh_command.c \
	ft_realloc.c \
	ft_strnclr.c \
	ft_redirect.c \
	ft_exec.c \
	ft_path.c \
	env.c \
	env2.c \
	builtin.c \
	ft_cd.c \
	ft_free_array.c \
	ft_strchr_str.c \
	ft_operator.c \
	ft_script.c \
	term.c \
	ft_history.c \
	ft_echo.c \
	ft_read.c \
	ft_press_button.c \
	ft_press_button2.c \
	ft_put_things.c \
	ft_init.c \
	ft_exit.c \
	ft_operator2.c \
	ft_init_chev.c

OBJ = $(SRC:.c=.o)

DEBFLAG = -g

LEAKFLAG = --analyze;

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32mBuilding 42sh...\033[0m"
	@make -C ./libft
	@gcc $(FLAGS) ft_minishell.c $(OBJ) ./libft/libft.a -ltermcap -o $(NAME)

	@echo "\033[0m"
	@echo "						   ___  _____       _     "
	@echo "						  /   |/ __  \     | |    "
	@echo "						 / /| |\| / /'  ___| |__  "
	@echo "						/ /_| |  / /   / __| '_ \ "
	@echo "						\___  |./ /___ \__ \ | | |"
	@echo "						    |_/\_____/ |___/_| |_|"

	@echo "\033[32m                					[GET READY BABY !!!!!]\033[0m"

%.o: %.c
	@gcc -o $@ -c $< $(FLAGS) -I ./libft/

clean:
	@echo "\033[33mCleaning 42sh and libft!\033[0m"
	@make -C ./libft/ clean
	@rm -f $(OBJ)

	@echo "				                              ____							"
	@echo "				                      __,-~~/~    \---.						"
	@echo "				                    _/_,---(      ,    )						"
	@echo "				                __ /        <    /   )  \__					"
	@echo "				 - ------===;;;'====------------------===;;;===----- -  -	"
	@echo "				                  \\/  ~\"~\"~\"~\"~\"~\\~\"~)~\"/\/			"
	@echo "				                   (_ (   \  (     >    \)					"
	@echo "				                    \_( _ <         >_>'						"
	@echo "				                       ~ \\-i' ::>|--\"						"
	@echo "				                           I;|.|.|							"
	@echo "				                          <|i::|i|\\.						"
	@echo "				                         (\\ ^'\"\\-' \")					"

	@echo "\033[32m                					[Everything is Clean]\033[0m"

fclean: clean
	@echo "\033[31mFclean 42sh and libft!\033[0m"
	@make -C ./libft/ fclean
	@rm -f $(NAME)

debug:	FLAG += $(DEBFLAG)
debug:	re

leaks:	FLAG += $(LEAKFLAG)
leaks:	re

re: fclean all

rew: all
	./$(NAME)
