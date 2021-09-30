/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:35:53 by hynam             #+#    #+#             */
/*   Updated: 2021/09/30 17:35:55 by minchoi          ###   ########.fr       */
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

extern int g_status;

typedef struct s_cmd
{
	char	**word;		//스플릿한 단어들
	int		is_pipe;	//파이프 유무 -> 개수까지
	int		i_redir;	//인풋 리다이렉션 -> 0이 디폴트, 1이면 < 2이면 <<
	int		o_redir;	//아웃풋 리다이렉션 -> 0이 디폴트, 1이면 > 2이면 >>
	char	quote;		//따옴표를 만나면 그 따옴표를 저장 -> 0이되면 따옴표가 쌍으로 있다
	t_list	*environ;	//환경변수
}t_cmd;

void	init_data(t_cmd	*cmd, char **envp);
int		parsing(t_cmd *cmd, char *str);
void	print_all(t_cmd *cmd);

/* list function */
void	remove_list(t_list *head, char *find, int compare(t_cmd *cmd, char *str));
void	clear_list(t_list **lst);

int		check_builtin(t_cmd *cmd);
void	exec_builtin(t_cmd *cmd);

/* in builtin dir */
void	ft_echo(t_cmd *cmd);
void	ft_cd(t_cmd *cmd);
void	ft_pwd(t_cmd *cmd);
void	ft_env(t_cmd *cmd);
void	ft_exit(t_cmd *cmd);

/* in error dir */
int		print_exec_err(char *ins, char *arg, char *err_msg);

/* in env dir */
char	*find_env(char *env_var, t_list *environ);
char	*make_path(char *path_a, char *path_b);

#endif