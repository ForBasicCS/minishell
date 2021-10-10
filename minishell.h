/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:35:53 by hynam             #+#    #+#             */
/*   Updated: 2021/10/10 14:19:40 by minchoi          ###   ########.fr       */
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

extern t_list	*g_environ;

/*PIPE = |, INPUT = <, DOCUMENT = <<, OUTPUT = >, APPEND = >>*/
typedef enum e_pipe {PIPE, INPUT, DOCUMENT, OUTPUT, APPEND}	t_pipe;

typedef struct s_cmd
{
	char			**word;		//스플릿한 단어들
	int				p_type;		//파이프 타입, -1이면 없는거
	char			quote;		//따옴표를 만나면 그 따옴표를 저장 -> 0이되면 따옴표가 쌍으로 있다
	t_list			*environ;	//환경변수
	int				cmd_num;	//cd .. -> 2개, 기본 0개
	char			**path;		//$PATH 의 경로를 저장하기 위한 변수
	int				status;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}t_cmd;

void	init_data(t_cmd	*cmd);
void	init_envp(char **envp);

int		parsing(t_cmd *cmd, char *str);
void	free_ctrl_d(t_cmd *cmd);

/* cmds function */
void	go_head_cmd(t_cmd **cmd);
void	clear_cmd(t_cmd **cmd);
void	add_cmd(t_cmd **cmd);

/* list function */
int		compare(t_list *environ, char *str);
void	remove_list(t_list *environ, char *look);
void	clear_list(t_list **lst);

/* in exec dir */
int		check_builtin(t_cmd *cmd);
int		exec_builtin(t_cmd *cmd, char **envp);
int		exec_pipe(int argc, char **argv, char **envp);

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
int		export_unset_return(int ret);
void	set_signal(void);
char	*ft_strjoinchr(char *src, int ch);
char	*ft_chrdup(int ch);
char	*ft_strdown(char *str);

#endif