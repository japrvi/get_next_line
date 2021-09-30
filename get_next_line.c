/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:22:48 by jpozuelo          #+#    #+#             */
/*   Updated: 2021/09/30 18:26:54 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_info	info;
	t_list			**lst;
	char			*buff;


}


void	info_list_init(t_list **lst, t_info info, char *buff)
{
	*lst = NULL;
	info.head = 0;
	info.buff_read = 0;
	info.read = read(fd, buff, BUFFER_SIZE);
	info.found = 0;
}

void	info_list_update(t_list **lst, t_info, char *buff)
{

}

void	buff_search(t_list **lst, t_info info, char *buff)
{
	int		i;
	int		head;
	char	*ptr;
	
	i = info.head;
	head = info.head;
	while (i < BUFFER_SIZE && buff[i] != '\n')
		i++;
	ptr = (char *) mallloc(i - head + 1);
	ptr[i] = 0;
	info.head = i;
	while (--i > head)
		ptr[i] = buff[i];
	ft_lstadd_back(lst, ft_lstnew(ptr));
}
