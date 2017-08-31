# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 18:15:40 by jcamhi            #+#    #+#              #
#    Updated: 2017/08/31 16:17:35 by jcamhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME = ft_bzero.s

OBJ_PATH = ./obj/
TOBJ_PATH = ./tobj/

INC_PATH = ./includes/

NAME = libfts.a

NAME_TEST = t_libftASM
NAME_TEST_OBJ = $(TOBJ_PATH)main.o

CC = nasm

CFLAGS = -g

OBJ_NAME = $(SRC_NAME:.s=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME) $(NAME_TEST)

$(NAME): $(OBJ)
	ar r $(NAME) $(OBJ)
	rm -fv $(NAME_TEST_OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.s
	@mkdir -p $(OBJ_PATH)
	$(CC) -f macho64 -o $@ $<

$(NAME_TEST): $(NAME_TEST_OBJ)
	gcc -L. -lfts $^ -o $@

$(NAME_TEST_OBJ): main.c
	@mkdir -p $(TOBJ_PATH)
	gcc $(CFLAGS) $(INC) -c $< -o $@


clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf $(OBJ_PATH)
	/bin/rm -rf $(TOBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f t_libftASM

re: fclean all
