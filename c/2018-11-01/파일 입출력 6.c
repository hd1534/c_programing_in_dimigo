# include <stdio.h>

int main()
{
    FILE *fp = fopen("data 6.txt","r" );
    char ch;
    if (fp == NULL)
        return 0;
    fseek(fp,-1,SEEK_END);
    while((ch=fgetc(fp))!=-1) //�������� ������ -1�� ch�� �ִ´�.
    {
        printf("%c",ch);
        fseek(fp,-2,SEEK_CUR);
    }
    fclose(fp);
    return 0;
}
