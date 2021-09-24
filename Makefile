CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = minishell

SRCS = main.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@ make -C ./libft/
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
