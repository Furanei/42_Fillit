/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:23:54 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/12 18:20:30 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"


#include <stdio.h>
t_piece	*ft_lstadd2(t_piece *first, t_piece *nnew)
{
	t_piece *tmp;

	tmp = NULL;
	if (first == NULL)	
		return (nnew);
	else
	{
		tmp = first;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = nnew;
		return (first);
	}
}