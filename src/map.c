/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:23:13 by obouayed          #+#    #+#             */
/*   Updated: 2024/09/15 14:16:59 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
Function to check if the map is valid:
- Check if the map is rectangular
- Check if the map is not too small
- Check if the map contains only valid characters
- Check if the map contains only one player
- Check if the map contains only one exit
- Check if the map contains at least one coin
- Check if the map is surrounded by walls
- Check if the player can reach all the coins and the exit
*/
void	check_map_format(t_data **data, int tile_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(*data)->map.array[i])
		cleanup(data, EXIT_FAILURE, "Error\nMap is empty\n");
	while ((*data)->map.array[i])
	{
		if (ft_strlen((*data)->map.array[i]) * tile_size != (*data)->map.width)
			cleanup(data, EXIT_FAILURE, "Error\nMap is not rectangular\n");
		i++;
	}
	while ((*data)->map.array[0][j])
		j++;
	if (i * j < 15)
		cleanup(data, EXIT_FAILURE, "Error\nMap is too small\n");
	check_valid_content(data);
	check_player(data);
	check_exit(data);
	check_coins(data);
	parsing_floodfill(data);
}

// Function to decide the size of the tiles
int	return_tile_size(float len)
{
	int	tile_size;

	if (len <= 40)
		tile_size = 128;
	else if (len <= 80)
		tile_size = 64;
	else if (len <= 160)
		tile_size = 32;
	else
		tile_size = 16;
	return (tile_size);
}

// Function to create the size of the tiles based on the length of the map
int	create_tile_size(t_data *data, char **av)
{
	int		fd;
	char	*line;
	float	len;

	check_map_extension(av[1], &data);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		cleanup(&data, EXIT_FAILURE, "Error\nMap file not found\n");
	line = get_next_line(fd);
	if (!line)
		cleanup(&data, EXIT_FAILURE, "Error\nMap is empty\n");
	len = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		len = len + 1.5;
	}
	free(line);
	close(fd);
	return (return_tile_size(len));
}

/*
Function to return the number of lines in the map:
- Open the map file
- Read the first line
- Initialize the width of the map
(Width = length of the first line * tile_size)
- Count the number of lines in the map
- Initialize the height of the map
(Height = number of lines * tile_size)
- Close the file
- Return the number of lines
*/
int	return_len_line_and_init_mapsize(t_data **data, char **av)
{
	int		i;
	int		fd;
	char	*line;

	(*data)->map.tile_size = create_tile_size(*data, av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		cleanup(data, EXIT_FAILURE, "Error\nMap file not found\n");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (i == 0)
			(*data)->map.width = ft_strlen(line) * (*data)->map.tile_size;
		free(line);
		i++;
		line = get_next_line(fd);
	}
	(*data)->map.height = i * (*data)->map.tile_size;
	close(fd);
	return (i);
}

/*
Function to initialize the map:
- Get the number of lines in the map
- Open the map file
- Allocate memory for the map
- Read the map line by line and store it
in the map array
- Add a NULL pointer at the end of the map array
- Check the map for errors
- Close the file
*/
void	init_map(t_data **data, char **av)
{
	int		i;
	int		fd;
	char	*line;

	i = return_len_line_and_init_mapsize(data, av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		cleanup(data, EXIT_FAILURE, "Error\nMap file not found\n");
	(*data)->map.array = malloc(sizeof(char *) * (i + 1));
	if (!(*data)->map.array)
	{
		close(fd);
		cleanup(data, EXIT_FAILURE, "Error\nMalloc failed\n");
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		(*data)->map.array[i] = line;
		line = get_next_line(fd);
		i++;
	}
	(*data)->map.array[i] = NULL;
	check_map_format(data, (*data)->map.tile_size);
	close(fd);
}
