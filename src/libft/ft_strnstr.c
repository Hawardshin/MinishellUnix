
#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ni;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		ni = 0;
		while (haystack[i + ni] && haystack[i + ni] == needle[ni]
			&& i + ni < len)
		{
			ni++;
			if (!needle[ni])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
