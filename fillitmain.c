/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:48:09 by cyrmorin          #+#    #+#             */
/*   Updated: 2017/01/18 19:03:33 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_clean(char *str, char *buffer)
{
	int i;
	int j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * 17);
	if (!str)
		return (NULL);
	while (i < 16)
	{
		if (i > 0 && (i % 4) == 0)
			j++;
		str[i] = buffer[i + j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main(int argc, char **argv)
{
	int fd;
	int i;
	char buffer[21];
	char **tab;
	t_piece		*alst;
	t_piece		*piece;
	size_t		*copy;
	// t_piece		*tmp;
	int 	j;
	
	if(!(copy = (size_t*)malloc(sizeof(size_t) * 13)))
		return (0);
	// init a 0
	alst = NULL;
	piece = NULL;
	i = 0;
	if (argc != 2)
		return (0);
	void				*ft_memset(void *s, int c, size_t n);
	ft_memset(buffer, ' ', 21);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, buffer, 21) != 0)
		i++;
	j = i;
	close(fd);
	tab = (char**)malloc(sizeof(char*) * i + 1);
	if (!tab)
			return (0);
		tab[i] = 0;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (read(fd, buffer, 21) != 0)
	{
		tab[i] = ft_clean(tab[i], buffer);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		alst = ft_sort(tab[i], piece, alst);
		i++;
	}
	printf("1-%s\n2-%s\n3-%s\n4-%s\n", ft_itoa_piece(alst)[0], ft_itoa_piece(alst)[1],
		ft_itoa_piece(alst)[2],ft_itoa_piece(alst)[3]);

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