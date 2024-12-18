
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = (void *)malloc(size * count);
	if (!result)
		return (0);
	ft_bzero(result, size * count);
	return (result);
}
