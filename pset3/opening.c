#include <stdio.h>
#define MAX 10

int main()
{
	FILE *f;
	int x;
	f=fopen("out", "w");
	if (!f)
		return 1;
	for (x = 1; x <= MAX; x++)
		fprintf(f, "%d\n", x);
	fclose(f);
	return 0;
}