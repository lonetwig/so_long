CC = cc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

#mendatory files ----------------------------------
D_PATH = mendatory/display
D_FILES = $(D_PATH)/display_sprite.c $(D_PATH)/display_map.c $(D_PATH)/display_all.c $(D_PATH)/display_player.c

F_PATH = mendatory/funcs
F_FILES = $(F_PATH)/free.c $(F_PATH)/print_free_exit.c 

GA_PATH = mendatory/gameplay
GA_FILES = $(GA_PATH)/check_collision.c $(GA_PATH)/get_nearby.c $(GA_PATH)/player.c $(GA_PATH)/change_command.c \
$(GA_PATH)/print_steps.c

GE_PATH = get_next_line
GE_FILES = $(GE_PATH)/get_next_line_utils.c $(GE_PATH)/get_next_line.c

I_PATH = mendatory/info
I_FILES = $(I_PATH)/get_map_coordinations.c $(I_PATH)/get_player_pos.c $(I_PATH)/initialize_info.c

L_PATH = mendatory/loop
L_FILES = $(L_PATH)/loop.c $(L_PATH)/modes.c 

M_PATH = mendatory/map
M_FILES = $(M_PATH)/map.c $(M_PATH)/check_map.c $(M_PATH)/check_path.c

C_FILES = $(GE_FILES) $(M_FILES) $(F_FILES) $(D_FILES) $(GA_FILES) \
$(L_FILES) $(I_FILES)

#bonus files ------------------------------------------
D_PATH_B = bonus/display
D_FILES_B = $(D_PATH_B)/display_sprite_bonus.c $(D_PATH_B)/display_map_bonus.c $(D_PATH_B)/display_hud_bonus.c \
$(D_PATH_B)/display_all_bonus.c $(D_PATH_B)/display_player_bonus.c $(D_PATH_B)/display_enemies_bonus.c

F_PATH_B = bonus/funcs
F_FILES_B = $(F_PATH_B)/free_bonus.c $(F_PATH_B)/print_free_exit_bonus.c 

GA_PATH_B = bonus/gameplay
GA_FILES_B = $(GA_PATH_B)/check_collision_bonus.c $(GA_PATH_B)/get_nearby_bonus.c $(GA_PATH_B)/player_bonus.c \
$(GA_PATH_B)/change_command_bonus.c $(GA_PATH_B)/enemies_bonus.c $(GA_PATH_B)/enemie_move_bonus.c $(GA_PATH_B)/check_death_bonus.c

I_PATH_B = bonus/info
I_FILES_B = $(I_PATH_B)/get_enemies_pos_bonus.c $(I_PATH_B)/get_map_coordinations_bonus.c $(I_PATH_B)/get_player_pos_bonus.c \
$(I_PATH_B)/initialize_info_bonus.c

L_PATH_B = bonus/loop
L_FILES_B = $(L_PATH_B)/loop_bonus.c $(L_PATH_B)/modes_bonus.c 

M_PATH_B = bonus/map
M_FILES_B = $(M_PATH_B)/map_bonus.c $(M_PATH_B)/check_map_bonus.c $(M_PATH_B)/check_path_bonus.c

C_FILES_BONUS = $(D_FILES_B) $(F_FILES_B) $(GA_FILES_B) $(I_FILES_B) $(L_FILES_B) $(M_FILES_B) $(GE_FILES)

#-------------------------------------------------

O_FILES = $(C_FILES:.c=.o)
NAME = so_long.a
O_FILES_BONUS = $(C_FILES_BONUS:.c=.o)

EXE = so_long
BONUS_EXE = so_long_bonus
NAME = so_long.a
BONUS_NAME = so_long_bonus.a

all:$(EXE)

bonus:$(BONUS_EXE)


$(NAME):$(O_FILES)
	ar -rcs $@ $(O_FILES)

$(BONUS_NAME):$(O_FILES_BONUS)
	ar -rcs $@ $(O_FILES_BONUS)



$(EXE):$(NAME)
	$(CC) so_long.c $(MLX_FLAGS) $< -o $@

$(BONUS_EXE):$(BONUS_NAME)
	$(CC) so_long.c $(MLX_FLAGS) $< -o $@


%.o:%.c so_long.h so_long.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(O_FILES) $(O_FILES_BONUS) so_long.o

fclean:clean
	rm -f $(NAME) $(BONUS_NAME)

re:fclean all

.PHONY: all bonus clean fclean re