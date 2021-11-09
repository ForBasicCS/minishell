/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:35:53 by hynam             #+#    #+#             */
/*   Updated: 2021/10/28 13:27:00 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <termios.h>
# include <termcap.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

extern int	g_status;

/*PIPE = |, INPUT = <, DOCUMENT = <<, OUTPUT = >, APPEND = >>*/
typedef enum e_pipe {PIPE, INPUT, DOCUMENT, OUTPUT, APPEND}	t_pipe;

typedef struct s_cmd
{
	char			**word;
	int				p_type;
	char			quote;
	t_list			*environ;
	int				cmd_num;
	char			**path;
	pid_t			pid;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}t_cmd;

void	init_data(t_cmd	*cmd, t_list *l_env);
t_list	*pre_process(char **envp);

int		is_pipe(char *str);
int		parsing(t_cmd **cmd, t_list *l_env, char *str);

/* cmds function */
void	go_head_cmd(t_cmd **cmd);
void	remove_cmd(t_cmd **cmd);
void	clear_cmd(t_cmd **cmd, char **str);
void	add_cmd(t_cmd **cmd, t_list *l_env);

/* list function */
int		compare(t_list *environ, char *str);
void	remove_list(t_list *environ, char *look);
void	clear_list(t_list **lst);

/* in exec dir */
int		here_document(t_cmd **cmd, int fd);
int		check_builtin(t_cmd *cmd);
int		exec_builtin(t_cmd *cmd);
int		exec_pipe(t_cmd **cmd);
int		exec_cmd(t_cmd **cmd);

/* in builtin dir */
int		ft_echo(t_cmd *cmd);
int		ft_cd(t_cmd *cmd);
int		ft_pwd(t_cmd *cmd);
int		ft_env(t_cmd *cmd);
int		ft_exit(t_cmd *cmd);
int		ft_export(t_cmd *cmd);
int		ft_unset(t_cmd *cmd);

/* in error dir */
int		print_exec_err(char *ins, char *arg, int err_flag);

/* in utils dir */
char	*find_env_value(char *env_key, t_list *environ);
t_list	*find_env(char *env_key, t_list *env);
char	*make_path(char *path_a, char *path_b);
char	*front_of_env(char *path, int dollar_sign);
void	none_ctrl_d(void);
void	set_signal(void);
char	**ft_arrjoinstr(char **s1, char *s2);
void	ft_strcpy_trim(char *dest, char trim);
int		is_pipe(char *str);
int		is_valid(char *str);
int		check_syntax(char **split);

int		set_redir_fd(t_cmd **cmd);
void	set_pipe_fd(t_cmd **cmd, int *fd, int n, int *i);
int		create_fd(t_cmd **cmd, int **fd);
void	close_all(int fd[], int n);
int		set_flag(t_cmd **cmd, int *fd);

#endif