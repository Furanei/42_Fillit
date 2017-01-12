/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_piece_to_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:56:36 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/12 20:11:59 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*ft_add_piece_to_list(int *tab, t_piece *first)
{
	printf("ft_add_piece_to_list\n");
	static char c = 'A';

	first = ft_lstadd2(first, ft_lstnew2(tab, c));
	c++;
	return (first);
}