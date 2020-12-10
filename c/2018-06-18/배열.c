#include <stdio.h>
int main()
{
    char ch[101];
    int i;
    fgets(ch,100*sizeof(char),stdin);
    for(i=0;ch[i]!=0;i++);
    printf("%d",i);
}
