
#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, s1, len + 1);
	return (result);
}
