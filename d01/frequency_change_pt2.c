//author: abchan
//github: chan-abraham

#include "frequency_change.h"
/*
void	printlist(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		printf("list says: result = %d\n", current->save);
		current = current->next;
	}
}
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
/*	printf("beginlist\n");
	printlist(head);
	printf("endlist\n");	*/
	return (checker);
}

int		read_calc(char *filename, t_node *head)
{
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
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putendl("Error: Read");
		return (0);
	}
	while (get_next_line(fd, &line) && !checker)
	{
		while (current->next != NULL)
			current = current->next;
		number = ft_atoi(line);
		result = current->save + number;
		checker = ft_listaddend(head, result);
//		printf("The current Frequency is: %d\n", result);
		ft_memdel((void **)&line);
	}
	close(fd);
//	printlist(head);
	return (checker);
}

int		main(int argc, char **argv)
{
	int		index;
	int		checker;
	t_node	*head;

	if ((head = (t_node *)malloc(sizeof(t_node))) == 0)
		return (0);
	head->save = 0;
	head->next = NULL;
	index = 0;
	checker = 0;
	while (!checker && argc)
	{
		checker = read_calc(argv[1], head);
		index++;
		printf("%d\n", index);
	}
	return (0);;
}
