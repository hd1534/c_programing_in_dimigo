#include <stdio.h>

int main()
{
    int i=10,j=20;
    char ch[100]="testestsetset";
    i="%d",j;
    printf("\"%%d\"�� ��ġ : %d\n",i);
    i=("%d",j);
    printf("�츮�� ���ϴ� �� : %d\n",i);

    printf("ch�� �� : ");
    printf(i>j?"ch�� ��ġ : %d\n",ch:("%d",ch));
    puts("");
    printf(1>0?"ch�� ��ġ : %d\n",ch:("%d",ch));
    puts("");
    printf(1>0?"ch�� ��ġ : %d\n":("%d",ch));
    puts("");
    printf(1>0?("ch�� ��ġ : %s\n",ch):("%d",ch));
    //�ű��ϳ�,,
}
