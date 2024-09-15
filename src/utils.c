/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:04:18 by obouayed          #+#    #+#             */
/*   Updated: 2024/07/12 07:48:58 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to clean up images
void	clean_images(t_data **data)
{
	if ((*data)->img.player)
		mlx_destroy_image((*data)->mlx, (*data)->img.player);
	if ((*data)->img.wall)
		mlx_destroy_image((*data)->mlx, (*data)->img.wall);
	if ((*data)->img.floor)
		mlx_destroy_image((*data)->mlx, (*data)->img.floor);
	if ((*data)->img.coin)
		mlx_destroy_image((*data)->mlx, (*data)->img.coin);
	if ((*data)->img.exit)
		mlx_destroy_image((*data)->mlx, (*data)->img.exit);
	if ((*data)->img.ptr)
		mlx_destroy_image((*data)->mlx, (*data)->img.ptr);
}

// Function to clean up data
void	clean_data(t_data **data)
{
	int	i;

	i = 0;
	clean_images(data);
	if ((*data)->win)
		mlx_destroy_window((*data)->mlx, (*data)->win);
	if ((*data)->mlx)
	{
		mlx_destroy_display((*data)->mlx);
		free((*data)->mlx);
	}
	if ((*data)->map.array)
	{
		while ((*data)->map.array[i])
			free((*data)->map.array[i++]);
		free((*data)->map.array);
	}
	free(*data);
	*data = NULL;
}

/*
Function to clean up the allocated memory:
- Check if the data pointer is not NULL
- Check if somethings are allocated in data:
	-Free the allocated memory
- Set the data pointer to NULL
- Check if an error occurred:
	-Print the error message
	-Exit the program with EXIT_FAILURE (1)
- If no error occurred:
	-Print the message
	-Exit the program with EXIT_SUCCESS (0)
*/
void	cleanup(t_data **data, int error, char *message)
{
	if (data && *data)
		clean_data(data);
	if (error)
	{
		ft_putstr_fd(message, 2);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd(message, 1);
	exit(EXIT_SUCCESS);
}

// Function to return the length of a string
size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}

// Function to print a string to a file descriptor
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
