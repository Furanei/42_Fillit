/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 02:03:06 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/20 00:44:06 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int		ft_first(char *s) /*trouve le premier #.*/
{
	int		i;

	i = 0;
	while(s[i] != '#')
		i++;
	return(i);
}

int	ft_pow(int n, int power) /*donne la puissance POWER de N. */
{
	int		exp;

	if (power == 0)
		return (1);
	exp = n;
	while (1 < power--)
	{
		n *=  exp;
	}
	return (n);
}

void	ft_strtoint(char *s, int *tab)
{
	
}


int		main(int ac, char **av)
{
	int		*tab;
	int		first;

	tab = (int *)malloc(16 + 1);
	tab[16] = '\0';
	if (ac > 1)
		first = ft_first(av[1]);
		printf("%d\n", ft_first(av[1]));
	return 0;
}
