# include <stdio.h>
# include <string.h>

int main()
{
    FILE *fp = fopen("data1.txt","r+" );
    char ch,tmp;
    int c=0;
    if (fp == NULL)
        return 0;
    tmp=getc(stdin);
    while((ch = getc(fp))!=-1)
    {
        if (ch == tmp)
            c++;
    }
    printf("%d",c);
    fclose(fp);
    return 0;
}
