/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehuang <yenhang1@gmail.co>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:30:03 by yehuang           #+#    #+#             */
/*   Updated: 2019/08/20 15:06:46 by yehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	rewriteline(char **data, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*data)[i] != '\n' && (*data)[i] != '\0')
		i++;
	if ((*data)[i] == '\n')
	{
		*line = ft_strsub(*data, 0, i);
		tmp = ft_strdup(&((*data)[i + 1]));
		free(*data);
		*data = tmp;
		if (!(*data)[0])
			ft_strdel(data);
	}
	else
	{
		*line = ft_strdup(*data);
		ft_strdel(data);
	}
	return (1);
}

static int	pass_norm(char **data, char **line, int r, int fd)
{
	if (r < 0)
		return (-1);
	else if (r == 0 && !data[fd])
		return (0);
	else
		return (rewriteline(&data[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	static char	*data[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	int			r;
	char		*tmp;

	if (fd < 0 || !line)
		return (-1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (!data[fd])
			data[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(data[fd], buff);
			free(data[fd]);
			data[fd] = tmp;
		}
		if (ft_strchr(data[fd], '\n'))
			break ;
	}
	return (pass_norm(data, line, r, fd));
}
