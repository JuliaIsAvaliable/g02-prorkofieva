#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
float x0, y0;
printf("x0, y0: "); // коорд пушки
scanf("%f %f", &x0, &y0);

float v0, a;
printf("v0, a: "); // скорость, угол
scanf("%f %f", &v0, &a);

float ra = a * (float) M_PI / 180.0f; // угол в радианы

float v0x = cosf(ra) * v0; // в дек сист
float v0y = sinf(ra) * v0; //

#define g 9.8f
//float x = x0 + v0x * t; 
//float y = y0 + v0y * t - g * t * t / 2.0f; равноускор движ

//0 = y0 + v0y * t - g / 2.0f * t * t;
//-g / 2.0f * t * t + v0y * t + y0 = 0


FILE *pf ;
    pf = fopen("extask03-c.txt", "w");

float d = v0y * v0y + 4.0f * (g / 2.0f) * y0; // дискр
fprintf (pf,"d = %f\n", d);

float t1 = (-v0y - sqrtf(d)) / (2.0f * (-g / 2.0f)); // корни
float t2 = (-v0y + sqrtf(d)) / (2.0f * (-g / 2.0f));
printf("t1 = %f, t2 = %f\n", t1, t2);

float t = 0.0f;
float x, y;

#define eps 0.01f

float a1 = t1 - 1;
float b1 = t1 + 1;



while (1)
{
	if (b1 - a1 < 2*eps)
	{
		//-g / 2.0f * t * t + v0y * t + y0 = 0
	x = x0 + v0x * t;
	y = y0 + v0y * t - g * t * t / 2.0f;

	fprintf(pf, "%f %f %f\n", t, x, y);
	t += eps;

	float fa = -g / 2.0f * a1 * a1 + v0y * a1 + y0;
	float fb = -g / 2.0f * b1 * b1 + v0y * b1 + y0;

	float c = (a1 + b1)/2;
	float fc = -g / 2.0f * c * c + v0y * c + y0;

	if (fa < 0 && fc < 0 && fb > 0)
	a1 = c;
	if (fa < 0 && fc > 0 && fb > 0)
	b1 = c;
	fprintf(pf, "c = %f\n", c);

	}
	
	else
	break;

}


//fprintf(pf, "t = %f, x = %f, y = %f\n", t, x, y);
fclose(pf);


return 0;
}