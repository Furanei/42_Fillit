/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:39:33 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/13 00:10:00 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

t_piece		*ft_lstnew2(size_t *tab, char c)
{
	t_piece *new;
	int i;

	i = 0;
	new = NULL;
	new = (t_piece*)malloc(sizeof(t_piece));
	if (!new)
		return (NULL);
	new->tab = (size_t *)malloc(sizeof(size_t) * 4);
	if (!new->tab)
		return (NULL);
	new->letter = c;
	new->next = NULL;
	while (i < 4)
	{
		new->tab[i] = tab[i];
		i++;
	}
	return (new);
}
