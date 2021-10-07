/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:22:48 by jpozuelo          #+#    #+#             */
/*   Updated: 2021/10/07 18:11:22 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_info info;

	while(!info.encontrado)
	{
	if (!buff_read)
		read_update(info, fd);
	transfer(info);
	if (head == BUFFER_SIZE)
	{
		
	}
	if (*(info.last) != 0)
		last[i + 1]; = 0;
	return (info.line);
}

void	read_update(t_info info, int fd)
{
	int readed;

	readed = info.read;
	info.read += read(fd, info.buff, BUFFER_SIZE);
	info.head = 0;
	info.buff_read = 1,
	info.times += 1;
	if (readed != info.read)
	{
		info.line = deep_copy(info.buff, info);
	}
	else
		info.enontrado = 1;
}
