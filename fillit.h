/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:13:17 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/20 18:37:35 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "fillit.h"

typedef struct		s_piece
{
	size_t			tab[4];
	char			letter;
	struct 			s_piece *next;
}					t_piece;

int				*ft_is_valid(char *s);
size_t			*ft_atoui_piece(int *t);
size_t			ft_pow(size_t n, int power);
t_piece			*ft_add_piece_to_list(size_t *tab, t_piece *piece, t_piece *first);
t_piece		 	*ft_lstnew2(size_t *tab, char c);
t_piece			*ft_lstadd2(t_piece *first, t_piece *nnew);
size_t			*search_slot(size_t *area, size_t *add);
char			**ft_itoa_piece(t_piece *piece);
size_t			ft_itoa_piece_limit(size_t *t, size_t nb_line);
char			**ft_tpiece_to_char(t_piece *piece);

#endif
