#include <stdio.h>
int main()
{
    char name[10];
    int i;
    scanf("%s",name);
    for(i=0;i<10;i++)
        scanf("%c",name[i]);
    for(i=0;i<10;i++)
        printf("%c",name[i]);
}
