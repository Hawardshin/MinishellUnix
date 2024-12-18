
#include"libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (ft_putchar_fd(s[i++], fd) == -1)
			return (-1);
	}
	return (i);
}
