/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:57:30 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/12 14:03:22 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
//to delete
#include <stdio.h>
#include "fillit.h"
/*
typedef struct s_piece
{
	int	*tab;
	char	letter;
	struct s_piece *next;
}				t_piece;
t_piece *ft_lstnew2(int *tab, char c)
{
	t_piece *new;
	int i;
	i = 0;
	new = NULL;
	new = (t_piece*)malloc(sizeof(t_piece));
	if (!new)
		return (NULL);
	new->tab = (int *)malloc(sizeof(int) * 4);
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
t_piece *ft_add(t_piece *first, t_piece *piece)
{
	t_piece *tmp;
	tmp = NULL;
	if (first == NULL)
		return (piece);
	else
	{
		tmp = first;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = piece;
	}
	return (first);
}
t_piece *ft_add_to_list(int *tab, t_piece *piece, t_piece *first)
{
	static char c = 'A';
	piece = ft_lstnew2(tab, c);
	first = ft_add(first, piece);
	c++;
	return (first);
}
*/
/*t_piece *ft_add(t_piece *first, t_piece *piece)
{
	piece->next = first;
	first = piece;
	return (first);
}*/

int main()
{
	t_piece *piece;
	t_piece *first;
	t_piece *tmp;
	int tab[4];
	int i;

	i = 0;
	piece = NULL;
	first = NULL;
	tab[0] = 8;
	tab[1] = 6;
	tab[2] = 3;
	tab[3] = 4;
	//piece = ft_lstnew2(tab, 'A');
	//first = ft_add(first, piece);
	first = ft_add_piece_to_list(tab, piece, first);
	tab[0] = 9;
	tab[1] = 9;
	tab[2] = 9;
	tab[3] = 9;
	//piece = ft_lstnew2(tab, 'B');
	//first = ft_add(first, piece);
	first = ft_add_piece_to_list(tab, piece, first);
	tab[0] = 555;
	tab[1] = 78;
	tab[2] = 78;
	tab[3] = 78;
	//piece = ft_lstnew2(tab, 'C');
	//first = ft_add(first, piece);
	first = ft_add_piece_to_list(tab, piece, first);
	tmp = first;
	while (tmp)
	{
		printf("%c\n", tmp->letter);
		while (i < 4)
		{
			printf("%d\n", tmp->tab[i]);
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
	return (0);
}