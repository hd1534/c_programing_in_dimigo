# include <stdio.h>
# include <string.h>

int main()
{
    FILE *fp = fopen("data3.txt","r+" );
    char ch;
    int c=0;
    if (fp == NULL)
        return 0;
    while((ch=getc(fp))!=-1)
    {
        if(ch=='b')
            if((ch=getc(fp))=='e')
                c++;
    }
    printf("%d",c);
    fclose(fp);
    return 0;
}
