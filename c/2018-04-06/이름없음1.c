#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	srand(time(0));
	printf("%d\n", rand() % (b-a+1) + a);
	return 0;
}
