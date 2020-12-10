#include<stdio.h>
int main()
{
    char ch[10] = "Hello?";//이건 stack에 있는 배열에 쳐 박혀있는 아이다. !!
    char *chp = "Hello?";//리터럴 메모리중 data 영역에 저장되어 있따 !
    printf("0x%x 0x%x %c %c\n",ch,chp,*ch,*chp);
    printf("%s",chp);
    printf("\n\n\n %d %d\n %d %d",ch,&ch,ch+1,&ch+1);
    //ch는 첫번째 원소를 가리키고 &ch는 배열 자체를 가리킨다.
    return 0;
}
