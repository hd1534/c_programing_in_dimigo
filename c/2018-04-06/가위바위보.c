#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int com,user;
	printf("����(0), ����(1), ��(2) �� �ϳ��� �Է��ϼ��� : ");
	scanf("%d",&user);
	srand (time(0));
	com = rand()%3;
	printf("%d %d\n",com, user);
	if (com == user)
		printf("�����ϴ�.\n");
	else
	{
		switch(user)
		{
			case 0:
				com = ++com%3;
				break;
			case 2:
				com = (com+2)%3;
			
		 }
		if (com)
			printf("��ǻ�� ��");
		else 
			printf("���� ��");
			 
	}	
	return 0;
}
