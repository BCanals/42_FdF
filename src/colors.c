/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:40:56 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/14 21:14:07 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	add_shade(double dist, int color)
{
	int i;

	if (dist < 0)
		dist = 0;
	if (dist > 1)
		dist = 1;
	i = 0;
	while (i < 3)
		((unsigned char *)&color)[i++] *= (1 - dist);
	return (color);
}

int get_opposite(int color)
{
	return (color ^= 0x00FFFFFF);
}
