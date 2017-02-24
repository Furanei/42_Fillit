# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 20:12:50 by mbriffau          #+#    #+#              #
#    Updated: 2017/01/16 14:27:49 by mbriffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS += -Wall -Wextra -Werror

CC = gcc

OBJS = $(SRCS:.c=.o)

SRCS = 	fillitmain.c  \
			ft_add_char.c \
			ft_add_piece_to_list.c \
			ft_alloc_binary_map.c \
			ft_atoui_piece.c \
			ft_is_valid.c \
			ft_lstadd2.c \
			ft_lstcopy.c \
			ft_lstnew2.c \
			ft_post_cleaner.c \
			ft_pow.c \
			ft_read_and_clean.c \
			ft_s_bslot.c \
			ft_solver.c \
			ft_sqrt_sup.c \
			ft_tpiece_to_char.c \
			ft_memset.c \
			ft_strlen.c \
			ft_memalloc.c \
			ft_double_memalloc.c \
			ft_bzero.c \
			ft_putstr.c

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	-/bin/rm -f $(OBJS)

fclean: clean
	-/bin/rm -f $(OBJS) $(NAME)

re: fclean all
