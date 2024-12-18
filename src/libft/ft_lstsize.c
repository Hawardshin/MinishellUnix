
#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 1;
	if (!lst)
		return (0);
	while (lst -> next != NULL)
	{
		size++;
		lst = lst -> next;
	}
	return (size);
}
