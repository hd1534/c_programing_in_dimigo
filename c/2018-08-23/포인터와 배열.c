#include<stdio.h>
int main()
{
    char ch[10] = "Hello?";//�̰� stack�� �ִ� �迭�� �� �����ִ� ���̴�. !!
    char *chp = "Hello?";//���ͷ� �޸��� data ������ ����Ǿ� �ֵ� !
    printf("0x%x 0x%x %c %c\n",ch,chp,*ch,*chp);
    printf("%s",chp);
    printf("\n\n\n %d %d\n %d %d",ch,&ch,ch+1,&ch+1);
    //ch�� ù��° ���Ҹ� ����Ű�� &ch�� �迭 ��ü�� ����Ų��.
    return 0;
}
