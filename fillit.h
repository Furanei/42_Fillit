/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:13:17 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/12 19:55:04 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct		s_piece
{
	int				*tab;
	char			letter;
	struct 			s_piece *next;
}					t_piece;

t_piece			*ft_add_piece_to_list(int *tab, t_piece *first);
t_piece			*ft_lstadd2(t_piece *first, t_piece *nnew);
t_piece		 	*ft_lstnew2(int *tab, char c);
int				*search_slot(int *area, int *add);
t_piece			**ft_sort(char *s, t_piece **alst);


#endif