NAME = cub3D

# Compile
CC = clang
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11 -lm -lbsd
INC = -I$(INC_DIR)
HEADER = $(INC_DIR)/cub3d.h

# Location
MLX_DIR = minilibx_linux
INC_DIR = includes
SRCS_DIR = srcs

# Source files 
MAIN = main.c render.c
PARSING = parsing_file.c parsing_fc.c parsing_textures.c check_map.c \
	set_and_parse_map.c check_surround.c parsing_fc_utils.c 
INIT = init_data.c init_data_ray.c init_render.c init_mlx.c
GET_NEXT_LINE = get_next_line.c get_next_line_utils.c gnl_str_free.c 
ERROR = ft_error.c ft_exit.c parsing_errors.c ft_free_and_exit.c
GLOBAL_UTILS = ft_charinstr.c ft_count_nb_virgule.c
RAYCAST = keys.c raycasting_utils.c raycasting_move.c

SRCS = $(addprefix srcs/, $(MAIN)) \
	$(addprefix srcs/parsing/, $(PARSING)) \
	$(addprefix srcs/init/, $(INIT)) \
	$(addprefix srcs/get_next_line/, $(GET_NEXT_LINE)) \
	$(addprefix srcs/error/, $(ERROR)) \
	$(addprefix srcs/raycast/, $(RAYCAST)) \
	$(addprefix srcs/global_utils/, $(GLOBAL_UTILS))

# Object files
OBJ = $(SRCS:.c=.o)

# Pattern rule
$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c ${HEADER}
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	${CC} $(CFLAGS) $(INC) -o $(NAME) $(OBJ) -L $(MLX_DIR) $(MLXFLAGS)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, make
