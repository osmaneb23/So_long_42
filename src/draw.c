/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:04:00 by obouayed          #+#    #+#             */
/*   Updated: 2024/07/12 07:03:32 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
Function to draw a pixel:
- Calculate the pixel offset
- Calculate the pixel address
- Change the color of the pixel
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		pixel_offset;

	pixel_offset = (y * data->img.size_line + x * (data->img.bits_per_pixel
				/ 8));
	dst = data->img.addr + pixel_offset;
	*(unsigned int *)dst = color;
}

// Function to color the entire image
void	color_whole_image(t_data *data, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x <= data->map.width)
	{
		y = 0;
		while (y <= data->map.height)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}

// Function to draw a square
void	draw_square(t_data *data, int color)
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	backup_height;

	width = data->map.width / 10;
	backup_height = data->map.height;
	x = data->player.x * 10;
	while (width)
	{
		y = data->player.y * 10;
		height = backup_height / 10;
		while (height)
		{
			my_mlx_pixel_put(data, x, y, color);
			height--;
			y++;
		}
		width--;
		x++;
	}
}
