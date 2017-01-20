/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 00:55:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/20 01:36:54 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int ft_count(int *tab, int count)
{
	if (count < 4)
		return (0);
	count = 0;
	count = (tab[0] + 1 == tab[1] || tab[0] + 4 == tab[1]) 
		+ (tab[0] + 1 == tab[2] || tab[0] + 4 == tab[2])
		+ (tab[0] + 1 == tab[3] || tab[0] + 4 == tab[3])
		+ (tab[1] + 1 == tab[2] || tab[1] + 4 == tab[2])
		+ (tab[1] + 1 == tab[3] || tab[1] + 4 == tab[3]) 
		+ (tab[2] + 1 == tab[3] || tab[2] + 4 == tab[3]);	
		return (count);
}

static void ft_initialise(int *i, int *j, int *count)
{
	*count = 0;
	*i = 0;
	*j = 0;
}

int		*ft_is_valid(char *s)
{/*trouve la position de chaque #, si le nombre de # est different de 4, la fonction return 0.*/
	int			i;/*index de tab.*/
	int			j;/*index de s.*/
	int			*tab;/*tableau d'int a returner, contient les positions de chaque # */
	int			count;/*compte le nombre de # */

	ft_initialise(&i, &j, &count);
	if (!(tab = (int*)malloc(sizeof(int) * 4)))
		return (0);
	while (s[j] != '\0')
	{
		if (s[j] != '#' && s[j] != '.')
			return 0;
		if (s[j] == '#')
		{
			count++;
			if (count > 4)
				return (0);
			tab[i] = j;
			i++;
		}
		j++;
	}	
	count = ft_count(tab, count);
	if (count == 3 || count == 4)
		return (tab);
	return (0);
}