/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:22:48 by jpozuelo          #+#    #+#             */
/*   Updated: 2021/11/07 18:43:11 by jpozuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_info infor;
	t_info        *info;

  info = &infor;
  init_state (info, fd);
  //printf("Estado incial: read = %d, bread =%u, times =%d\n", infor.read, infor.bread, infor.times);
  //printf("Inicializo.\nInfo buff:%s\n Info line:%s\n", infor.buff, infor.line);
  while (!(infor.nword))
  {
    if (infor.read > 0)
	{
		transfer(info);
		//printf("Transfiero.\nInfo buff: %s\n Info line: %s\n Bread: %u\n", infor.buff, infor.line, infor.bread);
	}
    if (!(infor.bread))
	{
		read_update(info, fd);
		//printf("Actualizo read=%d bread=%u.\n", infor.read, infor.bread);
	}
  }
  return (infor.line);
}
