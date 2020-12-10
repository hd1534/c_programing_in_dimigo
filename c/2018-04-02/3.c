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
		printf("Great");
	else if(a>80)
		printf("good!");
	else
		a>30?printf("study hard!"):printf("Hummm. aren't you study?");
 return 0;
}
