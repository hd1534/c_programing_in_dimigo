#include <stdio.h>
int main()
{
	int a,b=0;
	do{
		scanf("%d", &a);
		if(a<0)
		{
			printf("%d",b);
			return 0;
		}
		b+=a;
	}while (1);
}
