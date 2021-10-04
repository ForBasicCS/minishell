/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:05:44 by hynam             #+#    #+#             */
/*   Updated: 2021/10/04 17:30:12 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//str = 찾고자 하는 환경변수 를 찾는 함수
int	compare(t_list *environ, char *str)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = environ;
	if (ft_strncmp((char *)tmp->content, str, ft_strlen(str)) == 0
		&& ((char *)tmp->content)[ft_strlen(str)] == '=')
		return (0);
	return (1);
}

//지우고자 하는 환경변수를 찾으면 지우는 함수
void	remove_list(t_list *environ, char *look)
{
	t_list	*ptr;
	t_list	*tmp;

	if (environ != NULL)
	{
		ptr = environ;
		while (ptr->next != NULL)
		{
			if (compare(ptr->next, look) == 0)
			{
				tmp = ptr->next->next;
				free(ptr->next->content);
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
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
