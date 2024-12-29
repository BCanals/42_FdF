//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:05:01 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/29 23:12:31 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	abs(int i)
{
	if (i >= 0)
		return (i);
	return (-i);
}

void	draw_line(t_xy *ini, uint32_t color, mlx_image_t *img)
{
	t_xy	*end;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		x;
	int		y;
	int		error;
	int		e2;

	end = ini->n_x;
	dx = abs(end->x - ini->x);
	dy = 0 - abs(end->y - ini->y);
	//printf("dx = %i, dy = %i\n", dx, dy);
	x = ini->x;
	y = ini->y;
	sx = 1;
	sy = 1;
	error = dx + dy;
	//printf("error: %i\n", error);
	if (x >= end->x)
		sx = sx * -1;
	if (y >= end->y)
		sy = sy * -1;

	//printf("start x = %i,  end X = %i", ini->x, end->x);
	while (1)
	{
		//printf("printing %i, %i\n", x, y);
		my_mlx_pixel_put(img, x, y, color);
		//put_circle(prog->img, get_xy(x, y, NULL), 5, color);
		if (x == end->x && y == end->y)
			break ;
		e2 = 2 * error;
		//printf("e2 = %i\n", e2);
		//getchar();
		if (e2 >= dy)
		{
			error += dy;
			//printf("error = %i\n", error);
			//getchar();
			x += sx;
			//printf("x = %i\n", x);
			//getchar();
		}
		if (e2 <= dx)
		{
			error += dx;
			//printf("error = %i\n", error);
			//getchar();
			y += sy;
			//printf("y = %i\n", y);
			//getchar();
		}
	}
	//getchar();
}


void	render_next_frame(void *void_prog)
{
	uint32_t	color;
	t_prog 		*prog;
	t_xy		*ini;
	
	prog = void_prog;
	color = 0xFF00FFFF;
	if (prog->update == true)
	{
		ft_bzero(prog->img->pixels, prog->img->width * prog->img->height * sizeof(int32_t));
		ini = prog->net_2d;
		while (ini->n_x)
		{
			//put_circle(prog->img, get_xy(350, 350, NULL), 50, 0xFF00FFFF);
			draw_line(ini, color, prog->img);
			ini = ini->n_x;
		}
		mlx_image_to_window(prog->mlx, prog->img, 0, 0);
		//getchar();
		prog->update = false;
	}
	return ;
}

// TO-DO: in general, see if it makes sense to set a more specific int type such as int32_t

int	main(void)
{
	t_prog	prog;
	t_xy	*start;
	t_xy	*end;
	t_xy	*mid;
	t_xy	*starty2;
	t_xy	*endy2;

	end = get_xy(300, 200, NULL);
	mid = get_xy(250, 250, end);
	start = get_xy(200, 200, mid);
	prog.net_2d = start;
	prog.mlx = mlx_init(700, 700, "bcanals- fdf", true);
	prog.img = mlx_new_image(prog.mlx, 700, 700);
	prog.update = true;
	mlx_image_to_window(prog.mlx, prog.img, 0,0);
	// ft_printf("address in main: %p\n", all);
	mlx_key_hook(prog.mlx, hook, &prog);
	mlx_loop_hook(prog.mlx, *render_next_frame, &prog);
	mlx_loop(prog.mlx);
	mlx_terminate(prog.mlx);
}
