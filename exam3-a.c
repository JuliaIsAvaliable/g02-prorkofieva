#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(int argc, char **argv)
{

int N, i;
int *a;
scanf("%d", &N);
a = (int*)malloc(N * sizeof(int));

for (i = 0; i < N; i++)
	{
		a[i] = 2 + rand() % (5 - 2 + 1);
		printf("%d \n", a[i]);
	}

int sum = 0;
for (i = 0; i < N; i++)
		sum = sum + a[i];

float sred;
sred = sum / N;

if(sred >= 4.6)
		printf("Ученик поступит в университет\n");
else
		printf("Ученик не поступит в университет\n");

return 0;
}