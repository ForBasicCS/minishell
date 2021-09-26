CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NAME = minishell

<<<<<<< HEAD
SRCS = main.c \
		parsing.c \
		init.c \
=======
SRCS =	main.c\
		builtin/echo.c\
		builtin/cd.c\
		exec.c\
		exec_utils.c\
		error/print_exec_err.c\
>>>>>>> 1176484d4efeedc4f33bb5cd21ef37af9618b4ef

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@ make bonus -C ./libft/
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I ./ $^ -o $@ -lreadline ./libft/libft.a

all: $(NAME)

clean:
	rm -rf $(OBJS)
	@ make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	@ make fclean -C ./libft

re: fclean all
