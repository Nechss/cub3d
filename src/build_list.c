#include "cub3D.h"

static t_maplist	*create_node(char *line)
{
	t_maplist	*new_node;

	new_node = (t_maplist *)malloc(sizeof(t_maplist));
	if (!new_node)
		return (NULL);
	new_node->line = ft_strdup(line);
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_node(char *line, t_maplist **head)
{
	t_maplist	*new_node;
	t_maplist	*temp;

	new_node = create_node(line);
	if (!new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		// new_node->prev = NULL;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;

		}
		temp->next = new_node;
		new_node->prev = temp;
	}
}