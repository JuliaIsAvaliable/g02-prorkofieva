#include <stdio.h>
#include  <stdlib.h>

int main()
{
    #define m 12
    int s[m];
    float t[m];

    #define s_l 1000
    #define s_h 5000
    
    int y_s = 0;

    printf("months  ");
    int s_max = 1000, s_min = 5000;

    for (int i = 0; i < m; i++)
    {
        s[i] = s_l + rand() % (s_h - s_l + 1);
        printf("% 6d", (i + 1));
        y_s += s[i];
        if (s[i] > s_max)
        s_max = s[i];
        if (s[i] < s_min)
        s_min = s[i];
    }
    printf("\n");

    printf("salary  ");
    for (int i = 0; i < m; i++)
        printf("% 6d", s[i]);
    printf("\n");

    float y_t = 0.0f;
    printf("Tax     ");
    for (int i = 0; i < m; i++)
    {
        t[i] = s[i] * 0.02f;
        printf("% 6.1f", t[i]);
        y_t += t[i];
    }
    printf("\n");

    float y_a = y_s / (float) m;
    float y_avgt = y_t / m;
    printf("deviat  ");
        for (int i = 0; i < m; i++)
    {
        t[i] = s[i] * 0.02f;
        float e = t[i] - y_avgt; 
        printf("% 6.1f", e);
        y_t += t[i];
    }

    printf("\n");
    printf("year_sum = %d\n", y_s);
    printf("year_avg = %.2f\n", y_a);
    printf("year_tax = %.2f\n", y_t);
    printf("year_avg_tax = %.2f\n", y_avgt);
    printf("salary_max = %d\n", s_max);
    printf("salary_min = %d\n", s_min);

    return 0;
}