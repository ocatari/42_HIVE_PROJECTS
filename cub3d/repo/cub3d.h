/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:59:41 by corellan          #+#    #+#             */
/*   Updated: 2023/05/05 16:21:54 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

# define NO_INPUT 1
# define MANY_ARG 2
# define WRONG_FORMAT 3
# define INVALID_FILE 4
# define TEXTURES_MISSING 5
# define WRONG_INPUT 6
# define FLOOR_CELLING_MISSING 7
# define TEXTURE_NOT_FOUND 8
# define NO_MAP 9
# define INVALID_MAP 10

# define WIDTH_WINDOW 800
# define HEIGHT_WINDOW 600
# define HEIGHT_WINDOW_HALF 300

# define PI 3.141592653589793238462643383279

# define IN_THE_MIDDLE_OF_SQUARE 0.5
# define EMPTY_SQUARE 0
# define WALL_SQUARE 1

# define MOVEMENT_SPEED 0.04
# define TURNING_SPEED 0.02
# define PLAYER_COLLISION_DISTANCE 0.25

# define KEY_ESC 53

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
}			t_mlx;

typedef struct s_image
{
	void	*image;
	char	*address;
	int		height_tex;
	int		width_tex;
	int		bits_per_pixel;
	int		line_length;
	int		endianness;
}			t_image;

typedef struct s_render_walls
{
	double	ray_coordinate_in_camera_plane;
	double	ray_direction_x;
	double	ray_direction_y;
	int		player_which_map_cell_x;
	int		player_which_map_cell_y;
	double	straight_wall_distance;
	double	length_of_ray_to_next_x;
	double	length_of_ray_to_next_y;
	double	delta_distance_to_next_x;
	double	delta_distance_to_next_y;
	int		take_step_in_x;
	int		take_step_in_y;
	int		wall_hit;
	int		which_side_hit;
	int		wall_height;
	int		wall_height_half;
	int		draw_limit_low;
	int		draw_limit_high;
}			t_render_walls;

typedef struct s_cub3d
{
	t_mlx			mlx;
	t_image			image_1;
	t_image			image_2;
	t_image			no_tex;
	t_image			so_tex;
	t_image			ea_tex;
	t_image			we_tex;
	t_render_walls	render_walls;
	int				which_image;
	int				colour_ceiling;
	int				colour_floor;
	double			starting_angle;
	double			player_position_x;
	double			player_position_y;
	double			player_direction_x;
	double			player_direction_y;
	double			camera_plane_x;
	double			camera_plane_y;
	char			**map;
	int				**map_int;
	int				**textures;
	int				width_map;
	int				height_map;
	int				put_pixel_in_image_temp;
	int				key_w_down;
	int				key_a_down;
	int				key_s_down;
	int				key_d_down;
	int				key_arrow_left_down;
	int				key_arrow_right_down;	
	int				fd;
	char			***av_addr;
	int				idx_no;
	int				idx_so;
	int				idx_we;
	int				idx_ea;
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
	char			**file;
}			t_cub3d;

typedef struct s_coord
{
	int	row;
	int	col;
	int	i_row;
	int	j_col;
	int	i;
	int	j;
}				t_coord;

void	initialization(int argc, char **argv, t_cub3d *cub3d);
int		destroy(t_cub3d *cub3d);

int		key_down_event(int keycode, t_cub3d *variables);
int		key_up_event(int key_code, t_cub3d *cub3d);

void	put_pixel_in_image(t_cub3d *cub3d, int x, int y, int colour);

int		game_loop(t_cub3d *cub3d);
void	render_floor_ceiling(t_cub3d *cub3d);
void	render_walls(t_cub3d *cub3d);
void	draw_window(t_cub3d *cub3d, int x_coord);

void	in_which_box_we_are_in_map(t_cub3d *cub3d);
void	compute_ray_position_and_direction(t_cub3d *cub3d, int x_coord);
void	compute_delta_distances(t_cub3d *cub3d);
void	compute_x_step_and_initial_length_to_next_x(t_cub3d *cub3d);
void	compute_y_step_and_initial_length_to_next_y(t_cub3d *cub3d);
void	compute_ray_distance_with_dda(t_cub3d *cub3d);

void	move_forward(t_cub3d *cub3d);
void	move_backward(t_cub3d *cub3d);

void	strafe_left(t_cub3d *cub3d);
void	strafe_right(t_cub3d *cub3d);

void	turn_right(t_cub3d *cub3d);
void	turn_left(t_cub3d *cub3d);

int		return_texture_height(t_cub3d *cub3d, int nswe);
int		return_texture_width(t_cub3d *cub3d, int nswe);

double	insert_safety_movement_buffer(t_cub3d *cub3d, int x_or_y, int backward);
double	insert_safety_movement_buffer_strafe(t_cub3d *cub3d,
			int x_or_y, int backward);

int		which_wall_side(t_cub3d *cub3d);
int		relative_hight_texture(t_cub3d *cub3d, int y_coord, int nswe);
double	exact_coord_x_for_wall(t_cub3d *cub3d);
int		return_texture_width(t_cub3d *cub3d, int nswe);
int		return_texture_height(t_cub3d *cub3d, int nswe);

void	print_error(int error);
int		check_file_map(char **av, t_cub3d *cub3d);
int		check_presence_textures(char **array, t_cub3d *cub3d);
int		check_argument(int ac, char **av);
int		check_floor_ceiling(char **array, t_cub3d *img);
int		check_valid_number(char const *str);
int		check_is_number(char *str);
int		check_map(char **map, t_cub3d *cub3d);
int		check_mases(char **map, int flag, t_cub3d *cub3d);
int		check_empty_lines(char **map, t_cub3d *cub3d);
int		ft_find_word_array(char **array, char *needle);
int		ft_array_len(char **array);
int		ft_count_space(char *str);
int		check_textures(char **file, t_cub3d *cub3d);
int		longest_length(char **map);
int		error_free(char **array, int i);
int		check_after_flood_fill(char ***map);
void	create_int_map(t_cub3d *cub3d);
int		error_free_int(int **array, int i);
void	flood_fill(char ***temp, t_coord *id, int ro, int co);
void	ft_free_int(int **array, int height);
void	create_int_array_textures(t_cub3d *cub3d);
void	get_addr_textures(t_cub3d *cub3d);

#endif
