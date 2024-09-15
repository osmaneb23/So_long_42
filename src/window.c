/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:04:20 by obouayed          #+#    #+#             */
/*   Updated: 2024/07/15 21:48:33 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to redisplay the image in the window when needed (resize, etc)
int	redisplay_window(t_data *data)
{
	display_textures(&data);
	return (0);
}

/*
Function to handle the keys:
- If the key pressed is the escape key
  -Close the window and free the allocated memory
- If the key pressed is the 'w' key
  -Move the player up
- If the key pressed is the 'a' key
  -Move the player left
- If the key pressed is the 's' key
  -Move the player down
- If the key pressed is the 'd' key
  -Move the player right
*/
int	handle_keys(int keysym, t_data *data)
{
	int	w_key;
	int	a_key;
	int	s_key;
	int	d_key;

	w_key = 119;
	a_key = 97;
	s_key = 115;
	d_key = 100;
	if (keysym == XK_Escape)
		cleanup(&data, 0, NULL);
	if (keysym == w_key)
		move_player_up(&data);
	if (keysym == a_key)
		move_player_left(&data);
	if (keysym == s_key)
		move_player_down(&data);
	if (keysym == d_key)
		move_player_right(&data);
	return (0);
}

// Function to close the window by pressing the cross button
int	close_windows_cross(t_data *data)
{
	cleanup(&data, 0, NULL);
	return (0);
}

/*
Function that initializes the window:
- Initializes the connection with the X server
and returns a pointer to the connection
- Creates a window of width*height pixels with
a title and returns a pointer to the window
- Creates a new image of width*height pixels
and returns a pointer to the image
- Retrieves the address of the image and its
information and returns a pointer to the pointer
- Handles the close window event
- Handles the key press event
- Handles the redisplay window event
*/
void	init_window(t_data **data, int width, int height)
{
	(*data)->mlx = mlx_init();
	if (!(*data)->mlx)
		cleanup(data, 1, "Error\nConnection with X server failed\n");
	(*data)->win = mlx_new_window((*data)->mlx, width, height,
			"The Culling Game");
	if (!(*data)->win)
		cleanup(data, 1, "Error\nWindow not created\n");
	mlx_hook((*data)->win, DestroyNotify, StructureNotifyMask,
		close_windows_cross, *data);
	mlx_hook((*data)->win, KeyPress, KeyPressMask, handle_keys, *data);
	mlx_hook((*data)->win, Expose, ExposureMask, redisplay_window, *data);
	(*data)->img.ptr = mlx_new_image((*data)->mlx, width, height);
	if (!(*data)->img.ptr)
		cleanup(data, 1, "Error\nImage not created\n");
	(*data)->img.addr = mlx_get_data_addr((*data)->img.ptr,
			&((*data)->img.bits_per_pixel), &((*data)->img.size_line),
			&((*data)->img.endian));
	if (!(*data)->img.addr)
		cleanup(data, 1, "Error\nImage address not found\n");
}
