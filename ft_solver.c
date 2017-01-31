/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 18:01:23 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/27 23:50:05 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		*ft_binary_add(size_t *area, t_piece *add)/*renvoit la somme de area et de add */
{
	int		i;

	i = 0;
	while (i < 4)
	{
		area[add->shift_y + i] += add->tab[i];
		i++;
	}
	return (area);
}

static char		**ft_solver_helper(size_t *binary_map, t_piece *new, char **map_char, int limit)
{
	printf("ft_solver_helper\n");
	int			enter;
	size_t		*copy_binary_map;
	t_piece		*copy_new;
	int			pass;
	size_t		*result;

	result = NULL;
	pass = 0;
	enter = 0;
		printf("test1\n");   
	if (new == NULL)
	{	printf("test2\n");   
		return (map_char);
	}   
	if (!(copy_binary_map = (size_t*)malloc(sizeof(size_t) * 13)))
		return (0);
	if (!(copy_new = ft_lstnew3(new)))
		return (0);
	copy_binary_map = binary_map;                                                                                                                                                                                                                                      
	while(copy_new != 0)
	{
		if(enter == 1)
		{
			if ((map_char = ft_solver_helper(copy_binary_map, new->next, map_char, limit)) != 0)// si le solver helper revoi une piece c;est qu' om peut l ajoute
			{
				printf("ft_add\n");
				map_char = ft_add_char(map_char, ft_tpiece_to_char(copy_new));// ft_uitoa converti en char et ft_add ajout au tableau de char.
				return(map_char);
			}
			pass = 1;
		}
		copy_new = ft_search_binary_slot(binary_map, copy_new, pass, limit);// revoie la piece en binaire avec son placement possible ou 0 si rien trouve.
		copy_binary_map = ft_binary_add(binary_map, copy_new);// enregistre dans copie pour pouvoir retravailler avec l,original si besoin
		enter = 1;
	}
	return (0);
}
char	**ft_solver(t_piece *alst, int nb_piece)// je ne sais pas encore quel return mettre
{
	printf("solver\n");
	size_t	*binary_map; // la zone de depart vide pour que A puisse se replacer aussi  dans la fonction. 
	char	**map_char;// map de char vide
	int		i;
	int		limit;
	int		ok;

	i = 0;
	ok = 0;
	limit = ft_sqrt_sup(nb_piece * 4);
	if(!(binary_map = malloc(sizeof(size_t) * 13)))// malloc de la zone size_t, une 
		{//t_piece special serait elle mieux? par exemple 
		//avec un compteur pour savoir a quelle boucle de fonction nous sommes.
		return (0);
		}
	if (!(map_char = ft_double_memalloc(ft_sqrt_sup(6 * nb_piece), ft_sqrt_sup(6 * nb_piece))))
		return 0;
	while (i < 13)
	{
		binary_map[i] = 0;
		i++;
	}
	while (!(ok))
	{
		if ((map_char = ft_solver_helper(binary_map, alst, map_char, limit)) != 0)
			ok = 1;
		limit++;
	}
	return (map_char);
}
