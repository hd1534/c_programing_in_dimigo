# include <stdio.h>

int main()
{
    FILE *fp = fopen("data 9.txt","r" );
    FILE *fp2 = fopen("data 9.txt","r+");
    char ch;
    if (!fp)
        return 1;
    if (!fp2)
        return 1;
    while((ch=fgetc(fp))!=-1) //�������� ������ -1�� ch�� �ִ´�.
        if(ch!=32)
            fputc(ch,fp2);
    fclose(fp);
    fclose(fp2);
    return 1;
}
