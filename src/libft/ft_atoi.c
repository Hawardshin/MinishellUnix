
#include "libft.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (result > 9223372036854775807 && sign == -1)
		return (0);
	else if (result > 9223372036854775807)
		return (-1);
	else
		return ((int)sign * result);
}
