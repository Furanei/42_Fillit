/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpiece_to_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:26:39 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/27 23:51:31 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*ft_tpiece_to_char(t_piece *piece)
{
	printf("X________________X\n");
	int		i;
	int		j;
	int 	power;

	power = 31;
	j = 0;
	i = 0;
	while (i < 4) // i est normalement a 0
	{
		if (piece->tab[i] == 0)
			piece->chartab[i] = "....\0";
		else
		{		
			j = 0;
			while(j < 4 )
			{
				if (ft_pow(2, power) & piece->tab[i])
				{	
					piece->chartab[i][j] = piece->letter;
					power--;
				}
				else
				{
					piece->chartab[i][j] = '.';
					power--;
				}
				j++;
			}
		}
		power = 31;
		i++;
	}
	return (piece);
}