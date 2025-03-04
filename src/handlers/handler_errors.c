#include "../include/so_long.h"

void	error_message(char *message)
{
	ft_printf("Error:\n%s\n", message);
	exit(1);
}

void	validate_hidden_file(char *filename)
{
	if (filename[0] == '.')
		error_message("You tried to open the HIDDEN file!");
}

void	validate_file_extension(char *filename)
{
	int		i;
	int		j;
	char	*extension;
	int		matched_characters;

	matched_characters = 0;
	i = 0;
	j = 0;
	extension = ".ber";
	while (filename[i])
	{
		if (extension[j] == filename[i])
		{
			j = 0;
			while (extension[j] == filename[i] && extension[j] && filename[i])
			{
				matched_characters++;
				j++;
				i++;
			}
		}
		i++;
	}
	if (matched_characters != 4)
		error_message("The EXTENSION must be .ber!");
}
