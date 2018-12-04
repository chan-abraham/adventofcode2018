//author: abchan
//github: chan-abraham

#include "frequency_change.h"

//returns the calculated result
int		read_calc(char *filename)
{
	//variable initialization
	int		fd; //file descriptor
	int		number; //the number saved as int
	char	*line; //the pointer to the line that is being read
	int		result;

	result = 0;
	fd = -1;
	number = 0;
	//opens the file, and saves the file descriptor
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putendl("Error: Read");
		return (0);
	}
	//the get_next_line function is in libft
	//it reads a file line by line, and saves the read line to "line"
	while (get_next_line(fd, &line))
	{
		number = ft_atoi(line); //converts the read number from char to int
		result = result + number; //adds the read number to the saved result
		ft_memdel((void **)&line); //frees the line malloced by get_next_line
	}
	close(fd);
	return (result);
}

//main function
int		main(int argc, char **argv)
{
	//variable initialization
	int		result;

	result = 0;
	//passes the function, in this case the name of the input filename
	//into the function
	if (argc > 0)
	{
		result = read_calc(argv[1]);
		printf("%d\n", result);//prints the result
	}
	return (0);;
}
