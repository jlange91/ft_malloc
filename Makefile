# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlange <jlange@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 12:33:38 by jlange            #+#    #+#              #
#    Updated: 2019/10/28 10:17:23 by jlange           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINK_NAME = libft_malloc.so
LIBFT = lft
SRC_NAME = 	malloc.c				\
						free.c					\
						realloc.c				\
						init_address.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
CC = clang
CPPFLAGS = -Iincludes
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

lft:
	@$(MAKE) -C libft

$(NAME): $(OBJ)
	@$(CC) -lpthread -shared $^ -o $@  -Llibft -lft
	@rm -f $(LINK_NAME)
	@ln -s $(NAME) $(LINK_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@$(MAKE) clean -C libft
	@rm -Rf $(OBJ) $(OBJ_PATH)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME) $(LINK_NAME)

test: $(LIBFT) $(NAME)
	@$(CC) main.c -I$(INC_PATH) $(LINK_NAME) libft/libft.a
	@./a.out

re: fclean all

.PHONY : all, clean, fclean, re, lft
