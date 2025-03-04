#include "get_next_line.h"

int	has_newline_character(const char *str)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		index;
	int		str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (len > str_len - start)
		len = str_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	index = 0;
	while (s[start + index] && index < len)
	{
		substr[index] = s[start + index];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (*(s1 + ++i))
		*(result + i) = *(s1 + i);
	j = -1;
	while (*(s2 + ++j))
		*(result + i + j) = *(s2 + j);
	*(result + i + j) = '\0';
	free(s1);
	return (result);
}
