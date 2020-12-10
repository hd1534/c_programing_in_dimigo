# include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt","r+");
    int a,i,j,k,n;
    char ch[100],c;
    if(!fp)
    {
        printf("파일이 없음....\n v파일을 생성합니다.");
        fp = fopen("test.txt","w+");
        if(!fp)
        {
            printf("파일을 만들 수 없습니다.");
            return 0;
        }
    }
    while(a)
    {
        printf("1번은 원하는 줄 출력\n2번은 파일 내용 전부 출력\n3번은 파일 끝에 내용 추가\n0번은 종료.\n");
        printf("-------------------------------------------------------------------------\n");
        scanf("%d",&a);
        switch(a)
        {
           case 1:
               printf("원하는 줄의 번호를 입력해주세요.\n");
               scanf("%d",&n);
               n-=1;
               for(i=0;i<n;i++)
                {
                    c=fgetc(fp);
                    while(c!='\n' && c!=EOF)
                        c=fgetc(fp);
                    if(c==EOF)
                    {
                        printf("%d번 줄이 없습니다.\n",n+1);
                        break;
                    }
                }
                if (n==i)
                {
                    fgets(ch,99,fp);
                    printf("%s\n\n",ch);
                }
               break;
           case 2:
               break;
           case 3:
               break;
        }
    }
    fclose(fp);
    return 0;
}
