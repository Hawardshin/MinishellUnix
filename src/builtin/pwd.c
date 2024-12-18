
#include "utils.h"
#include "libft.h"

void	ft_pwd(void)
{
	char	*p;

	p = getcwd(NULL, 0);
	if (p == NULL)
		print_error(0, NULL);
	printf("%s\n", p);
	free(p);
}
