/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:48:25 by bizcru            #+#    #+#             */
/*   Updated: 2025/01/10 11:00:07 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static int do_load(t_prog *prog)
{
	t_xy	*start;
	t_xy	*end;
	t_xy	*mid;
	t_xy	*starty;
	t_xy	*midy;
	t_xy	*endy;

	endy = get_xy(300, 250, NULL, NULL);
	midy = get_xy(250, 250, endy, NULL);
	starty = get_xy(200, 250, midy, NULL);
	end = get_xy(300, 200, NULL, endy);
	mid = get_xy(250, 200, end, midy);
	start = get_xy(200, 200, mid, starty);
	prog->net_2d = start;
	return (1);
}*/

void points_clean_up(t_xy *start)
{
	t_xy	*next;
	t_xy	*next_line;

	next_line = start->n_y;
	while (start)
	{
		while (start)
		{
			next = start->n_x;
			free(start);
			start = next;
		}
		start = next_line;
		next_line = start->n_y;
	}
}

static int	split_count(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static void	do_load(t_prog *prog, fd)
{
	char	*line;
	char	**split;
	t_xyz	*prev_x;
	t_xyz	*prev_y;
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		prev_x = NULL;
		split = ft_split(line);
		while (split[++x]);
		while (--x >= 0)
			prev_x = get_xyz(x, y, ft_atoi(split[x]), prev_x);
		if (!prog->net_3d)
			prog->net_3d = prev_x;
		else
			prev_y->n_y = prev_x;
		prev_y = prev_x;
		line = get_next_line(fd);
	}
}

static int check_file(fd)
{
	char	*line;
	char	**split;
	int		size;
	int		this_size;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		split = ft_split(line);
		this_size = split_count(split);
		free(line);
		ft_free_array(split);
		if (this_size != size)
		{
			ft_putstr_fd("the file is not in the correct format\n", 2);
			return (-1);
		}
		size = this_size;
		line = get_next_line(fd);
	}
	return (0);
}

int load_map(t_prog *prog, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("error opening the file");
		return (-1);
	}
	if (check_file(prog, fd) == -1)
		return (-1);
	close(fd);
	if (fd == -1)
	{
		perror("error opening the file");
		return (-1);
	}
	do_load(prog, fd);
	link_y(prog
	return (0);
}
