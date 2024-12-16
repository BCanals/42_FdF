//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:05:01 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/16 21:00:50 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, unsigned int x, unsigned int y, int color)
{
	char	*dst;
	mlx_image_t	*my_img;

	my_img = (mlx_image_t *)img->img;
	//if (x * (img->bpp / 8) <= my_img->width && y <= my_img->height)
	if (x < my_img->width && y < my_img->height)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

t_pos	*get_pos(unsigned int x, unsigned int y)
{
	t_pos	*rtrn;

	rtrn = malloc(sizeof(t_pos));
	if (!rtrn)
		return (NULL);
	rtrn->x = x;
	rtrn->y = y;
	return (rtrn);
}

void	put_rectangle(t_data *img, t_pos pos, t_pos size, int color)
{
	unsigned int	i;
	unsigned int	j;

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

void	put_circle(t_data *img, t_pos *cent, int radius, int color)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	top_i;
	unsigned int	top_j;
	unsigned int	limit;

	limit = radius * radius - cent->x * cent->x - cent->y * cent->y;
	top_i = cent->x + radius;
	top_j = cent->y + radius;
	i = cent->x - radius;
	while (i <= top_i)
	{
		j = cent->y - radius;
		while (j <= top_j)
		{
			if ((i * (i - 2 * cent->x) + j * (j - 2 * cent->y)) <= limit)
				my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}

int	render_next_frame(t_all_data *all)
{
	int		color;
	mlx_image_t	*my_img;

	my_img = (mlx_image_t *)all->img->img;
	color = 0x00F00FFF;
	ft_bzero(all->img->addr, (my_img->width + 32) * my_img->height * 4);
	put_circle(all->img, all->pos, 50, color);
	mlx_image_to_window(all->vars->mlx, all->img->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data		img;
	t_vars		vars;
	t_pos		*pos;
	t_all_data	all;

	vars.mlx = mlx_init(1920, 1080," bcanals- pipex", 1);
	//mlx_do_key_autorepeaton(vars.mlx);
	pos = get_pos(500, 500);
	img.img = mlx_new_image(vars.mlx, 1000, 1000);
	//img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	all.img = &img;
	all.pos = pos;
	all.vars = &vars;
	// ft_printf("address in main: %p\n", all);
	mlx_key_hook(vars.win, hook, &all);
	// mlx_hook(vars.win, 2, 1L<<0, my_close, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &all);
	mlx_loop(vars.mlx);
}
