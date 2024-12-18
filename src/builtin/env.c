
#include "node.h"
#include "utils.h"
#include "libft.h"

static void	sort_env(t_env_main_node *env)
{
	int	i;
	int	j;

	i = env->count - 1;
	while (i >= 1)
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(env_of_idx(*env, j)->key, \
			env_of_idx(*env, j + 1)->key) > 0)
				swap_env(*env, j, j + 1);
			j++;
		}
		i--;
	}
}

static void	print_sorted_env(char *format)
{
	t_env			*p;
	t_env_main_node	env;

	env = env_dup(g_state.env_main_node);
	sort_env(&env);
	p = env.head;
	while (p)
	{
		if (p->value == NULL)
		{
			printf("%s%s\n", format, p->key);
			p = p->next;
			continue ;
		}
		printf("%s%s=\"%s\"\n", format, p->key, p->value);
		p = p->next;
	}
	free_all_env_main_node(&env);
}

static void	print_normal_env(char *format)
{
	t_env	*env;

	env = g_state.env_main_node.head;
	while (env)
	{
		if (env->value == NULL)
		{
			env = env->next;
			continue ;
		}
		printf("%s%s=%s\n", format, env->key, env->value);
		env = env->next;
	}
}

void	ft_env(int is_sort, char *format)
{
	if (is_sort)
	{
		print_sorted_env(format);
		return ;
	}
	print_normal_env(format);
}
