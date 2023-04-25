NAME = fractol

CC = gcc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror -g

SRC = $(wildcard *.c)

OBJS = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) ./mlx_linux/libmlx_Linux.a -o $@ -lm -lX11 -lXext
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