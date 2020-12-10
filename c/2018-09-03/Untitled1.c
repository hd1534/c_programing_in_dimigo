#include <stdio.h>
int main()
{
    int a[2][3] = {1,2,3,4,5,6};

    printf("%d %d %d %d\n", a, a[0], &a, &a[0][0]);
    printf("%d %d %d %d\n", a+1, a[0]+1, &a+1, &a[0][0]+1);
    return 0;
}
