NAME = libftprintf.a

SRCS =	ft_printf.c	\
		ft_print_char.c \
		ft_print_number.c	\
		ft_print_hexa.c		\
		ft_print_pointer.c

CFLAGS = -Wall -Werror -Wextra

CC = cc

AR = ar rcs

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all