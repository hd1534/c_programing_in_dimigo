#include <stdio.h>
int main()
{
    int a= 3;
    int *p=&a;
    printf("%d %x %p %x %d %x\n",&a,&a,&a,p,*p,p+1); // ����ּ� ���
    return 0;
}
