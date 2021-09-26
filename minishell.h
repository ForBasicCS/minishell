/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:35:53 by hynam             #+#    #+#             */
/*   Updated: 2021/09/26 16:48:56 by hynam            ###   ########.fr       */
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

typedef struct s_cmd
{
	char	**word;		//스플릿한 단어들
	int		is_pipe;	//파이프 유무 -> 개수까지
	int		i_redir;	//인풋 리다이렉션 -> 0이 디폴트, 1이면 < 2이면 <<
	int		o_redir;	//아웃풋 리다이렉션 -> 0이 디폴트, 1이면 > 2이면 >>
	char	quote;		//따옴표를 만나면 그 따옴표를 저장 -> 0이되면 따옴표가 쌍으로 있다
	char	*environ;	//환경변수
}t_cmd;

void	init_list(t_list *lst);
t_list	*new_list(t_list *lst, t_cmd *cmd);
int		parsing(t_list *lst, char *str);
void	print_all(t_cmd *cmd);

#endif