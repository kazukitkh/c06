#include <stdlib.h>
#include <unistd.h>

void	ft_quick_sort(char **argv, int *nbr)
{
	int	pl;
	int	pr;
	int kt;
	char *s;

	pl = nbr[nbr[0]];	
	pr = nbr[nbr[0] + 1];
	kt = nbr[nbr[0] + 6];
	while (pl <= pr)
	{
		while (argv[pl][kt] <= argv[nbr[0] / 2][kt])
			pl++;
		while (argv[nbr[0] / 2][kt] <= argv[pr][kt])
			pr--;
		if (pl <= pr)
		{
			s = argv[pl];
			argv[pl] = argv[pr];
			argv[pr] = s;
			pl++;
			pr--;
		}
	}
	if (nbr[nbr[0]] < pr)
		ft_quick_sort(argv, left, pr, nbr);
	if (nbr[nbr[0] + 1] < right)
		ft_quick_sort(argv, pl, right, nbr);
	
}

int main(int argc, char *argv[])
{
	int		nbr[argc + 7];
	char	k;

	nbr[argc] = 1;
	nbr[argc + 1] = argc - 1;
	nbr[0] = 1;
	nbr[argc + 3] = 1;
	nbr[argc + 4] = 1;
	nbr[argc + 5] = 1;//argvの全ての文字列の最大桁数
	nbr[argc + 6] = 0;//桁の変数
	while (nbr[0] < argc)
	{
		nbr[nbr[0]] = nbr[0];
		nbr[0]++;
	}
	while (nbr[argc + 3] < argc)
	{
		nbr[argc + 2] = 0;
		while (argv[nbr[argc + 4]][nbr[argc + 2]])
			nbr[argc + 2]++;
		if (nbr[argc + 5] < nbr[argc + 2])
			nbr[argc + 5] = nbr[argc + 2];
		nbr[argc + 3]++;
	}//桁数判定
	while (nbr[argc + 6] < nbr[argc + 3])
	{
		ft_quick_sort(argv, left, right, nbr);
		nbr[argc + 6]++;
	}
	k = '\n';
	while (nbr[0] < argc)
	{
		nbr[1] = 0;
		while (argv[nbr[0]][nbr[1]])
			nbr[1]++;
		write(1, argv[nbr[0]], nbr[1]);
		write(1, &k, 1);
		nbr[0]++;
	}
	return (0);
}