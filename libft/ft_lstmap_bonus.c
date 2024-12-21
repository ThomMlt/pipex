/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:16:22 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/27 16:01:26 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*tmp;
	void	*content;

	if (!lst || !f)
		return (NULL);
	dest = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			if (content)
				del(content);
			ft_lstclear(&dest, del);
			return (NULL);
		}
		ft_lstadd_back(&dest, tmp);
		lst = lst->next;
	}
	return (dest);
}
