#include <stdio.h>

int main(void)
{
	for (int x = 1; x < 101; x++)
	{
		printf("%d\n", x);
		if (x % 3 == 0)
		{
			if (x % 5 == 0)
				printf("CracklePop!\n");

			else
				printf("Crackle!\n");
		}

		else if (x % 5 == 0)
			printf("Pop!\n");
	}
}