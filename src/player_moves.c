/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:05:18 by obouayed          #+#    #+#             */
/*   Updated: 2024/07/15 23:31:36 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to move the player up
void	move_player_up(t_data **data)
{
	int	x;
	int	y;

	x = (*data)->player.x;
	y = (*data)->player.y;
	if ((*data)->map.array[x - 1][y] == MAP_EXIT && (*data)->map.nbr_coins == 0)
		cleanup(data, EXIT_SUCCESS, "You won!\n");
	if ((*data)->map.array[x - 1][y] == WALL || (*data)->map.array[x
		- 1][y] == MAP_EXIT)
		return ;
	if ((*data)->map.array[x - 1][y] == FLOOR)
	{
		(*data)->map.array[x][y] = FLOOR;
		(*data)->map.array[x - 1][y] = PLAYER;
		(*data)->player.x -= 1;
	}
	if ((*data)->map.array[x - 1][y] == COIN)
	{
		(*data)->map.array[x][y] = FLOOR;
		(*data)->map.array[x - 1][y] = PLAYER;
		(*data)->player.x -= 1;
		(*data)->map.nbr_coins--;
	}
	(*data)->player.nbr_moves++;
	display_textures(data);
}

// Function to move the player to the left
void	move_player_left(t_data **data)
{
	int	x;
	int	y;

	x = (*data)->player.x;
	y = (*data)->player.y;
	if ((*data)->map.array[x][y - 1] == MAP_EXIT && (*data)->map.nbr_coins == 0)
		cleanup(data, EXIT_SUCCESS, "You won!\n");
	if ((*data)->map.array[x][y - 1] == WALL || (*data)->map.array[x][y
		- 1] == MAP_EXIT)
		return ;
	if ((*data)->map.array[x][y - 1] == FLOOR)
	{
		(*data)->map.array[x][y] = FLOOR;
		(*data)->map.array[x][y - 1] = PLAYER;
		(*data)->player.y -= 1;
	}
	if ((*data)->map.array[x][y - 1] == COIN)
	{
		(*data)->map.array[x][y] = FLOOR;
		(*data)->map.array[x][y - 1] = PLAYER;
		(*data)->player.y -= 1;
		(*data)->map.nbr_coins--;
	}
	(*data)->player.nbr_moves++;
	display_textures(data);
}

// Function to move the player to the right
void	move_player_right(t_data **data)
{
	int	x;
	int	y;

	x = (*data)->player.x;
	y = (*data)->player.y;
	if ((*data)->map.array[x][y + 1] == MAP_EXIT && (*data)->map.nbr_coins == 0)
		cleanup(data, EXIT_SUCCESS, "You won!\n");
	if ((*data)->map.array[x][y + 1] == WALL || (*data)->map.array[x][y
		+ 1] == MAP_EXIT)
		return ;
	if ((*data)->map.array[x][y + 1] == FLOOR)
	{
		(*data)->map.array[x][y] = FLOOR;
		(*data)->map.array[x][y + 1] = PLAYER;
		(*data)->player.y += 1;
	}
	if ((*data)->map.array[x][y + 1] == COIN)
	{
		(*data)->map.array[x][y] = FLOOR;
		(*data)->map.array[x][y + 1] = PLAYER;
		(*data)->player.y += 1;
		(*data)->map.nbr_coins--;
	}
	(*data)->player.nbr_moves++;
	display_textures(data);
}

// Function to move the player down
void	move_player_down(t_data **data)
{
	int	x;
	int	y;

	x = (*data)->player.x;
	y = (*data)->player.y;
	if ((*data)->map.array[x + 1][y] == MAP_EXIT && (*data)->map.nbr_coins == 0)
		cleanup(data, EXIT_SUCCESS, "You won!\n");
	if ((*data)->map.array[x + 1][y] == WALL || (*data)->map.array[x
		+ 1][y] == MAP_EXIT)
		return ;
	if ((*data)->map.array[x + 1][y] == FLOOR)
	{
		(*data)->map.array[x][y] = FLOOR;
		(*data)->map.array[x + 1][y] = PLAYER;
		(*data)->player.x += 1;
	}
	if ((*data)->map.array[x + 1][y] == COIN)
	{
		(*data)->map.array[x][y] = FLOOR;
		(*data)->map.array[x + 1][y] = PLAYER;
		(*data)->player.x += 1;
		(*data)->map.nbr_coins--;
	}
	(*data)->player.nbr_moves++;
	display_textures(data);
}

// Function to print the number of moves made by the player on the screen
void	display_nbr_moves(t_data **data)
{
	char	*nbr_moves;
	char	*message;

	nbr_moves = ft_itoa((*data)->player.nbr_moves);
	message = ft_strjoin("Number of Gojo's movements: ", nbr_moves);
	mlx_string_put((*data)->mlx, (*data)->win, 10, 10, 0x00FFFFFF, message);
	mlx_string_put((*data)->mlx, (*data)->win, 10, 30, 0x00FFFFFF,
		"Press 'ESC' to exit");
	free(nbr_moves);
	free(message);
}
