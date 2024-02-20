NAME = fractol

SRCS =	intit.c  main.c math_util.c render.c string_utils.c events.c julia.c \

CFLAGS = -Wall -Werror -Wextra

CC = cc

OBJ = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ) 
		$(CC) $(CFLAGS) -I./mlx -L./mlx -lmlx  -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all