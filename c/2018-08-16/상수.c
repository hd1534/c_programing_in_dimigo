#include<stdio.h>
#define pi 3.14
int main()
{
    int r;
    const int *const p = &r;
    const double rate = 0.8;
    scanf("%d",&r);
    printf("%.2lf\n%d\n",r*r*pi,*p);
    r=1;
    printf("%d",*p);
    //*p = 2;
    return 0;
}
