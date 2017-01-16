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

NAME =			fillit.c

CC =			gcc

FLAGS =			-Wall -Werror -Wextra

HEADER =		fillit.h

HEADER_DIR =	./

FT_SRC_DIR =	./

FT_FILES =		
FT_COMPILED =	$(addsuffix .o,$(FT_FILES))

COMPILED =		$(FT_COMPILED)

all: $(NAME)

$(NAME): $(FT_COMPILED)
	ar rc $(FT_LIB) $(FT_COMPILED)
	ranlib $(FT_LIB)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)%.c $(HEADER)
	$(CC) -c $(FLAGS) -I $(HEADER_DIR) $< -o $@

clean:
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(FT_LIB)

re: fclean all