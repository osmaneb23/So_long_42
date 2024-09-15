/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 01:28:10 by obouayed          #+#    #+#             */
/*   Updated: 2024/07/12 07:51:43 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to assign the player position in the data (x, y)
void	assign_player_position(t_data **data)
{
	int	i;
	int	j;

	i = 1;
	while ((*data)->map.array[i])
	{
		j = 1;
		while ((*data)->map.array[i][j])
		{
			if ((*data)->map.array[i][j] == PLAYER)
			{
				(*data)->player.x = i;
				(*data)->player.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

/*
Function using the floodfill algorithm to check if the player can reach the exit:
- Recursively check in all directions if the player can move
- If the player can move, assign a new value to the position:
	-'G' if it's a floor
	-'V' if it's a coin
	-'X' if it's the exit
	(It will be reset to its original value after the check)
- If the player can't move, return
*/
void	floodfill(t_data **data, int x, int y)
{
	if ((*data)->map.array[x][y] == WALL || x <= 0 || y <= 0
		|| x >= (*data)->map.height || y >= (*data)->map.width
		|| (*data)->map.array[x][y] == 'V' || (*data)->map.array[x][y] == 'X'
		|| (*data)->map.array[x][y] == 'G')
		return ;
	if ((*data)->map.array[x][y] == MAP_EXIT)
	{
		(*data)->map.array[x][y] = 'X';
		(*data)->player.find_exit = 1;
	}
	else if ((*data)->map.array[x][y] == COIN)
	{
		(*data)->map.array[x][y] = 'V';
		(*data)->map.nbr_coins--;
	}
	else
		(*data)->map.array[x][y] = 'G';
	floodfill(data, x + 1, y);
	floodfill(data, x - 1, y);
	floodfill(data, x, y + 1);
	floodfill(data, x, y - 1);
}

// Function to reset the map to its original state
void	reset_map(t_data **data, int player_x, int player_y)
{
	int	i;
	int	j;

	i = 1;
	while ((*data)->map.array[i])
	{
		j = 1;
		while ((*data)->map.array[i][j])
		{
			if ((*data)->map.array[i][j] == 'V')
				(*data)->map.array[i][j] = COIN;
			if ((*data)->map.array[i][j] == 'G')
				(*data)->map.array[i][j] = FLOOR;
			if ((*data)->map.array[i][j] == 'X')
				(*data)->map.array[i][j] = MAP_EXIT;
			j++;
		}
		i++;
	}
	(*data)->map.array[player_x][player_y] = PLAYER;
}

// Function to check if the player can reach the exit and all the coins
void	parsing_floodfill(t_data **data)
{
	int	x;
	int	y;
	int	nbr_coins;

	nbr_coins = (*data)->map.nbr_coins;
	assign_player_position(data);
	x = (*data)->player.x;
	y = (*data)->player.y;
	floodfill(data, (*data)->player.x, (*data)->player.y);
	reset_map(data, x, y);
	if (!(*data)->player.find_exit)
		cleanup(data, EXIT_FAILURE, "Error\nThe player can't reach the exit\n");
	if ((*data)->map.nbr_coins != 0)
		cleanup(data, EXIT_FAILURE,
			"Error\nThe player can't reach all the coins\n");
	(*data)->map.nbr_coins = nbr_coins;
}
