//author: abchan
//github: chan-abraham

#include "frequency_change.h"

int		read_calc(char *filename)
{
	int		fd;
	int		number;
	char	*line;
	int		result;

	result = 0;
	fd = -1;
	number = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putendl("Error: Read");
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		number = ft_atoi(line);
		result = result + number;
		ft_memdel((void **)&line);
	}
	close(fd);
	return (result);
}

int		main(int argc, char **argv)
{
	int		result;

	result = 0;
	if (argc > 0)
	{
		result = read_calc(argv[1]);
		printf("%d\n", result);
	}
	return (0);;
}
