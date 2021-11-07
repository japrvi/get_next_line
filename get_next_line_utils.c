/* ************************************************************************ */
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
}

char	str_tok_cpy(char *source, char *target, char *delimiter)
{
}

void	transfer(t_info *info)
{
	char	*last;
	char	*buff;
	char	cpy;

	buff = info->buff;
	last = info->last;
	if (cpy == '\n')
	{
		last[i + 1] = 0;
		info->nword = 1;
	}
	else
	{
		info->head += i;
		info->bread = 1;
	}
}

void	read_update(t_info *info, int fd)
{
	int		r;
	char	*buff;

	buff = info->buff;
	r = read(fd, buff, BUFFER_SIZE);
	buff[r] = 0;
	deep_copy(info);
	info->bread = 1;
}

void	init_state(t_info *info , int fd)
{
	int	r;

	if (info->line)
		free(info->line);
	r = read(fd, info->buff, BUFFER_SIZE);
	if (r <= 0)
	{
		info->nword = 1;
		info->line = NULL;
		info->last = NULL;
		info->times = 0;
	}
	else
	{
		info->nword = 0;
		info->line = (char *) malloc(BUFFER_SIZE);
		info->last = info->line;
		info->times = 1;
	}
}
