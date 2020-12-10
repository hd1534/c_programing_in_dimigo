# include <stdio.h>

int main()
{
    FILE *fp = fopen("data1.txt","r" );
    int c=0;
    if (fp == NULL)
        return 0;
    while(getc(fp)!=-1)
        c++;
    printf("%d",c);
    fclose(fp);
    return 0;
}
