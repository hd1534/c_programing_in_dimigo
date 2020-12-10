#include<stdio.h>
int main()
{
    int m,i,max=0;
    int arr[100];
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d",&arr[i]);
    for (i=0;i<m;i++)
        if(max<arr[i])
            max=arr[i];
        printf("%d\n",max);
    return 0;
}
