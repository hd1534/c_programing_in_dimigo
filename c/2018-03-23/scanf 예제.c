#include <stdio.h>
int main()
{
	int a;
	char b;
	printf("�й��� �Է��ϼ���!\n");
	scanf("%d",&a);
	printf("������ �Է��ϼ���(m/f)1\n");
	scanf(" %c",&b);//���Ͷ����� �ȵǴµ� �����ϳ��� �ǳ� �׻� stdin ������µ� �̷�. 
	printf("�й� : %d, ���� : %c\n",a,b);
	return 0; 
 } 
