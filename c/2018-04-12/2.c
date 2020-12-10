#include <stdio.h>
int main()
{
	int a,sum=0;
	do
	{
		scanf("%d",&a);
		if(a>0)
			sum+=a;
	}while(a>0);
	printf("%d",sum);
	return 0;
}
