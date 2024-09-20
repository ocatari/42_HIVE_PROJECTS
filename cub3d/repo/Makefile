# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 10:54:50 by corellan          #+#    #+#              #
#    Updated: 2023/05/05 16:10:47 by tpoho            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c cub3d_events.c cub3d_key_events.c check_arguments.c \
check_file_map.c utils.c check_textures.c check_floor_ceiling.c check_map.c \
check_map2.c utils2.c error.c check_map3.c initialization.c game_loop.c \
render_functions.c put_pixel_in_image.c movement_functions.c \
movement_functions_2.c draw_window.c digital_differential_analyzer.c \
render_functions_helpers.c create_int_map.c process_textures.c \
insert_safety_movement_buffer.c determine_texture_pixel_colours_helpers.c

OBJS = main.o cub3d_events.o cub3d_key_events.o check_arguments.o \
check_file_map.o utils.o check_textures.o check_floor_ceiling.o check_map.o \
check_map2.o utils2.o error.o check_map3.o initialization.o game_loop.o \
render_functions.o put_pixel_in_image.o movement_functions.o \
movement_functions_2.o draw_window.o digital_differential_analyzer.o \
render_functions_helpers.o create_int_map.o process_textures.o \
insert_safety_movement_buffer.o determine_texture_pixel_colours_helpers.o

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT = -Llibft -lft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re:	fclean	all
