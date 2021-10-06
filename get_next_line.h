/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:23:30 by jpozuelo          #+#    #+#             */
/*   Updated: 2021/10/06 17:01:50 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

typedef struct s_info
{
	int	head;
	int	buff_read;
	int	read;
	int times;
	char *line;
	char buff[BUFFER_SIZE];
} t_info;

t_list  *ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstfree(t_list **lst);

#endif
