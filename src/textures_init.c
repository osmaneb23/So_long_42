/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 03:47:50 by obouayed          #+#    #+#             */
/*   Updated: 2024/07/11 03:08:20 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to initialize the 16x16 textures
void	init_textures_16(t_data **data)
{
	int	texture_height;
	int	texture_width;

	(*data)->img.player = mlx_xpm_file_to_image((*data)->mlx,
			"textures/Gojo16x16.xpm", &texture_width, &texture_height);
	if (!(*data)->img.player)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load player texture\n");
	(*data)->img.wall = mlx_xpm_file_to_image((*data)->mlx,
			"textures/wall16x16.xpm", &texture_width, &texture_height);
	if (!(*data)->img.wall)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load wall texture\n");
	(*data)->img.floor = mlx_xpm_file_to_image((*data)->mlx,
			"textures/floor16x16.xpm", &texture_width, &texture_height);
	if (!(*data)->img.floor)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load floor texture\n");
	(*data)->img.coin = mlx_xpm_file_to_image((*data)->mlx,
			"textures/coin16x16.xpm", &texture_width, &texture_height);
	if (!(*data)->img.coin)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load coin texture\n");
	(*data)->img.exit = mlx_xpm_file_to_image((*data)->mlx,
			"textures/exit16x16.xpm", &texture_width, &texture_height);
	if (!(*data)->img.exit)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load exit texture\n");
}

// Function to initialize the textures with the 32x32 textures
void	init_textures_32(t_data **data)
{
	int	texture_height;
	int	texture_width;

	(*data)->img.player = mlx_xpm_file_to_image((*data)->mlx,
			"textures/Gojo32x32.xpm", &texture_width, &texture_height);
	if (!(*data)->img.player)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load player texture\n");
	(*data)->img.wall = mlx_xpm_file_to_image((*data)->mlx,
			"textures/wall32x32.xpm", &texture_width, &texture_height);
	if (!(*data)->img.wall)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load wall texture\n");
	(*data)->img.floor = mlx_xpm_file_to_image((*data)->mlx,
			"textures/floor32x32.xpm", &texture_width, &texture_height);
	if (!(*data)->img.floor)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load floor texture\n");
	(*data)->img.coin = mlx_xpm_file_to_image((*data)->mlx,
			"textures/coin32x32.xpm", &texture_width, &texture_height);
	if (!(*data)->img.coin)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load coin texture\n");
	(*data)->img.exit = mlx_xpm_file_to_image((*data)->mlx,
			"textures/exit32x32.xpm", &texture_width, &texture_height);
	if (!(*data)->img.exit)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load exit texture\n");
}

// Function to initialize the textures according to the tile size
void	init_textures_64(t_data **data)
{
	int	texture_height;
	int	texture_width;

	(*data)->img.player = mlx_xpm_file_to_image((*data)->mlx,
			"textures/Gojo64x64.xpm", &texture_width, &texture_height);
	if (!(*data)->img.player)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load player texture\n");
	(*data)->img.wall = mlx_xpm_file_to_image((*data)->mlx,
			"textures/wall64x64.xpm", &texture_width, &texture_height);
	if (!(*data)->img.wall)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load wall texture\n");
	(*data)->img.floor = mlx_xpm_file_to_image((*data)->mlx,
			"textures/floor64x64.xpm", &texture_width, &texture_height);
	if (!(*data)->img.floor)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load floor texture\n");
	(*data)->img.coin = mlx_xpm_file_to_image((*data)->mlx,
			"textures/coin64x64.xpm", &texture_width, &texture_height);
	if (!(*data)->img.coin)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load coin texture\n");
	(*data)->img.exit = mlx_xpm_file_to_image((*data)->mlx,
			"textures/exit64x64.xpm", &texture_width, &texture_height);
	if (!(*data)->img.exit)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load exit texture\n");
}

// Function to initialize the textures with the 128x128 textures
void	init_textures_128(t_data **data)
{
	int	texture_height;
	int	texture_width;

	(*data)->img.player = mlx_xpm_file_to_image((*data)->mlx,
			"textures/Gojo128x128.xpm", &texture_width, &texture_height);
	if (!(*data)->img.player)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load player texture\n");
	(*data)->img.wall = mlx_xpm_file_to_image((*data)->mlx,
			"textures/wall128x128.xpm", &texture_width, &texture_height);
	if (!(*data)->img.wall)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load wall texture\n");
	(*data)->img.floor = mlx_xpm_file_to_image((*data)->mlx,
			"textures/floor128x128.xpm", &texture_width, &texture_height);
	if (!(*data)->img.floor)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load floor texture\n");
	(*data)->img.coin = mlx_xpm_file_to_image((*data)->mlx,
			"textures/coin128x128.xpm", &texture_width, &texture_height);
	if (!(*data)->img.coin)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load coin texture\n");
	(*data)->img.exit = mlx_xpm_file_to_image((*data)->mlx,
			"textures/exit128x128.xpm", &texture_width, &texture_height);
	if (!(*data)->img.exit)
		cleanup(data, EXIT_FAILURE, "Error\nFailed to load exit texture\n");
}

/* 
Function to initialize the textures according to the tile size:
- If the tile size is 16:
	-Initialize the textures with the 16x16 textures
- If the tile size is 32:
	-Initialize the textures with the 32x32 textures
- If the tile size is 64:
	-Initialize the textures with the 64x64 textures
- If the tile size is 128:
	-Initialize the textures with the 128x128 textures
*/
void	init_textures(t_data **data)
{
	if ((*data)->map.tile_size == 16)
		init_textures_16(data);
	else if ((*data)->map.tile_size == 32)
		init_textures_32(data);
	else if ((*data)->map.tile_size == 64)
		init_textures_64(data);
	else if ((*data)->map.tile_size == 128)
		init_textures_128(data);
}
