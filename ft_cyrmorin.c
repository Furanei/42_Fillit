/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cyrmorin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 23:55:46 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/20 00:43:57 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <fcntl.h>


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

/*
int	ft_isvalid(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != 0)
	{

	}

}
*/
int	main(int argc, char **argv)
{
	int fd;
	int i;
	char buffer[21];
	char **tab;

	i = 0;
	if (argc != 2)
		return (0);
	ft_memset(buffer, ' ', 21);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, buffer, 21) != 0)
		i++;
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
	return (0);
}