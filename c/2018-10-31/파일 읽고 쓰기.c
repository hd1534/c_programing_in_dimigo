# include <stdio.h>

int main()
{
    FILE *fp = fopen("data 6.txt","r+" );
    char ch[100];
    if (fp == NULL)
        return 0;
    fprintf(fp,"%s","hello?");
    fclose(fp);
    return 0;
}
