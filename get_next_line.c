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
  if (infor.line)
	  free(infor.line);
  init_state (info, fd);
  while (!(infor.nword))
  {
    if (!(infor.bread))
		read_update(info, fd);
    if (infor.read > 0)
	    transfer(info);
  }
  return (infor.line);
}
