NAME = minishell

SRC = src/commands.c src/mem.c src/main.c src/environ.c libft/libft.a

FLAGS = clang -Werror -Wextra -Wall -g -I includes -o

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/ all
	@$(FLAGS) $(NAME) $(SRC)

clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
