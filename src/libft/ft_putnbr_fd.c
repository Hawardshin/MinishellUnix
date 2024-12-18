
#include "libft.h"

static void	nbr_recur(long long n, int fd)
{
	if (n > 9)
		nbr_recur(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	nbr_recur(nb, fd);
}
