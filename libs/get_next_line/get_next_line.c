#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*read_line_from_file(char *line, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	while (!has_newline_character(line) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			if (line)
				free(line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_line_before_newline(char *str)
{
	int		index;
	char	*line;

	index = -1;
	while (str[++index])
		if (str[index] == '\n')
			break ;
	if (str[index] == '\n')
		index++;
	line = malloc(sizeof(char) * (index + 1));
	if (!line)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != '\n')
	{
		line[index] = str[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*get_line_after_newline(char *str)
{
	char	*remaining_line;
	int		start_index;
	int		line_length;
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			break ;
	if (str[i] == '\n')
		i++;
	start_index = i;
	line_length = (ft_strlen(str) - start_index);
	if (line_length == 0)
	{
		free(str);
		return (NULL);
	}
	remaining_line = ft_substr(str, start_index, line_length);
	free(str);
	return (remaining_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line_from_file(buffer, fd);
	if (!buffer || !*buffer)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = get_line_before_newline(buffer);
	buffer = get_line_after_newline(buffer);
	if (line[0] == '\n')
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (line);
}
