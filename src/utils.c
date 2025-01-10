/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:10:54 by bcanals-          #+#    #+#             */
/*   Updated: 2025/01/10 17:39:38 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, uint32_t color)
{
	uint8_t	*dst;

	if (x > 1 && y > 1)
	{
		dst = &img->pixels[(y * img->width + x) * BPP];
		*(uint32_t *)dst = color;
	}
}

t_xyz	*get_xyz(int x, int y, int z, t_xyz *next_x)
{
	t_xyz	*rtrn;

	rtrn = malloc(sizeof(t_xyz));
	if (!rtrn)
		return (NULL);
	rtrn->x = x;
	rtrn->y = y;
	rtrn->z = z;
	rtrn->n_x = next_x;
	rtrn->n_y = NULL;
	return (rtrn);
}

void	hook(mlx_key_data_t keycode, void *void_prog)
{
	t_prog	*prog;

	prog = void_prog;
	if (keycode.key == MLX_KEY_ESCAPE)
		mlx_close_window(prog->mlx);
}

t_limits	*init_limits(void)
{
	t_limits	*limits;

	limits = ft_calloc(1, sizeof(t_limits));
	if (!limits)
		return (NULL);
	limits->min_x = INT_MAX;
	limits->min_y = INT_MAX;
	limits->max_x = INT_MIN;
	limits->max_y = INT_MIN;
	return (limits);
}

void	normalize_proj(t_xyz *net, t_limits *limits)
{
	t_xyz	*ini_y;

	while (net)
	{
		ini_y = net;
		while (net)
		{
			net->proj_x -= limits->min_x;
			net->proj_y -= limits->min_y;
			net = net->n_x;
		}
		ini_y = ini_y->n_y;
		net = ini_y;
	}
}
