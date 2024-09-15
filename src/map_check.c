/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:12:37 by obouayed          #+#    #+#             */
/*   Updated: 2024/07/02 02:43:50 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to check if the map contains at least one coin
void	check_coins(t_data **data)
{
	int	i;
	int	j;
	int	coins;

	i = 0;
	coins = 0;
	while ((*data)->map.array[i])
	{
		j = 0;
		while ((*data)->map.array[i][j])
		{
			if ((*data)->map.array[i][j] == COIN)
				coins++;
			j++;
		}
		i++;
	}
	if (!coins)
		cleanup(data, EXIT_FAILURE, "Error\nNo coins\n");
	else
		(*data)->map.nbr_coins = coins;
}

// Function to check if the map contains only one exit
void	check_exit(t_data **data)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while ((*data)->map.array[i])
	{
		j = 0;
		while ((*data)->map.array[i][j])
		{
			if ((*data)->map.array[i][j] == MAP_EXIT)
			{
				if (!exit)
					exit++;
				else
					cleanup(data, EXIT_FAILURE, "Error\nMultiple exits\n");
			}
			j++;
		}
		i++;
	}
	if (!exit)
		cleanup(data, EXIT_FAILURE, "Error\nNo exit\n");
}

// Function to check if the map contains only one player
void	check_player(t_data **data)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while ((*data)->map.array[i])
	{
		j = 0;
		while ((*data)->map.array[i][j])
		{
			if ((*data)->map.array[i][j] == PLAYER)
			{
				if (!player)
					player++;
				else
					cleanup(data, EXIT_FAILURE, "Error\nMultiple players\n");
			}
			j++;
		}
		i++;
	}
	if (!player)
		cleanup(data, EXIT_FAILURE, "Error\nNo player\n");
}

// Function to check if the map is surrounded by walls
void	check_if_map_is_surrounded(t_data **data)
{
	int	i;
	int	j;

	j = ft_strlen((*data)->map.array[0]);
	i = 0;
	while ((*data)->map.array[i])
	{
		if ((*data)->map.array[i][0] != WALL || (*data)->map.array[i][j
			- 1] != WALL)
			cleanup(data, EXIT_FAILURE,
				"Error\nMap is not surrounded by walls\n");
		i++;
	}
	j = 0;
	while ((*data)->map.array[i - 1][j])
	{
		if ((*data)->map.array[i - 1][j++] != WALL)
			cleanup(data, EXIT_FAILURE,
				"Error\nMap is not surrounded by walls\n");
	}
}

// Function to check if the map have valid content
void	check_valid_content(t_data **data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while ((*data)->map.array[i])
	{
		j = 0;
		while ((*data)->map.array[i][j])
		{
			if ((*data)->map.array[i][j] != WALL && i == 0)
				cleanup(data, EXIT_FAILURE,
					"Error\nMap is not surrounded by walls\n");
			c = (*data)->map.array[i][j++];
			if (c != WALL && c != COIN && c != PLAYER && c != FLOOR
				&& c != MAP_EXIT)
				cleanup(data, EXIT_FAILURE,
					"Error\nInvalid character in the map\n");
		}
		i++;
	}
	check_if_map_is_surrounded(data);
}
