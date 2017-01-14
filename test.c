/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:16:41 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/14 16:01:23 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_index(char *s, int nb, int i)
{
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (nb == 0)
				return (i);
			nb--;
		}
		i++;
	}
	return (0);
}

int		ft_sort(char *s)
{
	// int		a;
	// int		b;
	// int		c;
	// int		d;
	int 	w;
	int		t[4];

	// if (!(s[0] == '#' || s[1] == '#'))
	// {
	// 	printf("error");
	// 	return ;
	// }
	t[0] = ft_index(s, 0, 0);
	t[1] = ft_index(s, 1, 0);
	t[2] = ft_index(s, 2, 0);
	t[3] = ft_index(s, 3, 0);
	printf("%d\n%d\n%d\n%d\n", t[0], t[1], t[2], t[3]);
	w = (t[0] + 1 == t[1] || t[0] + 4 == t[1]) + (t[0] + 1 == t[2] ||
		t[0]+ 4 == t[2]) + (t[0] + 1 == t[3] || t[0] + 4 == t[3]) + (t[1]
		+ 1 == t[2] || t[1] + 4 == t[2]) + (t[1] + 1 == t[3] || t[1] + 4
		== t[3]) + (t[2] + 1 == t[3] || t[2] + 4 == t[3]);
	printf("ok :%d\n", w);
	if (w == 4)
		return (2);
	if (w == 3)
		return (1);
	return (0);

}

int		main(int ac, char **av)
{
	ft_sort(av[1]);
	return 0;
}