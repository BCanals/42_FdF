/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:48:25 by bizcru            #+#    #+#             */
/*   Updated: 2025/01/10 17:40:13 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	do_load(t_prog *prog, int fd, int size)
{
	char	*line;
	char	**split;
	t_xyz	*prev_x;
	t_xyz	*prev_y;
	int		c[2];

	c[1] = -1;
	line = get_next_line(fd);
	while (line)
	{
		load_c(c, size);
		prev_x = NULL;
		split = ft_split(line, ' ');
		while (--(c[0]) >= 0)
			prev_x = get_xyz(c[0], c[1], ft_atoi(split[c[0]]), prev_x);
		if (!prog->net)
			prog->net = prev_x;
		else
			prev_y->n_y = prev_x;
		prev_y = prev_x;
		ft_free_array(split);
		free(line);
		line = get_next_line(fd);
	}
}

static int	check_file(int fd)
{
	char	*line;
	char	**split;
	int		size;
	int		this_size;

	line = get_next_line(fd);
	size = 0;
	while (line)
	{
		split = ft_split(line, ' ');
		this_size = split_count(split);
		if (size == 0)
			size = this_size;
		free(line);
		ft_free_array(split);
		if (this_size != size)
		{
			ft_putstr_fd("the file is not in the correct format\n", 2);
			return (-1);
		}
		line = get_next_line(fd);
	}
	return (size);
}

static void	link_y(t_xyz *ini)
{
	t_xyz	*prev;
	t_xyz	*next;

	next = ini->n_y;
	while (next)
	{
		prev = ini;
		while (prev)
		{
			prev->n_y = next;
			prev = prev->n_x;
			next = next->n_x;
		}
		ini = ini->n_y;
		next = ini->n_y;
	}
}

static t_limits	*project(t_xyz *ini)
{
	t_xyz		*p;
	t_limits	*l;

	l = init_limits();
	if (!l)
		return (NULL);
	while (ini)
	{
		p = ini;
		while (p)
		{
			p->proj_x = (p->x * 9 - p->y * 9) * cos(M_PI / 6);
			p->proj_y = (p->x * 9 + p->y * 9) * sin(M_PI / 6) - p->z * 9;
			update_limits(p, l);
			p = p->n_x;
		}
		ini = ini->n_y;
	}
	return (l);
}

t_limits	*load_map(t_prog *prog, char *path)
{
	int			fd;
	int			size;
	t_limits	*l;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("error opening the file");
		return (NULL);
	}
	size = check_file(fd);
	if (size == -1)
		return (NULL);
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("error opening the file");
		return (NULL);
	}
	do_load(prog, fd, size);
	link_y(prog->net);
	l = project(prog->net);
	return (l);
}
