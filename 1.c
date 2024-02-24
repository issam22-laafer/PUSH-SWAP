#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*next;
}				t_data;

void	insert_end(t_data *head, int data)
{
	t_data	*node;
	t_data	*tmp;

	node = malloc(sizeof(t_data));
	node->data = 88;
	node->next = NULL;
	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
}
int	main(void)
{
	t_data *head;

	head = malloc(sizeof(t_data));

	head->data = 15;
	head->next = NULL;

	t_data *current;

	current = malloc(sizeof(t_data));
	current->data = 20;
	current->next = NULL;

	head->next = current;
	current = malloc(sizeof(t_data));
	current->data = 90;
	current->next = NULL;
	head->next->next = current;

	insert_end(head, 88);
	t_data *temp;
	temp = head;
	int i;
	i = 0;
	while (temp)
	{
		printf("%d\n", temp->data);
		i++;
		temp = temp->next;
	}
	printf("The number of nodes is %d", i);
}