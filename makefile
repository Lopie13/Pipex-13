NAME = pipex

SRC_DIR				= srcs/
OBJ_DIR				= obj/
LDFLAGS 			= -L./minilibft -lminift
LIBFT				= ./minilibft/libminift.a

#Sources:
SRCS	= srcs/main.c srcs/utils.c
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(LIBFT) -I$(SRC_DIR) -g
RM = rm -f

start:				
	@make all

$(LIBFT):
	@make -C ./minilibft/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@make clean -C ./minilibft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ./minilibft

re: fclean all

.PHONY: all clean fclean re