/*			 ^
			^@^
		   ^@i@^
		  ^@i+i@^
		 ^@i+++i@^
		^@i++ ++i@^
	   ^@i++   ++i@^
	  ^@i++     ++i@^
	   ^@i++   ++i@^
	    ^@i++ ++i@^
		 ^@i+++i@^
		  ^@i+i@^
		   ^@i@^
		    ^@^
		     ^
	*/
#include <stdio.h>
int main()
{
    int a=1,b=1,c,tmp;
    for ( c=0;c<31;c++)
    {
        tmp = a+b;
        a=b;
        b=tmp;
    }
    printf("%d",tmp);
}
