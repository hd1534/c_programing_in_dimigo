# include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt","r+");
    int a,i,j,k,n;
    char ch[100],c;
    if(!fp)
    {
        printf("������ ����....\n v������ �����մϴ�.");
        fp = fopen("test.txt","w+");
        if(!fp)
        {
            printf("������ ���� �� �����ϴ�.");
            return 0;
        }
    }
    while(a)
    {
        printf("1���� ���ϴ� �� ���\n2���� ���� ���� ���� ���\n3���� ���� ���� ���� �߰�\n0���� ����.\n");
        printf("-------------------------------------------------------------------------\n");
        scanf("%d",&a);
        switch(a)
        {
           case 1:
               printf("���ϴ� ���� ��ȣ�� �Է����ּ���.\n");
               scanf("%d",&n);
               n-=1;
               for(i=0;i<n;i++)
                {
                    c=fgetc(fp);
                    while(c!='\n' && c!=EOF)
                        c=fgetc(fp);
                    if(c==EOF)
                    {
                        printf("%d�� ���� �����ϴ�.\n",n+1);
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
