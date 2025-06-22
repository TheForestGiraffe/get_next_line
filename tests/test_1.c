#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*line;
	
	fd = open("read_error.txt", O_RDONLY);

	if (fd < 0)
	{
		printf("Could not open one of the files.\n");
		return (-1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("==> %s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

