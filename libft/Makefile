# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 20:28:37 by ikourkji          #+#    #+#              #
#    Updated: 2019/03/29 11:49:52 by ikourkji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
GNL		= get_next_line
PF		= ft_printf

INC		= -I ./inc

#		sources: sorted by rough type
#		because of GitHub submodules, ft_printf and gnl aren't in src folder
_BITS	= ft_swapend32.c
BITS	= $(patsubst %,bits/%,$(_BITS))
_DS		= ft_stack.c ft_queue.c
DS		= $(patsubst %,ds/%,$(_DS))
_IS		= ft_isalnum.c ft_isascii.c ft_isinf.c ft_isninf.c ft_iswhite.c \
		  ft_isalpha.c ft_isdigit.c ft_isnan.c ft_isprint.c
IS		= $(patsubst %,is/%,$(_IS))
_LST	= ft_lstadd.c ft_lstdelone.c ft_lstmap.c ft_lstdel.c ft_lstiter.c \
		  ft_lstnew.c ft_lstmsort.c
LST		= $(patsubst %,lst/%,$(_LST))
_MEM	= ft_bzero.c ft_memchr.c ft_memdel.c ft_memset.c ft_memalloc.c \
		  ft_memcmp.c ft_memmove.c ft_rememalloc.c ft_memccpy.c ft_memcpy.c \
		  ft_memrchr.c
MEM		= $(patsubst %,mem/%,$(_MEM))
_PUT	= ft_putchar.c ft_putendl.c ft_puterror.c ft_putnbr_fd.c \
		  ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr.c ft_putstr.c
PUT		= $(patsubst %,put/%,$(_PUT))
_STR	= ft_atoi.c ft_strclr.c ft_strjoin.c ft_strncpy.c ft_strsubdel.c \
		  ft_atoi_skip.c ft_strcmp.c ft_strjoindel.c ft_strnequ.c ft_strtrim.c \
		  ft_charat.c ft_strcpy.c ft_strlcat.c ft_strnew.c ft_strtrim_c.c \
		  ft_findintab.c ft_strdel.c ft_strlen.c ft_strnstr.c ft_tolower.c \
		  ft_findintabn.c ft_strdup.c ft_strmap.c ft_strrchr.c ft_toupper.c \
		  ft_itoa.c ft_strequ.c ft_strmapi.c ft_strsplit.c ft_strcat.c \
		  ft_striter.c ft_strncat.c ft_strstr.c ft_strchr.c ft_striteri.c \
		  ft_strncmp.c ft_strsub.c
STR		= $(patsubst %,str/%,$(_STR))

_PFSRC	= ft_printf.c ft_printf_cont.c pf_core.c pf_utils.c pf_numbers.c \
		  pf_strings.c pf_strutils.c pf_smallconvs.c pf_floats.c
PFSRC	= $(patsubst %,$(PF)/src/%,$(_PFSRC))

__SRC	= $(_BITS) $(_DS) $(_IS) $(_LST) $(_MEM) $(_PUT) $(_STR)
_SRC	= $(BITS) $(DS) $(IS) $(LST) $(MEM) $(PUT) $(STR)
SRC		= $(patsubst %,src/%,$(_SRC)) $(GNL)/src/get_next_line.c \
		  $(PFSRC)

_OBJ	= $(__SRC:.c=.o) get_next_line.o $(_PFSRC:.c=.o)
OBJ		= $(patsubst %,obj/%,$(_OBJ))

RED		= \033[0;31m
GREEN	= \033[0;32m
NC		= \033[0m

all: $(NAME)

$(NAME):
	@echo "compiling libft..."
	@cp $(GNL)/inc/*.h $(PF)/inc/*.h inc
	@gcc -Wall -Wextra -Werror $(INC) -c $(SRC)
	@mkdir -p obj
	@mv $(_OBJ) obj
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)complete!$(NC)"

clean:
	@rm -rf obj
	@echo "$(RED)removed obj directory$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)removed $(NAME)$(NC)"

re: fclean all

.PHONY: all $(NAME) clean fclean re
