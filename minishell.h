/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:35:53 by hynam             #+#    #+#             */
/*   Updated: 2021/10/05 14:38:25 by hynam            ###   ########.fr       */
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

/*PIPE = |, INPUT = <, DOCUMENT = <<, OUTPUT = >, APPEND = >>*/
typedef enum e_pipe {PIPE, INPUT, DOCUMENT, OUTPUT, APPEND}	t_pipe;

typedef struct s_cmd
{
	char			**word;		//스플릿한 단어들
	int				is_str;		//"<<"이런식으로 들어오면 리다이렉션이 아닌 문자열로 인식해야하므로 0로 저장
	int				p_type;		//파이프 타입, -1이면 없는거
	char			quote;		//따옴표를 만나면 그 따옴표를 저장 -> 0이되면 따옴표가 쌍으로 있다
	t_list			*environ;	//환경변수
	int				ch;
	int				idx;
	struct s_cmd	*next;
	struct s_cmd	*prev;
	struct termios	org_term;	//캐노니컬 모드 터미널 옵션
	struct termios	new_term;	//논캐노니컬 모드 터미널 옵션
}t_cmd;

void	init_data(t_cmd	*cmd);
void	init_envp(t_cmd *cmd, char **envp);

int		parsing(t_cmd *cmd, char *str);
void	free_all(t_cmd *cmd);

/* list function */
int		compare(t_list *environ, char *str);
void	remove_list(t_list *environ, char *look);
void	clear_list(t_list **lst);

/* termianl function */
void	save_input_mode(t_cmd *cmd);
void	set_input_mode(t_cmd *cmd);
void	reset_input_mode(t_cmd *cmd);

char	*ft_readline(t_cmd *cmd);

/* in exec dir */
int		check_builtin(t_cmd *cmd);
int		exec_builtin(t_cmd *cmd);
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
char	*ft_strjoinchr(char *src, int ch);
char	*ft_chrdup(int ch);
char	*ft_strdown(char *str);

#endif