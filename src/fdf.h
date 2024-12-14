/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:21:44 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/14 21:59:42 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
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
	int	x;
	int	y;
}		t_pos;

int	add_shade(double dist, int color);
int	get_opposite(int color);
int my_close(t_vars *vars);

#endif

