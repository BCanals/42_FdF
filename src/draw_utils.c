/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:10:54 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/19 12:16:00 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, uint32_t color)
{
	uint8_t	*dst;
	
	//printf("x,i: %i,%i ; w-h: %i,%i\n", x, y, img->width, img->height);
	if (x < img->width && y < img->height && x > 1 && y > 1)
	{
		dst = &img->pixels[(y * img->width + x) * BPP];
		//printf("dest %p = %x\n", dst, *dst);
		*(uint32_t *)dst = color;
		//printf("now  %p = %x\n", dst, *(uint32_t *)dst);
	}
}

void	put_rectangle(mlx_image_t *img, t_xy pos, t_xy size, uint32_t color)
{
	int	i;
	int	j;

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

void	put_circle(mlx_image_t *img, t_xy *cent, int radius, uint32_t color)
{
	int	i;
	int	j;
	int	top_i;
	int	top_j;
	int	limit;

	limit = radius * radius - cent->x * cent->x - cent->y * cent->y;
	top_i = cent->x + radius;
	top_j = cent->y + radius;
	//printf("top_j: %i", top_j);
	i = cent->x - radius;
	while (i <= top_i)
	{
			j = cent->y - radius;
			while (j <= top_j)
			{	
				//printf("i: %i, j: %i\n", i, j);
				if ((i * (i - 2 * cent->x) + j * (j - 2 * cent->y)) <= limit)
					my_mlx_pixel_put(img, i, j, color);
					//mlx_put_pixel(img, i, j, color);
				j++;
			}
		i++;
	}
}
