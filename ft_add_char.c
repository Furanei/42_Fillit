/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:20:57 by mbriffau          #+#    #+#             */
/*   Updated: 2017/02/01 14:38:19 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_add_char(char **map_char, t_piece *add)
{
	short		i;
	short		j;

	i = 0;
	j = 0;
	while (i < add->size)
	{
		j = 0;
		while (j < 4)
		{
			if (add->chartab[i][j] != '.')
				map_char[i + add->shift_y][j + add->shift_x] = add->chartab[i][j];
			j++;
		}
		i++;
	}
	return (add->chartab);
}