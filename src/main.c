/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:05:01 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/14 20:06:08 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

t_pos	get_pos(int x, int y)
{
	t_pos	rtrn;

	rtrn.x = x;
	rtrn.y = y;
	return (rtrn);
}

void put_rectangle(t_data *img, t_pos pos, t_pos size, int color)
{
	int i;
	int j;
	color++;

	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			my_mlx_pixel_put(img, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
	}
}

void	put_circle(t_data *img, t_pos cent, int radius, int color)
{
	int i;
	int j;
	int top_i;
	int top_j;
	int limit;

	limit = radius*radius - cent.x*cent.x - cent.y*cent.y;
	top_i = cent.x + radius;
	top_j = cent.y + radius;
	i = cent.x - radius;
	while (i <= top_i)
	{
		j = cent.y - radius;
		while (j <= top_j)
		{
			if (i * (i + 2 * cent.x) + j * (j + 2 * cent.y) <= limit)
				my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}

int main()
{
	void	*mlx;
	void	*mlx_win;
	//void	*img;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	put_rectangle(&img, get_pos(500, 500), get_pos(100, 100), 0x0000FF00);
	put_circle(&img, get_pos(500, 500), 100, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
