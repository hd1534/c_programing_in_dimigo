#include <stdio.h>
int main()
{
	int a=5,b=2;
	printf ("a + b = %d\n",a+b);
	printf ("a - b = %d\n",a-b);
	printf ("a * b = %d\n",a*b);
	printf ("a / b = %f\n",(float)a/b);//cast ¿¬»êÀÚ	 
	printf ("a %% b = %d\n",a%b);
	
	printf ("a|b = %d\n",a|b);
	printf ("a||b = %d\n",a||b);
	printf ("a&b = %d\n",a&b);
	printf ("a&&b = %d\n",a&&b);
	return 0; 
}
