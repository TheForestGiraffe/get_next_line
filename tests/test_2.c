#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd_1;
	int		fd_2;
	int		fd_3;
	int		fd_4;
	int		fd_5;
	char	*line;
	
	fd_1 = open("get_next_line.c", O_RDONLY);
	fd_2 = open("empty", O_RDONLY);
	fd_3 = open("1char.txt", O_RDONLY);
	fd_4 = open("lorem.txt", O_RDONLY);
	fd_5 = open("lorem_500mb_100mb_lines.txt", O_RDONLY);

	if ((fd_1 < 0) || (fd_2 < 0) || (fd_3 < 0) || (fd_4 < 0) || (fd_5 < 0))
	{
		printf("Could not open one of the files.\n");
		return (-1);
	}
	printf("1 ==> %s", get_next_line(fd_1));
	printf("1 ==> %s", get_next_line(fd_1));
	printf("1 ==> %s", get_next_line(fd_1));
	printf("4 ==> %s", get_next_line(fd_4));
	printf("2 ==> %s\n", get_next_line(fd_2));
	printf("3 ==> %s", get_next_line(fd_3));
	printf("4 ==> %s", get_next_line(fd_4));
	printf("4 ==> %s", get_next_line(fd_4));
	printf("4 ==> %s", get_next_line(fd_4));
	line = get_next_line(fd_5);
	while (line)
	{
		printf("5 ==> %s", line);
		free(line);
		line = get_next_line(fd_5);
	}
	printf("3 ==> %s\n", get_next_line(fd_3));
	printf("4 ==> %s", get_next_line(fd_4));
	printf("1 ==> %s", get_next_line(fd_1));
	printf("2 ==> %s\n", get_next_line(fd_2));
	printf("3 ==> %s\n", get_next_line(fd_3));
	printf("4 ==> %s", get_next_line(fd_4));
	printf("4 ==> %s", get_next_line(fd_4));
	printf("1 ==> %s", get_next_line(fd_1));
	printf("4 ==> %s", get_next_line(fd_4));
	printf("4 ==> %s", get_next_line(fd_4));
	printf("4 ==> %s", get_next_line(fd_4));
	printf("4 ==> %s", get_next_line(fd_4));
	printf("4 ==> %s", get_next_line(fd_4));

	line = get_next_line(fd_1);
	while (line)
	{
		printf("1 ==> %s", line);
		free(line);
		line = get_next_line(fd_1);
	}

	return (0);
}

