/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:21:44 by bcanals-          #+#    #+#             */
/*   Updated: 2025/01/10 17:35:35 by bcanals-         ###   ########.fr       */
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

typedef struct s_xyz	t_xyz;

typedef struct s_xyz
{
	int		x;
	int		y;
	int		z;
	t_xyz	*n_x;
	t_xyz	*n_y;
	int		proj_x;
	int		proj_y;
}		t_xyz;

typedef struct s_limits
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
}			t_limits;

typedef struct s_program
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_xyz		*net;
}			t_prog;

void		my_mlx_pixel_put(mlx_image_t *img, int x, int y, uint32_t color);
t_xyz		*get_xyz(int x, int y, int z, t_xyz *next_x);
int			add_shade(double dist, int color);
int			get_opposite(int color);
int			my_close(t_prog *prog);
int			split_count(char **split);
void		hook(mlx_key_data_t keycode, void *void_all);
t_limits	*load_map(t_prog *prog, char *path);
int			points_clean_up(t_xyz *start);
void		load_c(int c[2], int size);
t_limits	*init_limits(void);
void		normalize_proj(t_xyz *net, t_limits *limits);
void		update_limits(t_xyz *p, t_limits *l);

#endif
