# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkalia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 14:12:11 by jkalia            #+#    #+#              #
#*   Updated: 2017/04/13 13:49:06 by jkalia           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME			:= libftprintf.a

CC				:= gcc
CFLAGS			+= -Wall -Wextra
CFLAGS			+= -Werror
CFLAGS			+= -I includes/

LIBFTPRINTF		:= -L. -lftprintf
	
SRC_FILES		:= ft_printf_1.c \
				ft_printf_2.c \
				dispatcher.c \
				handle.c \
				ft_flags.c \
				ft_array_1.c \
				ft_array_2.c \
				ft_printf_c.c \
				ft_printf_dp.c \
				ft_printf_nf.c \
				ft_printf_s.c \
				ft_printf_b.c \
				ft_printf_uox.c \

LIBFT_FILES		:= ft_putchar.c \
			  ft_putchar_fd.c \
			  ft_strcmp.c \
			  ft_putendl.c \
			  ft_putendl_fd.c \
			  ft_putnbr.c \
			  ft_putstr.c \
			  ft_putstr_fd.c \
			  ft_putnbr_fd.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isblank.c \
			  ft_iscntrl.c \
			  ft_isdigit.c \
			  ft_isgraph.c \
			  ft_islower.c \
			  ft_isprint.c \
			  ft_ispunct.c \
			  ft_isspace.c \
			  ft_isupper.c \
			  ft_isxdigit.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_memcpy.c \
			  ft_memalloc.c \
			  ft_memdel.c \
			  ft_memccpy.c \
			  ft_memchr.c \
			  ft_memmove.c \
			  ft_bzero.c \
			  ft_memset.c \
			  ft_memcmp.c \
			  ft_strcat.c \
			  ft_strncat.c \
			  ft_strlcat.c \
			  ft_strncmp.c \
			  ft_strlen.c \
			  ft_strnlen.c \
			  ft_strcpy.c \
			  ft_strclr.c \
			  ft_strncpy.c \
			  ft_strdup.c \
			  ft_strndup.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strstr.c \
			  ft_strnstr.c \
			  ft_strnew.c \
			  ft_strdel.c \
			  ft_striter.c \
			  ft_striteri.c \
			  ft_strsplit.c \
			  ft_strequ.c \
			  ft_strnequ.c \
			  ft_strsub.c \
			  ft_strmap.c \
			  ft_strjoin.c \
			  ft_strnjoinf.c \
			  ft_strtrim.c \
			  ft_strmapi.c \
			  ft_atoi.c \
			  ft_itoa.c \
			  ft_nbrlen.c \
			  ft_itoa_base.c \
			  ft_nbrlen_base.c \
			  ft_abs.c \
			  ft_lstnew.c \
			  ft_lstadd.c \
			  ft_lstiter.c \
			  ft_lstdel.c \
			  ft_lstdelone.c \
			  ft_lstmap.c \
			  ft_tbldel.c \
			  ft_realloc.c \
			  ft_wctomb.c \

SRC				:= $(addprefix src/, $(SRC_FILES))
LIBFT			:= $(addprefix libft/, $(LIBFT_FILES))
TEST			:= $(addprefix test/, $(TEST))

OBJ				:= $(SRC:.c=.o)
OBJLIBFT 		:= $(LIBFT:.c=.o)
OBJTEST			:= $(TEST:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "\033[32mCompiled Project Object Files\033[0m"

$(OBJLIBFT): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJLIBFT) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(OBJLIBFT)
	@echo "\033[32mCreated Library\033[0m"

clean:
	@rm -rf $(OBJ) $(OBJLIBFT) $(OBJTEST)
	@rm -rf main.o
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf test

re: fclean all

test: $(NAME)
	@echo "\033[32mTest Made\033[0m"
	@gcc -I include -o test printftest.c -L. -lftprintf
