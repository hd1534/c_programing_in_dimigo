# include <stdio.h>

int main()
{
    FILE *fp = fopen("data 7.txt","r" );
    char ch;
    int c=0;
    if (fp == NULL)
        return 0;
    while((ch=fgetc(fp))!=-1) //�������� ������ -1�� ch�� �ִ´�.
        if(ch=='g')
            if((ch=fgetc(fp))!=-1 && ch=='o')
                if((ch=fgetc(fp))!=-1 && ch=='g')
                {
                    c++;
                    fseek(fp,-2,SEEK_CUR);
                }
                else;
            else
                    fseek(fp,-1,SEEK_CUR);
    printf("%d",c);
    fclose(fp);
    return 0;
}
