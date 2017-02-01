/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:49:49 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/01 14:54:59 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*ft_lstnew3(t_piece *piece)
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
	new->shift_x = 0;
	new->shift_y = 0;
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
