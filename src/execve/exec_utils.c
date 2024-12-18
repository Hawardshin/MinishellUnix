
#include "node.h"
#include "libft.h"

void	ft_all_close(t_main_node *px, int idx, int bef)
{
	int	i;

	i = 0;
	while (i < px->cmd_num)
	{
		if (i != idx && i != bef)
		{
			close(px->pipefd[i][0]);
			close(px->pipefd[i][1]);
		}
		i++;
	}
}

t_node	*mlst_find(int idx, t_main_node *data)
{
	t_node	*node;

	node = data->node_head;
	while (node)
	{
		if (node->idx == idx)
			return (node);
		node = node ->next;
	}
	return (NULL);
}
