//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:05:01 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/17 21:36:50 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(mlx_image_t *img, unsigned int x, unsigned int y, uint32_t color)
{
	uint8_t	*dst;
	
	//printf("x,i: %i,%i ; w-h: %i,%i\n", x, y, img->width, img->height);
	if (x < img->width && y < img->height && x > 0 && y > 0)
	{
		dst = &img->pixels[(y * img->width + x) * BPP];
		//printf("dest %p = %x\n", dst, *dst);
		*(uint32_t *)dst = color;
		//printf("now  %p = %x\n", dst, *(uint32_t *)dst);
	}

	getchar();
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

void	put_rectangle(mlx_image_t *img, t_pos pos, t_pos size, int color)
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

void	put_circle(mlx_image_t *img, t_pos *cent, int radius, int color)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	top_i;
	unsigned int	top_j;
	unsigned int	limit;

	limit = radius * radius - cent->x * cent->x - cent->y * cent->y;
	top_i = cent->x + radius;
	top_j = cent->y + radius;
	//printf("top_j: %i", top_j);
	i = cent->x - radius;
	while (i <= top_i)
	{
		if (x > 0)
		{
			j = cent->y - radius;
			while (j <= top_j)
			{	
				//printf("i: %i, j: %i\n", i, j);
				if ((i * (i - 2 * cent->x) + j * (j - 2 * cent->y)) >= limit)
					my_mlx_pixel_put(img, i, j, color);
					//mlx_put_pixel(img, i, j, color);
				j++;
			}
		}
		i++;
	}
}

void	render_next_frame(void *void_prog)
{
	uint32_t	color;
	t_prog 		*prog;

	prog = void_prog;
	color = 0xFF00FFFF;
	ft_bzero(prog->img->pixels, prog->img->width * prog->img->height * sizeof(int32_t));
	put_circle(prog->img, prog->pos, 50, color);
	mlx_image_to_window(prog->mlx, prog->img, 0, 0);
	//getchar();
	return ;
}
/*
int	main(void)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(256, 256, "bcanals- pipex", true);
	if (!mlx)
		perror("no mlx");
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		perror("no image");
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}*/

int	main(void)
{
	t_prog	prog;

	//printf("BPP: %li\n", BPP);
	prog.mlx = mlx_init(700, 700, "bcanals- pipex", true);
	prog.pos = get_pos(100, 100);
	prog.img = mlx_new_image(prog.mlx, 256, 256);
	mlx_image_to_window(prog.mlx, prog.img, 0,0);
	// ft_printf("address in main: %p\n", all);
	mlx_key_hook(prog.mlx, hook, &prog);
	mlx_loop_hook(prog.mlx, *render_next_frame, &prog);
	mlx_loop(prog.mlx);
	mlx_terminate(prog.mlx);
}
