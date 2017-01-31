/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:13:17 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/27 23:50:54 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "fillit.h"
# include <fcntl.h>
//to delete :
# include <stdio.h>

typedef struct		s_piece
{
	size_t			tab[4];
	char			letter;
	short			shift_y;
	short			shift_x;
	short			size;
	char			**chartab;
	struct 			s_piece *next;
}					t_piece;

char			**ft_read_and_clean(int argc, char **argv, int *i);
int				*ft_is_valid(char *s);
size_t			*ft_atoui_piece(int *t);
size_t			ft_pow(size_t n, int power);
t_piece			*ft_add_piece_to_list(size_t *tab, t_piece *piece, t_piece *first);
t_piece		 	*ft_lstnew2(size_t *tab, char c);
t_piece			*ft_lstadd2(t_piece *first, t_piece *nnew);
size_t			*search_slot(size_t *area, size_t *add);
char			**ft_itoa_piece(t_piece *piece);
size_t			ft_itoa_piece_limit(size_t *t, size_t nb_line);
t_piece			*ft_tpiece_to_char(t_piece *piece);
t_piece			*ft_search_binary_slot(size_t *binary_map, t_piece *add, int pass, int limit);
int				ft_sqrt_sup(int nb);
char			**ft_add_char(char **map_char, t_piece *add);
char			**ft_solver(t_piece *alst, int nb_piece);
t_piece			*ft_lstnew3(t_piece *piece);

#endif
