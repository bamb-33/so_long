# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
#include <time.h>
# include "../libft/libft.h"

char getRandomChar(const char* charSet, int setSize) {

    // Generate a random index within the size of the set
    int randomIndex = rand() % setSize;

    // Return the randomly selected character
    return charSet[randomIndex];
}

int main(int ac , char *av[])
{
	char *str;
	char *str1;
	int fd = open ("1", O_RDONLY);
	int fd1 = open ("2", O_RDONLY);
	int fd2 = open ("new_xpm", O_CREAT | O_WRONLY);
	str = get_next_line(fd);
	str1 = get_next_line(fd1);
	for (int i = 0; str[i]; i++)
	{
		if (str1[i] == '#')
			write(fd2, &str[i], 1);
		else
			write(fd2, &str1[i], 1);
	}
}