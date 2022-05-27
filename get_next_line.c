/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:51:35 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/05/27 07:04:06 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_save(int fd, char *save)
{
	char	*buffer;
	char	*tmp;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	i = 1;
	while (!ft_strchr(save) && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[i] = '\0';
		tmp = ft_strjoin(save, buffer);
		free(save);
		save = tmp;
	}
	free(buffer);
	return (save);
}

char	*get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	line[++i] = '\0';
	while (i--)
		line[i] = save[i];
	return (line);
}

char	*get_newsave(char *save)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!tmp)
		return (0);
	while (save[i])
		tmp[j++] = save[++i];
	tmp[j] = '\0';
	free(save);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || read(fd, save, 0) == -1)
		return (0);
	if (!save)
	{
		save = malloc(sizeof(char));
		save[0] = '\0';
	}
	save = get_save(fd, save);
	line = get_line(save);
	save = get_newsave(save);
	return (line);
}
