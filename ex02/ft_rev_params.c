#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	int j;
	char k;

	j = argc - 1;
	k = '\n';
	while (j >= 1)
	{
		i = 0;
		while (argv[j][i])
			i++;
		write(1, argv[j], i);
		write(1, &k, 1);
		j--;
	}
	return (0);
}