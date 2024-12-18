
#include"libft.h"

static int	check_len(long long num)
{
	int	len;

	len = 1;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num > 9)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*retstr;
	long long	num;

	num = n;
	len = check_len(num);
	retstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!retstr)
		return (0);
	retstr[len] = '\0';
	len--;
	if (num < 0)
	{
		retstr[0] = '-';
		num = num * -1;
	}
	if (num == 0)
		retstr[0] = '0';
	while (num)
	{
		retstr[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (retstr);
}
