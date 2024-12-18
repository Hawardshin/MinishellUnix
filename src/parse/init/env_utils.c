
#include "node.h"
#include "libft.h"
#include "utils.h"

static t_env	*search_env(char *key)
{
	t_env	*ret;

	ret = g_state.env_main_node.head;
	while (ret)
	{
		if (ft_strcmp(key, ret->key) == 0)
			break ;
		ret = ret->next;
	}
	return (ret);
}

static int	check_key(char *key, char *value)
{
	if (key == NULL)
	{
		ft_eprintf("minishell: export: `=%s': not a valid identifier\n", value);
		g_state.exit_code = -1;
		return (1);
	}
	if (search_env(key) != NULL)
	{
		free(search_env(key)->value);
		search_env(key)->value = value;
		free(key);
		return (1);
	}
	return (0);
}

void	env_lst_add_back(char *key, char *value)
{
	t_env	*node;

	if (check_key(key, value))
		return ;
	node = malloc(sizeof(t_env));
	g_state.env_main_node.count++;
	if (!node)
		print_error(0, NULL);
	ft_memset(node, 0, sizeof (t_env));
	node->key = key;
	node->value = value;
	if (g_state.env_main_node.head)
	{
		g_state.env_main_node.tail->next = node;
		node->prev = g_state.env_main_node.tail;
		node->next = NULL;
	}
	else
		g_state.env_main_node.head = node;
	g_state.env_main_node.tail = node;
}

void	connect_two_node(t_env *front, t_env *back)
{
	if (front == NULL && back == NULL)
		return ;
	if (front == NULL)
	{
		back->prev = NULL;
		return ;
	}
	if (back == NULL)
	{
		front->next = NULL;
		return ;
	}
	front->next = back;
	back->prev = front;
}

void	env_lst_delete(char *key)
{
	t_env	*del;

	del = search_env(key);
	if (del == NULL)
		return ;
	connect_two_node(del->prev, del->next);
	free(del->key);
	free(del->value);
	free(del);
	g_state.env_main_node.count--;
}
