#include <stdio.h>

int main()
{
    int i=10,j=20;
    char ch[100]="testestsetset";
    i="%d",j;
    printf("\"%%d\"의 위치 : %d\n",i);
    i=("%d",j);
    printf("우리가 원하던 값 : %d\n",i);

    printf("ch의 값 : ");
    printf(i>j?"ch의 위치 : %d\n",ch:("%d",ch));
    puts("");
    printf(1>0?"ch의 위치 : %d\n",ch:("%d",ch));
    puts("");
    printf(1>0?"ch의 위치 : %d\n":("%d",ch));
    puts("");
    printf(1>0?("ch의 위치 : %s\n",ch):("%d",ch));
    //신기하네,,
}
