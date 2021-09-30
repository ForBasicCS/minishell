CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NAME = minishell

SRCS =	main.c\
		parsing.c\
		init.c\
		ft_list.c\
		builtin/echo.c\
		builtin/cd.c\
		builtin/pwd.c\
		exec.c\
		exec_utils.c\
		error/print_exec_err.c\
		utils/find_env.c\

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

$(NAME): $(OBJS)
	@ make bonus -C ./libft/
	$(CC) $(CFLAGS) -I ./ $^ -o $@ -lreadline ./libft/libft.a

all: $(NAME)

clean:
	rm -rf $(OBJS)
	@ make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	@ make fclean -C ./libft

re: fclean all
