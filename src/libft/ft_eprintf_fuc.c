
#include "libft.h"

int	eprint_unsigned_int(va_list ap)
{
	char	*to_print;
	int		read_len;

	to_print = ft_lltoa(va_arg(ap, unsigned int));
	if (!to_print)
		return (-1);
	read_len = ft_putstr_fd(to_print, 2);
	free(to_print);
	to_print = NULL;
	return (read_len);
}

int	eprint_hex_lower(va_list ap)
{
	return (ft_eputnbr_base(va_arg(ap, unsigned int), "0123456789abcdef"));
}

int	eprint_hex_upper(va_list ap)
{
	return (ft_eputnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
}

int	eprint_addr(va_list ap)
{
	void	*p;

	p = va_arg(ap, void *);
	return (ft_eprint_addr(p));
}

int	eprint_dec_int(va_list ap)
{
	char	*to_print;
	int		read_len;

	to_print = ft_lltoa(va_arg(ap, int));
	if (!to_print)
		return (-1);
	read_len = ft_putstr_fd(to_print, 2);
	free(to_print);
	to_print = NULL;
	return (read_len);
}
