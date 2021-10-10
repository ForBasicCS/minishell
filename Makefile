CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -Qunused-arguments -L$(READLINE_DIR) -I$(READLINE_INC)

NAME = minishell

SRCS =	main.c\
		parsing.c\
		init.c\
		ft_list.c\
		free_all.c\
		cmds.c\
		builtin/echo.c\
		builtin/cd.c\
		builtin/pwd.c\
		builtin/env.c\
		builtin/exit.c\
		builtin/export.c\
		builtin/unset.c\
		exec/exec.c\
		exec/exec_pipe.c\
		exec/exec_utils.c\
		error/print_exec_err.c\
		utils/find_env.c\
		utils/builtin_util.c\
		utils/signal_util.c\
		utils/ft_chrdup.c\
		utils/ft_strjoinchr.c\
		utils/ft_strdown.c\

READLINE_DIR = /usr/local/opt/readline/lib/
READLINE_INC = /usr/local/opt/readline/include/

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
