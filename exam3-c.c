#include <stdio.h>
#include  <stdlib.h>
#include <malloc.h>
int main(int argc, char **argv)
{
   int avg(int x, int y) 
 {
  int a = x/y;  
  return a;       
 }
    int n, i;
    scanf ("%d",&n);

    int *m;
    m = (int*)malloc(n *sizeof(int));

    for (i=0; i< n; i++)
    { 
       m[i] = 2 + rand()%(5-2+1);
       printf("%d\n", m[i]);
    }

    int sum = 0;
    for (i=0; i<n; i++)
    sum += m[i];

    float a;
    a = avg(sum,n);

    printf("avg = %.1f\n", a);

    if (a >= 4.6)
   {
      printf("yes\n");
   }
  else
   {
      printf("no\n");
   }
   return 0;

}