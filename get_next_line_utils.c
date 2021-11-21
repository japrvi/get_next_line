/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:22:10 by jpozuelo          #+#    #+#             */
/*   Updated: 2021/11/07 18:43:03 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	deep_copy(t_info *info)
{
	char			*line;
	char			*nline;
	unsigned int	i;

	line = info->line;
	if (line)
	{
		(info->times)++;
		nline = (char *) malloc(((BUFFER_SIZE) * (info->times)) + 1);
		i = 0;
		while (line[i])
		{
			nline[i] = line[i];
			i++;
		}
		nline[i] = line[i];
		info->line = nline;
		info->last = nline + i;
		free(line);
	}
}

char	str_tok_cpy(t_info *info, char delimiter)
{
	unsigned int	head;
	unsigned int	i;
	char			*buff;
	char			*last;

	i = 0;
	head = info->head;
	last = info->last;
	buff = info->buff;
	while (buff[head + i] && buff[head + i] != delimiter)
	{
		last[i] = buff[head + i];
		i++;
	}
	last[i] = buff[head + i];
	info->last = last + i;
	info->head = head + i + 1;
	if (buff[head + i] == delimiter)
		return (delimiter);
	else
		return (0);
}

void	transfer(t_info *info)
{
	char	cpy;

	cpy = str_tok_cpy(info, '\n');
	if (cpy == '\n')
	{
		info->nword = 1;
		(info->last)++;
		*(info->last) = 0;
		if ((info->buff)[info->head] == 0)
		{
			info->bread = 0;
		}
		else
		{
			info->bread = 1;
		}
	}
	else
	{
		info->bread = 0;
		deep_copy(info);
	}
}

void	read_update(t_info *info, int fd)
{
	int		r;
	char	*buff;

	buff = info->buff;
	r = read(fd, buff, BUFFER_SIZE);
	if (r <= 0)
		info->nword = 1;
	else 
		buff[r] = 0;
	info->head = 0;
	info->bread = 1;
	info->read = r;
}

void	init_state(t_info *info , int fd)
{
	int	r;

	info->line = NULL;
	info->last = NULL;
	r = info->read;
	if (!(info->bread))
	{
		r = read(fd, (info->buff), BUFFER_SIZE);
		(info->buff)[r] = 0;
		info->head = 0;
	}
	if (r <= 0)
	{
		info->nword = 1;
		info->times = 0;
	}
	else
	{
		info->nword = 0;
		info->line = (char *) malloc(BUFFER_SIZE + 1);
		info->last = info->line;
		info->times = 1;
	}
	info->read = r;
