/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:35:04 by hynam             #+#    #+#             */
/*   Updated: 2020/12/25 13:39:22 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*crnt;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (NULL);
	lst = lst->next;
	tmp = head;
	while (lst)
	{
		crnt = ft_lstnew(f(lst->content));
		if (crnt == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tmp->next = crnt;
		tmp = crnt;
		lst = lst->next;
	}
	return (head);
}
