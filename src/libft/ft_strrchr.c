
#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((char)c == s[i])
		return ((char *) &s[i]);
	while (i)
	{
		i--;
		if ((char)c == s[i])
			return ((char *) &s[i]);
	}
	return (0);
}
