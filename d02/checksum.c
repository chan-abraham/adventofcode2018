#include "checksum.h"

int		count(char *line, int count)
{
	//variable initialization
	int		index;
	int		j;
	int		length;
	int		currentCount;
	char	currentChar;

	index = 0;
	j = 0;
	length = 0;
	currentCount = 0;
	//gets length of the line
	length = ft_strlen(line);
	//the loop that iterates through line, and checks the uniqueness of each
	//character
	while (index < length)
	{
		j = 0;
		currentCount = 0;
		currentChar = line[index];
		while (j < length)
		{
			if (currentChar == line[j])
				currentCount++;
			j++;
			//returns 1 if it finds what we are looking for
			if ((j == length) && (currentCount == count))
				return (1);
		}
		index++;
	}
	return (0);
}

int		readfile(char *filename)
{
	//variable initialization
	char	*line;
	int		fd;
	int		twoCount;
	int		threeCount;
	int		checkSum;

	fd = 0;
	twoCount = 0;
	threeCount = 0;
	checkSum = 0;
	//opens file
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putendl("Error: Read");
		return (0);
	}
	//uses get next line to read the file line by line
	while (get_next_line(fd, &line))
	{
		//sets the nCount by sending it to count function with the string and
		//the number of repetitions we are looking for as the parameter
		twoCount = twoCount + count(line, 2);
		threeCount = threeCount + count(line, 3);
		//frees line
		ft_memdel((void **)&line);
	}
	close(fd);
	//calculates and prints what the checkSum is
	checkSum = twoCount * threeCount;
	printf("The checksum is: %d\n", checkSum);
	return (1);
}
//main function, sends the argument (in this case the input filename) to readfile
int		main(int argc, char **argv)
{
	if (argc)
		readfile(argv[1]);
	return (0);
}
