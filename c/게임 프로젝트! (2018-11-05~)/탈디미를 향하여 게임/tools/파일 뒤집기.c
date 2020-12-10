#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *READ = fopen("..\\img\\knight.txt","r");
    FILE *WRITE = fopen("..\\img\\up\\knight.txt","w");
    char ch;
    char arr[1000];
    fseek(READ,-2,SEEK_END);
    while(1)
    {
        while((ch=fgetc(READ))!='\n')
        {
            if (ch==EOF)
                goto end;
            fseek(READ,-2,SEEK_CUR);
        }
        fgets(arr,1000,READ);
        fputs(arr,WRITE);
        fseek(READ,-2,SEEK_CUR);
        while((ch=fgetc(READ))!='\n')
        {
            if (ch==EOF)
                goto end;
            fseek(READ,-2,SEEK_CUR);
        }
        fseek(READ,-2,SEEK_CUR);
    }
    end:
    fgets(arr,1000,READ);
    fputs(arr,WRITE);
    fclose(READ);
    fclose(WRITE);
    return 0;
}
