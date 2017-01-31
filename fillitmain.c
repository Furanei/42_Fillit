/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:48:09 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/25 02:22:10 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	// int fd;
	int i;
	int k;
	int nb_piece;
	// size_t k;
	// char buffer[21];
	char **tab;
	char **tab2;
	// char **tab2;
	t_piece		*alst;
	t_piece		*piece;
	//t_piece		**tmp;
	// size_t		*copy;
	int			*tab_valid;
	size_t		*tab_size_t;
	char		**dest;

	k = 0;
	alst = NULL;
	piece = NULL;
	dest = NULL;
	//tmp = NULL;
	dest = ft_double_memalloc(4, 4);
	i = 0;
	tab = ft_read_and_clean(argc, argv, &nb_piece);
	while (tab[i])
	{
		printf("<\n");
		if ((tab_valid = ft_is_valid(tab[i])) == 0)
		{
			write(2, "error\n", 6);
			return (0);
		}
		tab_size_t = ft_atoui_piece(tab_valid);
		alst = ft_add_piece_to_list(tab_size_t, piece, alst);
		//printf("%s\n%zi-%zi-%zi-%zi\n", tab[i], piece->tab[0], piece->tab[1], piece->tab[2], piece->tab[3]);
		i++;
	}
	i = 0;
	printf("---------XXXXXXXXXXXXXX--------\n");
	//*tmp = alst;
	// while (alst)
	// {
	// 	alst = ft_tpiece_to_char(alst);
	// 	i = 0;
	// 	while (i < 4)
	// 	{
	// 		printf("%s\n", alst->chartab[i]);
	// 		i++;
	// 	}
	// 	alst = alst->next;
	// }
	// alst = *tmp;
	tab2 = ft_solver(alst, nb_piece);
	while (tab2[k])
	{
		printf("%s\n", tab2[k]);
		k++;
	}
}
