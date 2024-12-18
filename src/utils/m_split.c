
#include "node.h"
#include "utils.h"
#include "libft.h"

static long long	len_count(char *str, char c)
{
	long long	count;
	long long	i;

	count = 0;
	i = 0;
	while (!str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		count++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static long long	len_into(char *str, char c)
{
	long long	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	move_if_charset(char **str, char c)
{
	while (**str && **str == c)
		(*str)++;
}

static void	div_result(char *str, char **result, char c)
{
	long long	i;
	long long	k;

	i = 0;
	while (*str)
	{
		k = 0;
		result[i] = malloc(sizeof(char) * (len_into(str, c) + 1));
		if (!result[i])
			print_error(0, NULL);
		while (*str && *str != c)
			result[i][k++] = *str++;
		result[i][k] = '\0';
		i++;
		move_if_charset(&str, c);
	}
	result[i] = 0;
}

char	**ft_msplit(char *str, char c)
{
	char		**result;
	char		*tmp;

	tmp = str;
	if (!str)
		print_error(0, NULL);
	result = (char **)malloc(sizeof(char *) * (len_count(str, c) + 1));
	if (!result)
		print_error(0, NULL);
	move_if_charset(&str, c);
	div_result(str, result, c);
	my_free((void **)&tmp);
	return (result);
}
