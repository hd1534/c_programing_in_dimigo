#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *READE = fopen("..\\img\\knight.txt","r");
    FILE *WRITE = fopen("..\\delete_img\\delete_knight.txt","w");
    char  ch;
    while((ch=fgetc(READE))!=EOF)
        if(ch=='\n')
            fputc('\n',WRITE);
        else
            fputc(' ',WRITE);
    return 0;
}
