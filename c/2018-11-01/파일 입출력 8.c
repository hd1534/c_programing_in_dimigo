# include <stdio.h>

int main()
{
    FILE *fp = fopen("data 8.txt","r+" );
    char ch,input,c;
    if (fp == NULL)
        return 0;
    scanf("%c %c",&input,&c);
    while((ch=fgetc(fp))!=-1) //�������� ������ -1�� ch�� �ִ´�.
    if(ch==input)
    {
        fseek(fp,-1,SEEK_CUR);
        fprintf(fp,"%c",c);
        fseek(fp,0,SEEK_CUR);
    }
    fclose(fp);
    return 0;
}
