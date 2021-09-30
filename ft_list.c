/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:05:44 by hynam             #+#    #+#             */
/*   Updated: 2021/09/29 21:36:03 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//str = 찾고자 하는 환경변수 를 찾는 함수
int	compare(t_cmd *cmd, char *str)
{
	int	i;

	i = 0;
	while (cmd->environ)
	{
		if (ft_strncmp((char *)cmd->environ->content, str, ft_strlen(str)) == 0)
			return (0);
		else
			cmd->environ = cmd->environ->next;
	}
	return (1);
}

//지우고자 하는 환경변수를 찾으면 지우는 함수
void	remove_list(t_list *head, char *find,
					int compare(t_cmd *cmd, char *str))
{
	t_list	*ptr;
	t_list	*tmp;

	if (head != NULL)
	{
		ptr = head;
		while (ptr->next != NULL)
		{
			if (compare((t_cmd *)ptr->next->content, find) == 0)
			{
				tmp = ptr->next->next;
				free(ptr->next);
				ptr->next = tmp;
				return ;
			}
			else
				ptr = ptr->next;
		}
	}
}

//나중에 리스트 초기화 할때 필요
void	clear_list(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
