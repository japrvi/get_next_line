/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:23:30 by jpozuelo          #+#    #+#             */
/*   Updated: 2021/10/07 18:11:19 by jpozuelo         ###   ########.fr       */
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
	int encontrado;
	char *line;
	char *last;
	char buff[BUFFER_SIZE];
} t_info;

char *deep_copy(t_info info);

#endif
