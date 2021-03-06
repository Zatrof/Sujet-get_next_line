/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 19:07:50 by sguirrie          #+#    #+#             */
/*   Updated: 2013/12/08 19:03:15 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include "get_next_line.h"

int		ft_buff_read(char *buff, char **line)
{
	char			*temp;
	char			*remain;

	temp = *line;
	remain = ft_strchr(buff, '\n');
	if (remain != NULL)
	{
		*line = ft_strjoin(*line, ft_strsub(buff, 0, (remain - buff)));
		if (temp != NULL)
			free(temp);
		return (1);
	}
	else
	{
		*line = ft_strjoin(*line, buff);
		if (temp != NULL && *line == NULL)
			free(temp);
		if (remain == NULL && (ft_strlen(buff) == BUFF_SIZE))
			return (0);
		else
			return (1);
	}
}

int		get_next_line(int const fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	int				ret;
	char			*cue;

	*line = ft_strnew(1);
	ft_bzero(*line, 1);
	if (buff[0] != '\0')
	{
		if (!ft_strchr(buff, '\n'))
			return (0);
		cue = (ft_strchr(buff, '\n') + 1);
		if (ft_buff_read(cue, line) == 1)
		{
			ft_strncpy(buff, cue, BUFF_SIZE + 1);
			return (1);
		}
	}
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_buff_read(buff, line) == 1)
			return (1);
	}
	return (ret);
}
