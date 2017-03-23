# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkalia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 14:12:11 by jkalia            #+#    #+#              #
#*   Updated: 2017/03/23 14:36:22 by jkalia           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME			:= libftprintf.a

CFLAGS			+= -Wall -Wextra -Werror
CFLAGS			+= -I includes/
TEST			:= test.c

SRC_FILES		:= read.c \

LIB_FILES		:=

SRC				:= $(addprefix src/, $(SRC_FILES))
LIB				:= $(addprefix lib/, $(LIB_FILES))

OBJ 			:= $(SRC:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@
	@echo "\033[32mCompiled Project Object Files\033[0m"

$(OBJLIB): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@
	@echo "\033[32mCompiled Library Object Files\033[0m"

$(NAME): $(OBJLIB) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(OBJLIB)
	@echo "\033[32mCreated Library\033[0m"

clean:
	@rm -rf $(OBJ) $(OBJLIB)
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)

re: fclean all
