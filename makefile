NAME = pipex

SRC_DIR				= srcs/
OBJ_DIR				= obj/
LDFLAGS 			= -L./$(SRC_DIR)/mini -lminift
LIBFT				= ./$(SRC_DIR)/minilibft/libminift.a

#Sources:
SRCS	=	$(SRC_DIR)ps_mains/error_handler.c \
						$(SRC_DIR)ps_mains/a_to_b.c \
						$(SRC_DIR)ps_mains/b_to_a.c \
						$(SRC_DIR)ps_mains/push_swap.c \
						$(SRC_DIR)ps_mains/split.c \
						$(SRC_DIR)ps_mains/stack_init.c \
						$(SRC_DIR)ps_mains/stack_utils.c
						
SRCS = $(PUSHSWAP) $(COMMANDS) 
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(LIBFT) -I$(SRC_DIR) -g
RM = rm -f

start:				
	@make all

$(LIBFT):
	@make -C ./$(SRC_DIR)/libft+/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@make clean -C ./$(SRC_DIR)/libft+

fclean: clean
	@$(RM) $(NAME)