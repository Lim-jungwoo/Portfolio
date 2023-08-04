#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	*test1 = (int *)malloc(sizeof(int) * 5);
	int	**test2 = (int **)malloc(sizeof(int *) * 5);

	for (int i = 0; i < 10000; i++)
		test2[i] = (int *)malloc(sizeof(int) * 5);
	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < 10000; j++)
			test2[i][j] = i + j;
	}
	printf("test2 : %d\n", test2[9999][9999]);
	printf("test1 : %d\n", test1[5000]);
	for (int i = 0; i < 10000; i++)
		test1[i] = i;
	printf("test1[9999] : %d\n", test1[9999]);
}