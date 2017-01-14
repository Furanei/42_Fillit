/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:13:17 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/14 17:10:54 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "fillit.h"

typedef struct		s_piece
{
	size_t			*tab;
	char			letter;
	struct 			s_piece *next;
}					t_piece;

t_piece			*ft_add_piece_to_list(size_t *tab, t_piece *first);
t_piece			*ft_lstadd2(t_piece *first, t_piece *nnew);
t_piece		 	*ft_lstnew2(size_t *tab, char c);
size_t			*search_slot(size_t *area, size_t *add);
t_piece			*ft_sort(char *s, t_piece *alst);
size_t			*ft_piece(int *t);
size_t			ft_pow(size_t n, int power);
int				ft_index(char *s, int nb, int i);

#endif