#include <stdio.h>
int main()
{
	int a= 5;
	printf("%d %d",a,a++);//후위 증감연산자의 우선순위는 높고 단지 따로 파생해서 보관한다.참고(http://blog.naver.com/PostView.nhn?blogId=ruvendix&logNo=220897091153&parentCategoryNo=&categoryNo=93&viewDate=&isShowPopularPosts=false&from=postView) 
	return 0;
}
