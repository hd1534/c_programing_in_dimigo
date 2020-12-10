#include <stdio.h>
void swap(int *a,int *b)
{
    int tmp;
    tmp = *a;
    *a=*b;
    *b=tmp;
    return;
}
void cal(int a, int b, int *sum,int *mul)
{
    *sum = a+b;
    *mul = a*b;
}
int main()
{
    int a,b,sum,mul;
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    cal(a,b,&sum,&mul);
    printf("swap : %d %d\n",a,b);
    printf("sum :%d mul : %d",sum,mul);
    return 0;
}
