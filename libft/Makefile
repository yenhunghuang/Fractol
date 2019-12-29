SRC =ft_atoi.c ft_bzero.c ft_isalnum.c ft_digit_count.c\
	 ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c \
	 ft_isupper.c ft_itoa.c ft_itoa_base.c ft_lstadd.c \
	 ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	 ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	 ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	 ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	 ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	 ft_strcpy.c ft_strdel.c \
	 ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	 ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	 ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	 ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c \
	 ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	 get_next_line.c ft_errorexit.c ft_swap.c


INCLUDES= ./

NAME = libft.a
OBJECT = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra \
-I libft.h get_next_line.h
NOC=\033[0m
GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m

all: $(NAME)

$(NAME): $(OBJECT)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@echo "$(GREEN)LIBFT ✓ Created libft.a$(NOC)"

$(OBJECT): $(SRC)
	@gcc $(CFLAGS) -c $(SRC)
clean:
	@rm -f $(OBJECT)
	@echo "$(BLUE)LIBFT ✓ Removed .o files$(NOC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)LIBFT ✓ Removed libft.a$(NOC)"

re: fclean all
