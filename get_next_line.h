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
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_info
{
	unsigned int	head;
	unsigned int	times;
	long int   read;
	char  nword;
	char  bread;
	char *line;
	char *last;
	char buff[BUFFER_SIZE];
} t_info;

char *get_next_line(int fd);

//functions get_next_line
void  init_state(t_info *info, int fd);
void  read_update(t_info *info, int fd);
void  transfer(t_info *info);

//functions aux
char  str_tok_cpy(t_info *info, char delimiter);
void  deep_copy(t_info *info);
#endif 
