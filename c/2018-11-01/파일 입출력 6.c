# include <stdio.h>

int main()
{
    FILE *fp = fopen("data 6.txt","r" );
    char ch;
    if (fp == NULL)
        return 0;
    fseek(fp,-1,SEEK_END);
    while((ch=fgetc(fp))!=-1) //읽을것이 없으면 -1을 ch에 넣는다.
    {
        printf("%c",ch);
        fseek(fp,-2,SEEK_CUR);
    }
    fclose(fp);
    return 0;
}
