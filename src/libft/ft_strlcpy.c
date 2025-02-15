
#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i + 1 < dstsize)
	{
		if (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		else
			break ;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
