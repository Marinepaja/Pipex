OBJS = ${SRCS:.c=.o}

SRC_DIR = ./

SRC = command.c files.c pipex.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = ./

OBJ = $(SRC:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

NAME = pipex

all: $(NAME) pipex.h

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c pipex.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "making libft..."
	@make -sC $(LIBFTDIR)
	@echo "Done !"

clean:
	@echo "cleaning libft..."
	@make -sC $(LIBFTDIR) clean
	rm -f ${OBJS} 

fclean: clean
	@make -sC $(LIBFTDIR) fclean
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re

