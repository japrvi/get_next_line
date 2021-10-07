/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:22:10 by jpozuelo          #+#    #+#             */
/*   Updated: 2021/10/07 18:11:25 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*deep_copy(char *line, t_info info)
{
	char	*res;
	size_t	i;

	if (info.times > 1)
	{
		i = info.head;
		res = (char *) malloc((info.times * BUFFER_SIZE) + 1);
		while (i < info.read)
		{
			res[i] = line[i];
			i++;
		}
		free(line);
		res[i] = 0;
		info.last = res + i;
	}
	else
	{
		res = (char *) malloc(BUFFER_SIZE + 1);
		info.last = res;
	}
	return(res);
}

void	*transfer(t_info info)
{
	int		i;
	char	*last;
	char	*buff;

	i = info.head;
	last = info.last;
	while (i < BUFFER_SIZE && buff[i] != '\n' && buff[i])
	{
			last[i] = buff[i];
			i++;
	}
	last[i] = buff[i];
	if (i == BUFFER_SIZE)
	{
		buff_read = 0;
	}
	if (buff[i] == '\n')
	{
		info.encontrado = 1;
	}
	info.last += i;
	info.head += i;
}
