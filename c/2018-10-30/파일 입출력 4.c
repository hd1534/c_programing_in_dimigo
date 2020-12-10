# include <stdio.h>

int main()
{
    FILE *fp = fopen("data4.txt","w" );
    char ch;
    if (fp == NULL)
        return 0;
    while((ch=fgetc(stdin))!='0')
        fprintf(fp,"%c",ch);
    fclose(fp);
    return 0;
}
