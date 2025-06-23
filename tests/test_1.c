#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*line;
	int		c;
	
	c = 1;
	fd = open("test_files/1char.txt", O_RDONLY);
	printf("fd: %i\n", fd);
	if (fd < 0)
	{
		printf("Could not open the file.\n");
		return (-1);
	}		

	while (c < 3)
	{
		line = get_next_line(fd);
		printf("$%s$", line);
		free(line);
		c++;
	}

	close(fd);
	line = get_next_line(fd);
	printf("$%s$\n", line);
	free(line);

	fd = open("test_files/1char.txt", O_RDONLY);
	printf("fd: %i\n", fd);
	while (line || c < 5)
	{
		line = get_next_line(fd);
		printf("$%s$", line);
		free(line);
		c++;
	}
	close(fd);
	return (0);
}

