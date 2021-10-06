/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:22:48 by jpozuelo          #+#    #+#             */
/*   Updated: 2021/10/06 18:43:41 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_info info;

	while()
	{
	if (buff_read)
		read_update(info, fd);

	}
}

void	read_update(t_info info, int fd)
{
	read += read(fd, info.buff, BUFFER_SIZE);
	info.head = 0;
	info.buff_read = 1,
	info.times += 1;
	if (times == 1)
		info.line = deep_copy(info.buff, info);
	else
		info.line = deep_copy(info.line, info);
}

void	
