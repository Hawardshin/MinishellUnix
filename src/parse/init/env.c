
#include "node.h"
#include "utils.h"
#include "libft.h"

char	*get_env(char *key)
{
	t_env	*e_node;

	e_node = g_state.env_main_node.head;
	while (e_node)
	{
		if (ft_strcmp(e_node->key, key) == 0)
			return (e_node->value);
		else
			e_node = e_node->next;
	}
	return (NULL);
}

static void	make_key_value(int i, char **envp)
{
	char	*key;
	char	*value;

	key = malloc(i + 1);
	if (!key)
		print_error(0, NULL);
	key[0] = '\0';
	ft_strlcpy(key, *envp, i + 1);
	key[i] = '\0';
	i++;
	value = malloc(ft_strlen((*envp) + i) + 1);
	if (!value)
		print_error(0, NULL);
	ft_strlcpy (value, (*envp) + i, ft_strlen((*envp) + i) + 1);
	value[ft_strlen((*envp) + i)] = '\0';
	env_lst_add_back(key, value);
}

void	init_g_state(char **envp)
{
	t_env	*env_node;
	int		i;

	while (*envp)
	{
		env_node = malloc(sizeof(t_env));
		if (!env_node)
			print_error(0, NULL);
		ft_memset(env_node, 0, sizeof(t_env));
		i = -1;
		while ((*envp)[++i])
		{
			if ((*envp)[i] == '=')
			{
				make_key_value(i, envp);
				break ;
			}
		}
		envp++;
	}
}
