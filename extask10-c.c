
#include <stdio.h>
#include <stdlib.h>

int main()
{

	int *tab, rows, cols;
    printf("количество строк: ");
    scanf("%d", &rows);
    printf("количество колонок: ");
    scanf("%d", &cols);
    tab = (int*)malloc(rows*cols * sizeof(int));

	#define mark0 1
	#define mark1 10

    float m_max = 1;

	for(int y = 0; y < rows; y++)
		for(int x = 0; x < cols; x++)
			*(tab+y*cols+x) = mark0 + rand() % (mark1 - mark0 + 1);

	float avg[rows];

    	printf("num");
	for(int x = 0; x < cols; x++)
		printf("\t%d", x + 1);

    printf("\tmax");
	printf("\tavg\n");

	for(int y = 0; y < rows; y++)
	{
        printf("%d", y + 1);
		int s = 0;
        m_max = 1;
		for(int x = 0; x < cols; x++)
        {
			printf("\t%d",*(tab+y*cols+x));
            
            s += *(tab+y*cols+x);
            if (*(tab+y*cols+x) > m_max)
            m_max = *(tab+y*cols+x); 
        }
		avg[y] = s / (float)cols;
        printf("\t%.1f", m_max);
        printf("\t%.1f\n", avg[y]);
	}

return 0;
}
