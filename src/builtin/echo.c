
#include "node.h"
#include "utils.h"
#include "libft.h"
#include "builtin.h"

void	ft_echo(char **cmd)
{
	int		i;
	char	newline[2];

	if (cmd_len(cmd) == 1)
	{
		printf("\n");
		return ;
	}
	i = 1;
	newline[0] = '\n';
	newline[1] = '\0';
	if (ft_strcmp(cmd[1], "-n") == 0)
	{
		i = 2;
		newline[0] = '\0';
	}
	while (i < cmd_len(cmd))
	{
		printf("%s", cmd[i]);
		i++;
		if (i != cmd_len(cmd))
			printf(" ");
	}
	printf("%s", newline);
}
