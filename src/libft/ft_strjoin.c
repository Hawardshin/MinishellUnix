
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*retstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	retstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!retstr)
		return (0);
	while (s1[i])
	{
		retstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		retstr[i + j] = s2[j];
		j++;
	}
	retstr[i + j] = '\0';
	return (retstr);
}
