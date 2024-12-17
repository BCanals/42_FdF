/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:21:44 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/17 19:27:46 by bizcru           ###   ########.fr       */
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

typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
}		t_pos;

typedef struct s_program
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_pos		*pos;
}			t_prog;

int		add_shade(double dist, int color);
int		get_opposite(int color);
int		my_close(t_prog *prog);
void	hook(mlx_key_data_t keycode, void *void_all);

#endif

