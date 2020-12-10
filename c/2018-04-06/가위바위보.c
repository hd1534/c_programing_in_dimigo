#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int com,user;
	printf("가위(0), 바위(1), 보(2) 중 하나를 입력하세요 : ");
	scanf("%d",&user);
	srand (time(0));
	com = rand()%3;
	printf("%d %d\n",com, user);
	if (com == user)
		printf("비겼습니다.\n");
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
			printf("컴퓨터 승");
		else 
			printf("유저 승");
			 
	}	
	return 0;
}
