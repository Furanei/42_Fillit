/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpiece_to_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:26:39 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/20 20:12:04 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_tpiece_to_char(t_piece *piece)
{
	printf("X________________X\n");
	char	**dest;
	int		i;
	int		j;
	int 	power;

	i = 3;
	power = 31;
	if(!(dest = malloc(sizeof(char*) * 5)))/*malloc du tableau de char*. */
		return (0);
	dest[4] = 0;

	while (dest[i])
	{
		if(!(dest[i] = malloc(sizeof(char) * 5)))/*malloc de chaque str dans le tableau de char* .*/
			return(0);
		dest[i][4] = '\0';
		i--;
	}
	while (i < 4) // i est normalement a 0
	{
		printf("enter\n");
		j = -1;
		if (piece->tab[i])
		{
			while(4 > ++j)
			{
				printf("B");
				if (ft_pow(2, power--) & piece->tab[i])
				{	
					printf("#");
					dest[i][j] = '#';
					printf("--->%c    | ", dest[i][j]);
				}
				else
				{
					printf(".");
					dest[i][j] = '.';
					printf("--->%c    | ", dest[i][j]);
				}
			}
			printf("\n");
		}
		else
		{
			printf("....");
			dest[i] = "....\0";
			printf("--->%s    | ", dest[i]);
		}
		power = 31;
		printf("%s\n", dest[i]);
		i++;
	}
	printf("X^^^^^^^^^^^^^^^X\n");
	return (dest);
}