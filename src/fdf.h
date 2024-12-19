/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:21:44 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/19 12:15:11 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/MLX42/include/MLX42/MLX42_Int.h"
# include "../libs/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <sys/types.h>

typedef struct s_xy
{
	int	x;
	int	y;
	int	*n_x;
	int	*n_y;
}		t_xy;

typedef struct s_xyz
{
	int	x;
	int y;
	int	z;
	int	*n_x;
	int	*n_y;
}		t_xyz;

typedef struct s_3d
{
	t_xyz	*first;
	int		*x_size;
	int		*y_size;
}

typedef struct s_program
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_xy		*offset;
	t_xy		*2d_net;
	t_3d		*3d_net;
}			t_prog;

void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, uint32_t color);
void	put_rectangle(mlx_t *img, t_xy pos, t_xy size, uint32_t color);
void	put_circle(mlx_t *img, t_xy *cent, int radius, uint32_t color);
int		add_shade(double dist, int color);
int		get_opposite(int color);
int		my_close(t_prog *prog);
void	hook(mlx_key_data_t keycode, void *void_all);

#endif
