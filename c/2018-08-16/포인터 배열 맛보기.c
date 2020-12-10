#include<stdio.h>
int main()
{
    char arr[5]="¾È³ç";
    printf("0x%x : 0x%x\n",arr,&arr[0]);
    printf("%c%c",arr[0],arr[1]);
    return 0;
}
