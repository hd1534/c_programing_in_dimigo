#include <stdio.h>
int main()
{
    int a[3][2]={1,2,3,4,5,6};
    int *ap;
    int i=6;
    ap=a;
    while(--i>=0)
        printf("%d ",ap[i]);
    printf("\n%d %d",ap[1],ap[0]+1);
    return 0;
}
