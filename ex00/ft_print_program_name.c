#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (argv[argc - 1][i])
		i++;
	write(1, argv[0], i);
	return (0);
}