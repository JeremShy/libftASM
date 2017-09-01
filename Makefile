# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 18:15:40 by jcamhi            #+#    #+#              #
#    Updated: 2017/09/01 13:19:38 by jcamhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME = ft_bzero.s \
						ft_strcat.s \
						ft_isalpha.s \
						ft_isdigit.s \
						ft_isalnum.s \
						ft_isascii.s \
						ft_isprint.s \
						ft_toupper.s \
						ft_tolower.s \
						ft_puts.s \
						ft_strlen.s \
						ft_memset.s \
						ft_memcpy.s

OBJ_PATH = ./obj/
TOBJ_PATH = ./tobj/

INC_PATH = ./includes/

NAME = libfts.a

NAME_TEST = t_libftASM
NAME_TEST_OBJ = $(TOBJ_PATH)main.o

CC = nasm

CFLAGS = -g -O0

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
