/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:21:44 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/29 22:49:01 by bizcru           ###   ########.fr       */
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

typedef struct s_xy t_xy;
typedef struct s_xyz t_xyz;

typedef struct s_xy
{
	union {
		int		pos[2];
		struct {
			int x;
			int y;
		};
	};
	t_xy	*n_x;
	t_xy	*n_y;
}		t_xy;

typedef struct s_xyz
{
	union {
		int		pos[3];
		struct {
			int	x;
			int	y;
			int	z;
		};
	};
	t_xyz	*n_x;
	t_xyz	*n_y;
}		t_xyz;

typedef struct s_3d
{
	t_xyz	*first;
	int		*x_size;
	int		*y_size;
}			t_3d;

typedef struct s_program
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_xy		*offset;
	t_xy		*net_2d;
	t_3d		*net_3d;
	bool		update;
}			t_prog;

void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, uint32_t color);
void	put_rectangle(mlx_image_t *img, t_xy *pos, t_xy *size, uint32_t color);
void	put_circle(mlx_image_t *img, t_xy *cent, int radius, uint32_t color);
t_xy	*get_xy(int x, int y, t_xy *next_x);
t_xyz	*get_xyz(int x, int y, int z, t_xyz *next_x);
int		add_shade(double dist, int color);
int		get_opposite(int color);
int		my_close(t_prog *prog);
void	hook(mlx_key_data_t keycode, void *void_all);

#endif
