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
	int i;
	int k;
	int nb_piece;
	char **tab;
	char **tab2;
	t_piece		*alst;
	t_piece		*piece;
	int			*tab_valid;
	size_t		*tab_size_t;

	k = 0;
	alst = NULL;
	piece = NULL;
	//tmp = NULL;
	i = 0;
	tab = ft_read_and_clean(argc, argv, &nb_piece);
	//lis le fichier d entree, memorise le nombre de piece dans nb_piece, et retourne un tableau de piece sous 
	//la forme de string sans les \n
	while (tab[i])
	{
		printf("<\n");
		if ((tab_valid = ft_is_valid(tab[i])) == 0) // check la validite des piece, et renvoi erreur sur a sortie standard si pbm
		{
			write(2, "error\n", 6);
			return (0);
		}
		tab_size_t = ft_atoui_piece(tab_valid); //transforme les pieces en binaire et les place le plus en haut et
												// le plus a gauche possible de leur carre de 4 respectif
		alst = ft_add_piece_to_list(tab_size_t, piece, alst); //cree une liste de piece avec leur proprietes.
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
