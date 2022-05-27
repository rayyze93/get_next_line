/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:43:11 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/05/27 01:54:02 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_strchr(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_save(int fd, char *save);
char	*get_line(char *save);
char	*get_newsave(char *save);
char	*get_next_line(int fd);

#endif
