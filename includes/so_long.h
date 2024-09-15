/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:54:45 by obouayed          #+#    #+#             */
/*   Updated: 2024/09/15 14:17:29 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Include the minilibx
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// Include X11 keysymbols
# include <X11/keysym.h>
// Include X11 functions
# include <X11/X.h>
// Include file reading
# include <fcntl.h>

/*
Structure to store a linked list:
- Pointer to the content of the node
- Pointer to the next node
*/
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

/*
Structure to store map data:
- Array of strings containing the map
- Width of the map
- Height of the map
- Size of a tile in the map
- Number of coins in the map
*/
typedef struct s_map
{
	char			**array;
	int				width;
	int				height;
	int				tile_size;
	int				nbr_coins;
}					t_map;

/*
Structure to store player data:
- Player's x and y coordinates
- Boolean to check if the player found the exit
*/
typedef struct s_player
{
	int				x;
	int				y;
	int				find_exit;
	int				nbr_moves;
}					t_player;

/*
Structure to store image data:
- Pointer to the image
- Pointer to the image's address
- Pointer to the player's image
- Pointer to the wall's image
- Pointer to the floor's image
- Pointer to the coin's image
- Pointer to the exit's image
- Number of bits per pixel
- Size of a line of the image
- Endianness of the image (big or little endian)
*/
typedef struct s_img
{
	void			*ptr;
	char			*addr;
	void			*player;
	void			*wall;
	void			*floor;
	void			*coin;
	void			*exit;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_img;

/*
Structure to store window data:
- Pointer to the connection with the X server
- Pointer to the window
- Image data
- Player data
- Map data
*/
typedef struct s_data
{
	void			*mlx;
	char			*win;
	t_img			img;
	t_player		player;
	t_map			map;
}					t_data;

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				color_whole_image(t_data *data, int color);
void				cleanup(t_data **data, int error, char *message);
void				init_window(t_data **data, int width, int height);
void				draw_square(t_data *data, int color);
int					move_square(int keysym, t_data *data);
char				*get_next_line(int fd);
int					search_nl(t_list *stash);
t_list				*last_node(t_list *stash);
void				add_buffer(t_list **stash, int fd);
void				add_stash(char *buffer, t_list **stash);
char				*add_line(t_list *stash);
void				copy_str(t_list *list, char *str);
int					len_for_line(t_list *stash);
void				clear_stash(t_list **stash);
void				lstclear(t_list **stash, t_list *node, char *buffer);
void				init_map(t_data **data, char **av);
size_t				ft_strlen(const char *s);
void				ft_putstr_fd(char *s, int fd);
void				check_map_format(t_data **data, int tile_size);
void				check_valid_content(t_data **data);
void				check_player(t_data **data);
void				check_exit(t_data **data);
void				check_coins(t_data **data);
void				assign_player_position(t_data **data);
void				parsing_floodfill(t_data **data);
void				init_textures(t_data **data);
void				display_textures(t_data **data);
void				move_player_up(t_data **data);
void				move_player_left(t_data **data);
void				move_player_right(t_data **data);
void				move_player_down(t_data **data);
char				*ft_itoa(int n);
void				display_nbr_moves(t_data **data);
char				*ft_strjoin(char const *s1, char const *s2);
void				check_map_extension(char *filename, t_data **data);

// Definition of characters for map elements

// WALL: character for walls (ASCII value of 1)
# define WALL 49
// FLOOR: character for floor (ASCII value of 0)
# define FLOOR 48
// COIN: character for coin (ASCII value of C)
# define COIN 67
// PLAYER: character for the player (ASCII value of P)
# define PLAYER 80
// MAP_EXIT: character for the exit (ASCII value of E)
# define MAP_EXIT 69

# ifndef BUFFER_SIZE
// Definition of buffer size for get_next_line (1 by default)
#  define BUFFER_SIZE 1
# endif

#endif