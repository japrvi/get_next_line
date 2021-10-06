/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:22:10 by jpozuelo          #+#    #+#             */
/*   Updated: 2021/10/06 17:21:56 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*depp_ccopy(char *buff, t_info info)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *) malloc((info.times * BUFFER_SIZE) + 1);
	while (buff[i])
	{
		res[i] = buff[i];
		i++;
	}
	free(buff);
}
