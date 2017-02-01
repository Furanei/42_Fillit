/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:39:33 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/25 01:13:41 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*ft_lstcopy(t_piece *piece)
{
	t_piece *new;
	int i;
	int j;

	i = 0;
	new = NULL;
	new = (t_piece*)malloc(sizeof(t_piece));
	if (!new)
		return (NULL);
	new->letter = piece->letter;
	new->next = piece->next;
	new->shift_x = piece->shift_x;
	new->shift_y = piece->shift_y;
	new->size = piece->size;
	if (!(new->chartab = (char**)malloc(sizeof(char*) * 5)))
		return (0);
	new->chartab[4] = 0;
	while (i < 4)
	{
		if (!(new->chartab[i] = (char*)malloc(sizeof(char) * 5)))
			return (0);
		j = 0;
		while (j < 4)
		{
			new->chartab[i][j] = piece->chartab[i][j];
			j++;
		}
		new->chartab[i][4] = '\0';
		new->tab[i] = piece->tab[i];
		i++;
	}
	return (new);
}