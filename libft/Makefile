NAME 	= libft.a
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I includes/

SRC = ft_putchar.c \
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
	  ft_itoa_base.c \
	  ft_nbrlen.c \
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

.PHONY = all clean

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c 
	@gcc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) 
	@echo "\033[32mLibft Created\033[0m"

clean: 
	@rm -f $(OBJ)
	@echo "\033[32mLibft Object Files Removed\033[0m"

fclean: clean
	@rm -f $(NAME) 
	@echo "\033[32mLibft Removed\033[0m"
	
re: fclean all
