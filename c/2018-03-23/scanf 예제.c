#include <stdio.h>
int main()
{
	int a;
	char b;
	printf("학번을 입력하세요!\n");
	scanf("%d",&a);
	printf("성별을 입력하세요(m/f)1\n");
	scanf(" %c",&b);//에터때문에 안되는데 공백하나면 되네 항상 stdin 비웠었는데 이런. 
	printf("학번 : %d, 성별 : %c\n",a,b);
	return 0; 
 } 
