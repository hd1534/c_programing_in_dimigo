#include <stdio.h>
int main()
{
	int i = 0 ;
	while(++i<20)
	{
		if (i%2)
			continue;
		printf("%d\n",i);
	}
}

