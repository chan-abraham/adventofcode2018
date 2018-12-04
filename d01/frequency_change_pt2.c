//author: abchan
//github: chan-abraham

#include "frequency_change.h"

/*
** This function adds a new calculated result to the end of the linked list
** Because of the way linked lists work (to get to the last element you have
** to iterate through every element before it), I also used this opportunity
** to check to see if the result already happened. If so, it sets the checker
** variable to 1. In the end, it returns the checker int.
*/
int		ft_listaddend(t_node *head, int result)
{
	t_node *current;
	int checker;

	checker = 0;
	current = head;
	while (current->next != NULL)
	{
		if (current->save == result)
		{
				checker = 1;
				printf("The following frequency happened again: %d\n", result);
		}
		current = current->next;
	}
	current->next = (t_node *)malloc(sizeof(t_node));
	current->next->save = result;
	current->next->next = NULL;
	return (checker);
}

/*
** This function is where the file is read and the calculated results get sent
** to be saved to a linked list. In that saving process, it gets checked to see
** if a repeat happens, and if it did, checker gets returned as 1, otherwise
** checker gets returned as 0, signaling the main function that it needs to
** continue through the process of reading and calculating the file again.
*/

int		read_calc(char *filename, t_node *head)
{
	//variable initialization
	int		fd;
	int		number;
	char	*line;
	int		checker;
	int		result;
	t_node	*current;

	result = 0;
	current = head;
	fd = -1;
	number = 0;
	checker = 0;
	//opens the file
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putendl("Error: Read");
		return (0);
	}
	//uses get_next_line function, which reads the file line by line. stops
	//looping when checker is returned as 1
	while (get_next_line(fd, &line) && !checker)
	{
		//iterates to the end of the linked list
		while (current->next != NULL)
			current = current->next;
		//atoi number from read line
		number = ft_atoi(line);
		//calculates result from the previous calculated result
		result = current->save + number;
		//puts result in end of list and checks for repetitition
		checker = ft_listaddend(head, result);
		//frees line
		ft_memdel((void **)&line);
	}
	close(fd);
//	printlist(head);
	return (checker);
}
/*
** main function and set up of the linked list
*/
int		main(int argc, char **argv)
{
	/*
	** variable and linked list initialization
	** the index here is not necessary for this assignment, but its just for
	** my curiosity
	*/
	int		index;
	/*
	** checker is the variable to determine if a result has been found 0 for no,
	** and 1 for yes. it is the main variable being passed around to check if the
	** re-read needs to continue or it can stop (because a solution has been found)
	*/
	int		checker;
	t_node	*head;

	if ((head = (t_node *)malloc(sizeof(t_node))) == 0)
		return (0);
	head->save = 0;
	head->next = NULL;
	index = 0;
	checker = 0;
	//sends the filename to be read, and it will continue doing this until
	//checker returns 1 (or something else not zero, but that won't happen)
	while (!checker && argc)
	{
		checker = read_calc(argv[1], head);
		index++;
		//just some extra info for me to know how many time the file needed to be
		//read for the result to be found. in my given input, it had to read the
		//file 143 times before finding the result
		printf("%d\n", index);
	}
	return (0);;
}
