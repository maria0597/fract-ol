NAME = fractol

CC = gcc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

FLAGS2 = -lmlx -framework OpenGL -framework AppKit

SRC = draw_utils.c hook.c tree.c main.c mandelbrot.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
			$(CC) $(FLAGS) $(FLAGS2) $(SRC) -o fractol
norme:
					@norminette $(SRC)

clean:
					$(RM) $(OBJS)
					@echo "\033[36mFractol >> Deleted \".o\" files\033[0m"

fclean:		clean
					$(RM) $(NAME)
					@echo "\033[35mFractol >> Project cleaned\033[0m"

re:		fclean all
					@echo "\033[0;92mFractol >> Project cleaned and recompiled\033[0m"

.PHONY: all bonus clean fclean re