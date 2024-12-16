/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:21:44 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/16 20:02:20 by bcanals-         ###   ########.fr       */
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
}		t_pos;

typedef struct s_all_data
{
	t_data	*img;
	t_pos	*pos;
	t_vars	*vars;
}			t_all_data;

int	add_shade(double dist, int color);
int	get_opposite(int color);
int my_close(t_vars *vars);
int	hook(int keycode, t_all_data *all);

#endif

