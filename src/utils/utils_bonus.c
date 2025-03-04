#include "../include/so_long.h"

static int	count_orders(int nmbr)
{
	int	i;

	i = 0;
	if (nmbr <= 0)
		i = 1;
	while (nmbr)
	{
		nmbr /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int nmbr)
{
	char	*str;
	int		len;

	len = count_orders(nmbr);
	str = malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (nmbr == 0)
		str[0] = '0';
	if (nmbr < 0)
	{
		str[0] = '-';
		if (nmbr == -2147483648)
		{
			str[--len] = '8';
			nmbr /= 10;
		}
		nmbr = -nmbr;
	}
	while (len-- && nmbr != 0)
	{
		str[len] = (nmbr % 10) + '0';
		nmbr /= 10;
	}
	return (str);
}
