#include <stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	if(a>100)
	{
		printf("Are you kidding me?\n");
		return 1;
	}
	if (a>90)
		printf("good!");
	else
		printf("study hard!");
	return 0;
}
