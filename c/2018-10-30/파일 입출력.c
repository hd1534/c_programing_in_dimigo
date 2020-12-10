# include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt","r+" );
    char ch;
    if (fp == NULL)
        return 0;
    fseek(fp,-1,SEEK_END);
    //fseek(fp,-1,SEEK_CUR);
    //fseek(fp,0,SEEK_SET);
    fscanf(fp,"%c",&ch);
    printf("%c",ch);
    fclose(fp);
    return 0;
}
