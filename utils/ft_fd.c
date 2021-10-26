/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:00:14 by hynam             #+#    #+#             */
/*   Updated: 2021/10/26 19:52:14 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_flag(t_cmd **cmd, int *fd)
{
	int	flag;

	flag = 0;
	*fd = set_redir_fd(cmd);
	if (*fd == -1)
	{
		g_status = 1;
		return (-1);
	}
	if ((*cmd)->p_type == 1 || (*cmd)->p_type == 2)
	{
		flag = 1;
		dup2(*fd, 0);
	}
	else
		dup2(*fd, 1);
	close(*fd);
	return (flag);
}

void	close_all(int fd[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		close(fd[i]);
		i++;
	}
}

int	create_fd(t_cmd **cmd, int **fd)
{
	int		i;
	int		n;
	t_cmd	*tmp;

	i = 0;
	n = 0;
	tmp = *cmd;
	while (tmp)
	{
		if (tmp->p_type == 0)
			i++;
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	n = i * 2;
	if (n)
		*fd = (int *)malloc(sizeof(int) * n);
	return (n);
}

void	set_pipe_fd(t_cmd **cmd, int *fd, int n, int *i)
{
	t_cmd	*tmp;

	if (n == 0)
		return ;
	if ((*cmd)->prev)
		dup2(fd[((*i) - 1)*2], 0);
	if ((*cmd)->next != NULL)
	{
		tmp = *cmd;
		while (tmp->next && tmp->p_type != 0)
			tmp = tmp->next;
		if (tmp->p_type != -1)
			dup2(fd[(*i)*2 + 1], 1);
	}
	close_all(fd, n);
}

int	set_redir_fd(t_cmd **cmd)
{
	int	fd;

	fd = -1;
	if ((*cmd)->p_type == 1)
		fd = open((*cmd)->next->word[0], O_RDONLY);
	else if ((*cmd)->p_type == 2)
		fd = open(".tmp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if ((*cmd)->p_type == 3)
		fd = open((*cmd)->next->word[0],
				O_RDWR | O_CREAT | O_TRUNC | S_IROTH, 0644);
	else if ((*cmd)->p_type == 4)
		fd = open((*cmd)->next->word[0],
				O_RDWR | O_CREAT | O_APPEND | S_IROTH, 0644);
	return (fd);
}
