/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_sup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:39:52 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/25 18:31:43 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_sup(int nb)
{
	int	i;
	int comp;

	comp = 0;
	i = 0;
	while (nb > comp)
	{
		i++;
		comp = i * i;
		if (nb == comp)
			return (i);
	}
	return (i);
}