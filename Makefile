# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 06:59:43 by ikourkji          #+#    #+#              #
#    Updated: 2019/04/03 06:59:21 by ikourkji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

CFLAGS	= -Wall -Wextra -Werror

INC		= -I ./inc

LIB		= -L ./libft -lft

FTSRC	= ./libft/src/bits/* ./libft/src/ds/* ./libft/src/is/* \
		  ./libft/src/lst/* ./libft/src/mem/* ./libft/src/put/* \
		  ./libft/src/str/* ./libft/ft_printf/src/*

_SRC	= *.c
SRC		= $(patsubst %,src/%,$(_SRC))

_OBJ	= $(_SRC:.c=.o)
OBJ		= $(patsubst %,obj/%,$(_OBJ))

TEST	= -g -fsanitize=address

GREEN	= \033[0;32m
NC		= \033[0m

all:	$(NAME)

$(NAME):
	@make -C libft
	@cp libft/inc/* ./inc
	@echo "compiling ft_ls..."
	@gcc $(INC) $(CFLAGS) -c $(SRC)
	@mkdir -p obj
	@mv $(_OBJ) obj
	@gcc $(INC) $(LIB) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)complete!$(NC)"

clean:
	@make -C libft clean
	@echo "deleting obj directory"
	@rm -rf obj

fclean: clean
	@make -C libft fclean
	@echo "deleting $(NAME)"
	@rm $(NAME)

re: fclean all

test:
	gcc $(SRC) $(INC) $(LIB) $(TEST) -o test_ls

.PHONY: all $(NAME) clean fclean re test
	
