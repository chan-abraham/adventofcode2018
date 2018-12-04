#include "checksum.h"

//where the scanning happens
int		find_unique(char **allStrings)
{
	int		i;
	int		j;
	int		k;
	int		countDifferent;

	i = 0;
	j = 0;
	k = 0;
	countDifferent = 0;
	//in this set of loops, it iterates through each element of the 2D array
	//and compares them
	while (i < 250)
	{
		k = i + 1; //prevents double checking
		while (k < 250)
		{
			//goes through each char of the allstrings[i] and allstrings[k]
			//sees how many characters are different. Since we are only looking
			//for one char difference, if its more than one, it can stop scanning
			while (j < 26 && countDifferent < 2)
			{
				if (allStrings[i][j] != allStrings[k][j])
					countDifferent++;
				j++;
			}
			//breaks loop and returns 1 if the solution is found
			if (countDifferent == 1)
			{
				printf("%s\n%s\n", allStrings[i], allStrings[k]);
				return (1);
			}
			//resets j and countDifferent and iterates k
			j = 0;
			countDifferent = 0;
			k++;
		}
		//iterates i
		i++;
	}
	return (0);
}

//reads the file, and saves each string in a 2D array
int		readfile(char *filename)
{
	char	*line;
	int		fd;
	char	**allStrings;
	int		i;
	int		j;

	fd = 0;
	i = 0;
	j = 0;
	//allocates memory for the 2D array (250 because we know there are 250 lines)
	allStrings = (char **)ft_memalloc(sizeof(char *) * 250);
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putendl("Error: Read");
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		//allocates memory for each line (26 because we know there are 26 chars)
		allStrings[i] = (char *)ft_memalloc(sizeof(char) * 26);
		//copies from line to the array in the 2D array
		while (j < 26)
		{
			allStrings[i][j] = line[j];
			j++;
		}
		//frees the line
		ft_memdel((void **)&line);
		//iterates to the next 2D index
		i++;
		//resets j position
		j = 0;
	}
	close(fd);
	/*
	** sends the 2D array to the scanning function
	** the only reason i made j=result of find_unique is because I need the loop to
	** stop running and return when it finds the solution. I can't remember if a
	** I can make a void function stop by returning, so i just made it an int
	** int function. kinda lazy but w/e
	*/
	j = find_unique(allStrings);
	return (1);
}
//main
int		main(int argc, char **argv)
{
	if (argc)
		readfile(argv[1]);
	return (0);
}
