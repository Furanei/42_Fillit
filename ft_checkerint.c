/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 22:37:23 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/14 16:01:31 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

static unsigned int	ft_convertbit(const char *s, int *nbtab, int i)/* recois des str de 16 fini par un \0. */
{
	int				power;
	int				convert;

	printf("___FT_COVERTBIT___\n");
	convert = 0;
	power = 31;
	while (power > 27)
	{
		if (s[i] == '#')
			convert += ft_pow(2, power);
	power--;
	i++;
	}
	return (convert);

// void		ft_checkerint(char *s)
// {
// 	int		i;

// 	i = 0;
// 	while(i < 4)
// 	{
		
// 	}
// 	return ;
// }

int		main(int ac, char **av)
{
	int i;

	i = 0;

	while (a <= 16)
	{
		ft_convertbit(av[1], 0, i);
		i += 4;
	}
}