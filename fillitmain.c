/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:48:09 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/20 17:01:06 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char **tab;
	t_piece		*alst;
	t_piece		*piece;
	int 		i;
	size_t		*copy;
	int			*tab_valid;
	size_t		*tab_size_t;

	char		**dest;
	if(!(dest = malloc(sizeof(char*) * 5)))
		return 0;
	dest[4] = 0;
	
	if(!(copy = malloc(sizeof(size_t) * 13)))
		return (0);
	alst = NULL;
	piece = NULL;
	tab = ft_read_and_clean(argc, argv);
	i = 0;
	while (tab[i])
	{
		printf("<\n");
		if ((tab_valid = ft_is_valid(tab[i])) == 0)
		{
			write(1, "error\n", 6);
			return (0);
		}
		tab_size_t = ft_atoui_piece(tab_valid);
		alst = ft_add_piece_to_list(tab_size_t, piece, alst);
		//printf("%s\n%zi-%zi-%zi-%zi\n", tab[i], piece->tab[0], piece->tab[1], piece->tab[2], piece->tab[3]);
		i++;
	}
	i = 0;
	printf("---------XXXXXXXXXXXXXX--------\n");
	while (alst != NULL)
	{
		while (i < 4 )
		{
		printf("%zi\n", alst->tab[i++]);
		}
		i=0;
		printf("\n");
		alst = alst->next;
	}
	// copy[0] = 
	// dest = ft_itoa_piece(alst);
	// printf("%c\n", dest[0][0]);
					//verifier la sortie de ft_piece, peut etre que la sortie n'est pas bonne 
					// et verifier ft_itoa_Piece

	// copy[0] = alst->tab[0];
	// copy[1] = alst->tab[1];
	// copy[2] = alst->tab[2];
	// copy[3] = alst->tab[3];
	// tmp = alst->next;
	// printf("copy end\n");// verifier le contenu de tmp  et de copy
	// while (j--)// segfault 
	// {
	// 	printf("enter\n");
	// 	copy = search_slot(copy, tmp->tab);// retour de tableau d'int, pas de chat vec lettre, il faut trouver un moyen;
	// 	tmp = tmp->next;
	// }
	return (0);
}