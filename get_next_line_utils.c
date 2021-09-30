/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:22:10 by jpozuelo          #+#    #+#             */
/*   Updated: 2021/09/30 18:29:00 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;
	
	ptr = (t_list *) malloc(sizeof(t_list));
	if (ptr)
	{
		(ptr->content) = content;
		(ptr->next) = NULL;
	}
	return (ptr);
}

t_list ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *aux;

	if (!(*lst))
		*lst = new;
	else
	{
		aux = ft_lstlast(*lst);
		(aux->next) = new;
	}
}

void	ft_lstfree(t_list **lst)
{
	t_list	*aux;
	t_list	*tmp;

	aux = *lst;
	while (aux)
	{
		tmp = (aux->next);
		free(aux);
		aux = tmp;
	}
}
