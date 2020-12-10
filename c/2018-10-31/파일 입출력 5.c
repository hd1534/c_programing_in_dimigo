# include <stdio.h>

int main()
{
    FILE *fp = fopen("data 6.txt","r" );
    FILE *ofp = fopen("data 5_out.txt","w");
    char ch;
    if (fp == NULL)
        return 0;
    while((ch=fgetc(fp))!=-1)
        fprintf(ofp,"%c",ch>='a'&&ch<='z'?ch-32:ch>='A'&&ch<='Z'?ch+32:ch);
    fclose(fp);
    fclose(ofp);
    return 0;
}
