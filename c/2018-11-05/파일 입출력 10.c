# include <stdio.h>

int main(int argc,char *argv[])
{
    FILE *fp,*fp2;
    char f1[1000],f2[1000];
    scanf("%s %s",f1,f2);
    fp = fopen(f1,"r" );
    fp2 = fopen(f2,"r" );
    if (!fp)
        return 1;
    if (!fp2)
        return 1;
    while(fgetc(fp)==fgetc(fp2)); //읽을것이 없으면 -1을 ch에 넣는다.
    if fgetc(fp)==fgetc(fp2)
        printf("true");
    else
        printf("false");
    fclose(fp);
    fclose(fp2);
    return 0;
}
