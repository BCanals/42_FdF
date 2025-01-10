/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:05:01 by bcanals-          #+#    #+#             */
/*   Updated: 2025/01/10 17:35:06 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	abs(int i)
{
	if (i >= 0)
		return (i);
	return (-i);
}

static void	load_vars(int v[3][2], t_xyz *ini, t_xyz *end)
{
	v[0][0] = abs(end->proj_x - ini->proj_x);
	v[0][1] = 0 - abs(end->proj_y - ini->proj_y);
	v[2][0] = ini->proj_x;
	v[2][1] = ini->proj_y;
	v[1][0] = 1;
	v[1][1] = 1;
	if (v[2][0] >= end->proj_x)
		v[1][0] = v[1][0] * -1;
	if (v[2][1] >= end->proj_y)
		v[1][1] = v[1][1] * -1;
}

static void	draw_line(t_xyz *ini, t_xyz *end, uint32_t color, mlx_image_t *img)
{
	int	v[3][2];
	int	error;
	int	e2;

	if (!ini || !end)
		return ;
	load_vars(v, ini, end);
	error = v[0][0] + v[0][1];
	while (1)
	{
		my_mlx_pixel_put(img, v[2][0], v[2][1], color);
		if (v[2][0] == end->proj_x && v[2][1] == end->proj_y)
			break ;
		e2 = 2 * error;
		if (e2 >= v[0][1])
		{
			error += v[0][1];
			v[2][0] += v[1][0];
		}
		if (e2 <= v[0][0])
		{
			error += v[0][0];
			v[2][1] += v[1][1];
		}
	}
}

static void	draw_map(mlx_image_t *img, t_xyz *p)
{
	t_xyz	*ini_y;

	ini_y = p;
	while (p)
	{
		while (p)
		{
			if (p->n_x)
				draw_line(p, p->n_x, 0xFF00FFFF, img);
			if (p->n_y)
				draw_line(p, p->n_y, 0xFF00FFFF, img);
			p = p->n_x;
		}
		ini_y = ini_y->n_y;
		p = ini_y;
	}
}

int	main(int argc, char **argv)
{
	t_prog		prog;
	t_limits	*l;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf file_path\n");
		return (0);
	}
	prog.net = NULL;
	l = load_map(&prog, argv[1]);
	if (!l)
		return (points_clean_up(prog.net));
	normalize_proj(prog.net, l);
	prog.mlx = mlx_init(l->max_x - l->min_x + 20, l->max_y - l->min_y + 20,
			"bcanals- fdf", true);
	prog.img = mlx_new_image(prog.mlx, l->max_x - l->min_x + 20,
			l->max_y - l->min_y + 20);
	draw_map(prog.img, prog.net);
	mlx_image_to_window(prog.mlx, prog.img, 0, 0);
	mlx_key_hook(prog.mlx, hook, &prog);
	mlx_loop(prog.mlx);
	points_clean_up(prog.net);
	free(l);
	mlx_delete_image(prog.mlx, prog.img);
	mlx_terminate(prog.mlx);
}
