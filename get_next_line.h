/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 19:21:31 by sguirrie          #+#    #+#             */
/*   Updated: 2013/12/03 19:27:51 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 32
# endif

int		get_next_line(int const fd, char **line);
int		ft_buff_read(char *buff, char **line);

#endif
