GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g
LFT			=	libft/libft.a
INC			=	-I ./includes -I ./libft/includes
LIB			=	-L ./libft -lft
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/pipex.c

all:		$(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB) -fsanitize=address -g

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ $(GREEN)OK$(RESET) ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			@echo "$@ $(GREEN)created$(RESET)"
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "Object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "Binary file removed."

re:			fclean all

.PHONY:		all clean fclean re

#42YerevanProjects