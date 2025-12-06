# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct node{
	int		num;
	struct node	*next;
} node;

void	print_list(node *Hlist)
{
	if (Hlist == NULL)
		return ;
	node	*ptr = Hlist;
	while (ptr)
	{
		printf("-->%i<--\n", ptr->num);
		ptr = ptr->next;
	}
}

void	free_list(node *Hlist)
{
        if (Hlist == NULL)
                return ;
	node	*next;
        node    *ptr = Hlist;
        while (ptr)
        {
		next = ptr->next;
		free(ptr);
                ptr = next;
        }
}


int	main(int ac, char **av)
{
	int	i = 0;
	node	*Hlist = NULL;
	
	while (i < ac)
	{
		node *n = malloc(sizeof(node));
		if (n == NULL)
			return (free_list(Hlist), (1));
		n->num = atoi(av[i]);
		n->next = Hlist;
		Hlist = n;
		i++;
	}
	
	print_list(Hlist);
	free_list(Hlist);
	return (0);
}
