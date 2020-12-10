#include <stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	switch(a/10)
	{
		case 10:
			printf("Great!");
			break;
		case 9:
			printf("Good!");
			break;
		default:
			printf("Fail!");
				
	}
	
}
