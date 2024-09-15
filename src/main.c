/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:23:56 by obouayed          #+#    #+#             */
/*   Updated: 2024/09/15 14:16:48 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to check if the map file has a .ber extension
void	check_map_extension(char *filename, t_data **data)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 4] != '.' || filename[i - 3] != 'b' || filename[i
			- 2] != 'e' || filename[i - 1] != 'r')
		cleanup(data, EXIT_FAILURE,
			"Error\nMap file must have a .ber extension\n");
}

// Function to display the necessary image
void	display_image(t_data **data, int i, int j)
{
	int	x;
	int	y;

	x = j * (*data)->map.tile_size;
	y = i * (*data)->map.tile_size;
	if ((*data)->map.array[i][j] == '1')
		mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img.wall,
			x, y);
	else if ((*data)->map.array[i][j] == '0')
		mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img.floor,
			x, y);
	else if ((*data)->map.array[i][j] == 'C')
		mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img.coin,
			x, y);
	else if ((*data)->map.array[i][j] == 'E')
		mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img.exit,
			x, y);
	else if ((*data)->map.array[i][j] == 'P')
		mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img.player,
			x, y);
}

// Function to display the textures in the window at their respective positions
void	display_textures(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	while ((*data)->map.array[i])
	{
		j = 0;
		while ((*data)->map.array[i][j])
		{
			display_image(data, i, j);
			j++;
		}
		i++;
	}
	display_nbr_moves(data);
}

// Function to initialize all the data to NULL
void	init_data(t_data **data)
{
	(*data)->mlx = NULL;
	(*data)->win = NULL;
	(*data)->img.ptr = NULL;
	(*data)->img.addr = NULL;
	(*data)->img.player = NULL;
	(*data)->img.wall = NULL;
	(*data)->img.floor = NULL;
	(*data)->img.coin = NULL;
	(*data)->img.exit = NULL;
	(*data)->img.bits_per_pixel = 0;
	(*data)->img.size_line = 0;
	(*data)->img.endian = 0;
	(*data)->map.array = NULL;
	(*data)->map.width = 0;
	(*data)->map.height = 0;
	(*data)->map.tile_size = 0;
	(*data)->map.nbr_coins = 0;
	(*data)->player.x = 0;
	(*data)->player.y = 0;
	(*data)->player.find_exit = 0;
	(*data)->player.nbr_moves = 0;
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		fd;

	if (ac != 2)
		cleanup(NULL, 1, "Error\nInvalid number of arguments\n");
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		cleanup(NULL, 1, "Error\nMemory allocation failed\n");
	init_data(&data);
	init_map(&data, av);
	init_window(&data, data->map.width, data->map.height);
	init_textures(&data);
	display_textures(&data);
	mlx_loop(data->mlx);
	cleanup(&data, 0, NULL);
	return (EXIT_SUCCESS);
}
