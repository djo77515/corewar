/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:11:44 by pmilan            #+#    #+#             */
/*   Updated: 2018/07/11 16:24:39 by pmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static int		ft_fruit_gnl(t_file **f, size_t n)
{
	t_file		*to_del;

	to_del = ((t_file*)ft_lstget((t_list*)*f, n));
	if (n > 0)
	{
		((t_file*)ft_lstget((t_list*)*f, n - 1))->next = \
			((t_file*)ft_lstget((t_list*)*f, n + 1));
	}
	else
	{
		to_del = *f;
		if (*f)
			*f = (*f)->next;
	}
	if (to_del)
	{
		free(to_del->s);
		free(to_del);
	}
	return (GNL_SUCCESS);
}

static int		ft_create_struct(t_file **f, int fd, size_t *n)
{
	t_file		*new;

	*n = 0;
	while (((t_file*)ft_lstget((t_list*)*f, *n)))
	{
		if (((t_file*)ft_lstget((t_list*)*f, *n))->fd == fd)
			return (GNL_SUCCESS);
		(*n)++;
	}
	*n = 0;
	if (!(new = malloc(sizeof(t_file))))
		return (GNL_ERROR);
	new->fd = fd;
	if (!(new->s = malloc(sizeof(char))))
	{
		free(new);
		return (GNL_ERROR);
	}
	new->s[0] = '\0';
	new->size = 1;
	new->next = *f;
	*f = new;
	return (GNL_SUCCESS);
}

static int		ft_get_line(t_file *tmp, char **line)
{
	size_t	size_line;

	tmp->size = ft_strlen(tmp->s);
	size_line = 0;
	while (tmp->s[size_line] != '\n' && tmp->s[size_line] != '\r'
			&& tmp->s[size_line] != '\0')
		size_line++;
	if (!(*line = malloc(sizeof(**line) * (size_line + 1))))
		return (GNL_ERROR);
	ft_strncpy(*line, tmp->s, size_line);
	(*line)[size_line] = '\0';
	ft_memmove(tmp->s, tmp->s + size_line + 1, tmp->size - size_line);
	if (!(tmp->s = ft_realloc(tmp->s, tmp->size + 1,
					tmp->size - size_line + 1)))
		return (GNL_ERROR);
	tmp->s[tmp->size - size_line] = '\0';
	tmp->size = ft_strlen(tmp->s) + 1;
	return (LINE_READ);
}

static int		ft_read(t_file *f, char **line, size_t n)
{
	int		i;
	t_file	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		ret_read;

	i = 0;
	tmp = ((t_file*)ft_lstget((t_list*)f, n));
	while (tmp->s[i] != '\n' && tmp->s[i] != '\r' && tmp->s[i])
		i++;
	if (tmp->s[i] == '\n' || tmp->s[i] == '\r')
		return (ft_get_line(tmp, line));
	if ((ret_read = read(tmp->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret_read] = '\0';
		if (!(tmp->s = ft_realloc(tmp->s, tmp->size, tmp->size + ret_read)))
			return (GNL_ERROR);
		ft_strcat(tmp->s, buf);
		tmp->size += ret_read;
		return (ft_read(f, line, n));
	}
	else if (ret_read == 0 && ft_strlen(tmp->s) == 0)
		return (GNL_END);
	else if (ret_read == 0)
		return (ft_get_line(tmp, line));
	return (GNL_ERROR);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*f = NULL;
	size_t			n;
	int				ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (GNL_ERROR);
	*line = NULL;
	if (ft_create_struct(&f, fd, &n) == GNL_ERROR)
		return (GNL_ERROR);
	ret = ft_read(f, line, n);
	if (ret == GNL_END || ret == GNL_ERROR)
		ft_fruit_gnl(&f, n);
	return (ret);
}
