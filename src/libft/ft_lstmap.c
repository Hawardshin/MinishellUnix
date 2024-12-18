
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*head;

	if (lst && f)
	{
		new_node = NULL;
		head = new_node;
		while (lst)
		{
			new_node = ft_lstnew(f(lst->content));
			if (!new_node)
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, new_node);
			lst = lst-> next;
		}
		return (head);
	}
	return (NULL);
}
