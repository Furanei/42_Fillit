#include "fillit.h"

static char	*ft_clean(char *str, char *buffer)
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

char	**ft_read_and_clean(int argc, char **argv)
{
	int		i;
	int		fd;
	char	**tab;
	char	buffer[21];

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
	return (tab);
}