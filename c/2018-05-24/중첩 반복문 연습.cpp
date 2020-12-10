#include <stdio.h>
int main()
{
	/*
	int i,j,k;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		for (j=0;j<k;j++)
			printf("*");
		printf("\n");
	}

	int i,j;
	for(i=2;i<10;i++)
	{
		for (j=1;j<10;j++)
			printf("%d * %d = %d ",i,j,i*j);
		printf("\n");
	}
	
	int i,j;
	for(i=1;i<10;i++)
	{
		for (j=2;j<10;j++)
			printf("%d*%d = %2d   ",j,i,j*i);
		printf("\n");
	}
	*/

	int a,b,c,o=0;
	for(a=999;a>0;a--)
		for(b=999;b>0;b--)
		{
			c=a*b;
			if(c/100000==c%10&&c/10000%10==c/10%10&&c/1000%10==c/100%10)
			{
				if(o<c)
					o=c;
			}
		}
	printf("%d",o);
}

