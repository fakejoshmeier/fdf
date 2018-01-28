# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/06 17:01:42 by jmeier            #+#    #+#              #
#    Updated: 2018/01/27 18:35:42 by jmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FUNC = main parse

C_LOC = src/
C_NAM = $(addsuffix .c, $(FUNC))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

O_LOC = obj/
O_NAM = $(addsuffix .o, $(FUNC))
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

LIB_LOC = ftprintf/
LIB_NAM = libftprintf.a
LIB_SRC = $(addprefix $(LIB_LOC), $(LIB_NAM))

H_LOC = -I inc/ -I ftprintf/inc -I ftprintf/libft/inc
HEADERS = inc/*.h

all: $(NAME)

$(NAME): $(O_SRC) $(LIB_SRC)
	@echo Compiling...
	@gcc -Wall -Werror -Wextra $^ -o $(NAME)
	@echo Complete.  Dope.

$(O_LOC)%.o: $(C_LOC)%.c $(HEADERS)
	@echo Recompiling...
	@gcc -Wall -Werror -Wextra $(H_LOC) -o $@ -c $<

$(LIB_SRC): force
	@echo Compiling libft...
	@make -C $(LIB_LOC)

force:
	@true

clean:
	@echo Cleaning .o files...
	@/bin/rm -f $(O_SRC)
	@make clean -C $(LIB_LOC)
	@echo .o files removed.

fclean: clean
	@echo Cleaning $(NAME) ...
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_LOC)
	@echo $(NAME) removed

re: fclean all

.PHONY: all clean fclean re
