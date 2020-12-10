//코드는 내가 다했닭 예~~~~~~
#include <stdio.h>
#define arr_l 10000//배열의 길이 (재현)
int count_check;
int abcdefg[10000]={0},abcdefghi=0;
int prime(int *prime_arr);//에라토스 테네스의 체, 리턴값은 10000보다 작은 소수의 개수(재현이가 한거)
void check(int prime,int prime_num,int *prime_arr,int i);//2부터 시작해서 --로 연결되는 자기보다 큰 소수를 지운다. 즉 안지워진 것은 2->p가 안되는 것들 (재귀 함수이다)(재현이가 한거)
int AB(int a,int b);// A--B가 되는지 확인, 되면 1을 안되면 0을 반환(재현이가 한거)
//int involution(int a);//10의 거듭제곱,  10^a
int main()//규형이가 할거
{
    int prime_arr[arr_l]={0};//소수 배열(재현)
	long long int sum=0;//long long int는 int보다 큰 숫자를 담을수 있다. 이변수는 총합을 담는 변수이다.(재현)
    int i,prime_num1000,prime_num10000;//i,1000이하의 소수의 개수,10000이하의 소수의 개수(재현)

    prime_num10000=prime(prime_arr);//prime_num배열에 에라토스 테네스의 체로 거른 소수를 받는다.(재현)

    printf("에라토스 테네스의 체 : ");
    for(i=1;i<prime_num10000;i++)//1부터 시작하는 이유가 2를 제외하고 출력 하기 위해
    {
        printf("%d ",prime_arr[i]);//이부분은 에라토스 테네스의 체가 제대로 작동했는지 확인하려고 만듦
    }
    printf("\n\n");

    for(prime_num1000=0;prime_arr[prime_num1000]<1000;prime_num1000++);//1000보다 작은 소수의 개수

    check(2,prime_num10000,prime_arr,1);//2부터 시작이니까

    printf("2->P가 안되는 소수들 : ");
    for(i=1;i<prime_num1000;i++)//1부터 시작하는 이유가 2를 제외하고 더하기 위해
    {
        sum+=prime_arr[i];//sum에다가 누적한다.
    }
    for(i=1;i<prime_num10000;i++)//1부터 시작하는 이유가 2를 제외하고 더하기 위해
    {
        printf("%d ",prime_arr[i]);//출력하는 이유는 결과를 눈으로 보고싶어서
        sum+=prime_arr[i];//sum에다가 누적하다.
    }
    printf("\n\n더한 값 : %lld",sum);//sum의 값을 long long int 로 출력

	printf("\n\n\ncheck 연산 횟수(if문 기준):%d",count_check);
    return 0;
}
/* 이부분은 밑에 AB를 사용하면 함수 없이 가능하다.
int involution(int a)
{
    int i,j;
    for(i=1,j=0;j<a;i*=10,j++);
    return i;
}
int AB(int a, int b)//큰 소수, 작은 소수(재현)
{
	int l, l2, tmp;//a의 길이, b의 길이, 임시변수
	int i,j, k = 0;//for문에 쓰임,for문에 쓰임, 같은 숫자의 개수

	for (l = 0, tmp = a; tmp; tmp /= 10)//자리수 알아보기(재현)
		l++;
	for (l2 = 0, tmp = b; tmp; tmp /= 10)//자리수 알아보기(재현)
		l2++;
	if (l - 1 == l2)//한자리수가 차이날 경우(재현)
		if (a % (involution(l2)) == b)//2번째 경우의 왼쪽에 한자리 수를 추가하면 같아지는 경우로 왼쪽의 한자리 수를 제외하면 같아야한다.  0제곱이 1이다. 그래서 l-1을 해준다.(재현)
            return 1;
	if (l == l2)//자릿수가 똑같을 경우(재현)
	{
		for (i = 1,j = 0; j < l; i *= 10,j++)// 알고싶은 자릿수가 n이면 10^(n-1) % 10을 하면 알 수있다.(n-1인 이유는 0제곱이 1이라)(재현)
		{
			if ((a / i % 10) == (b / i % 10))//현재 자리수의 숫자가 같으면 k에 1을 더한다.(재현)
				k++;
		}
		if (k == l-1)//전체 길이보다 한개 적으면 한군데만 다른것이다.(재현)
			return 1;
	}
	return 0;
}
*/

int AB(int a, int b)//큰 소수, 작은 소수(재현)
{
	int l, l2, tmp;
	int i,j, k = 0;
    int involution[]={1,10,100,1000,10000};//involution 함수대신 배열에 넣어 연산 횟수 줄임
	for (l = 0, tmp = a; tmp; tmp /= 10)//자리수 알아보기(재현)
		l++;
	for (l2 = 0, tmp = b; tmp; tmp /= 10)//자리수 알아보기(재현)
		l2++;
	if (l - 1 == l2)//한자리수가 차이날 경우(재현)
		if (a % involution[l2] == b)//2번째 경우의 왼쪽에 한자리 수를 추가하면 같아지는 경우로 왼쪽의 한자리 수를 제외하면 같아야한다.  0제곱이 1이다. 그래서 l-1을 해준다.(재현)  l-1이 l2여서 연산 줄이려고 씀
			return 1;
	if (l == l2)//자릿수가 똑같을 경우(재현)
	{
		for (i = 1,j = 0; j < l; i *= 10,j++)// 알고싶은 자릿수가 n이면 10^(n-1) % 10을 하면 알 수있다.(n-1인 이유는 0제곱이 1이라)(재현)
		{
			if ((a / i % 10) == (b / i % 10))//현재 자리수의 숫자가 같으면 k에 1을 더한다.(재현)
				k++;
		}
		if (k == l-1)//전체 길이보다 한개 적으면 한군데만 다른것이다.(재현)
			return 1;
	}
	return 0;
}
void check(int prime,int prime_num,int *prime_arr,int i)//확인해볼 소수,소수의 총 개수,소수 배열,for문을 돌릴때 쓰는 i(i를 초기화 시켜서 돌리면 현재 소수보다 작은수부터 시작한다.)
{
    for(;i<prime_num;i++)//i를 입력받은 숫자부터쓰는 이유는 입력받은 소수보다 작은수는 확인하지 않기 위해서
    {
        count_check++;
        if(AB(prime_arr[i],prime))//--로 이어지는 더큰 소수를 찾는다.
        {
            check(prime_arr[i],prime_num,prime_arr,i+1);
            prime_arr[i]=0;
        }
    }
}
int prime(int *prime_arr)//소수의 배열을 저장하고 싶은 배열의 주솟값
{
	int i, j;
	int arr[arr_l]={0};
	for (i = 2; i<arr_l; i++)//2부터 차례대로 배열에 넣어준다.(재현)
		arr[i] = i;
	for (i = 1; i<arr_l; i++)
	{
		if (!arr[i])//체에서 걸러져서 빈 곳을 거른다.(재현)
			continue;
		for (j = 2; j*i<arr_l; j++)//1부터 시작하면 소수의 배수만 지우는 것이 아니라 소수도 지우게 된다. //j*i<arr_l인 이유는 j*i>arr_l 일경우 배열의 길이를 넘는 곳의 값을 바꾸기 때문(재현)
		{
			arr[i*j] = 0;//배열 번호는 배열안의 숫자와 같다.(재현)
		}
	}
	j=0;
	for (i = 0; i<arr_l; i++)
	{
		if (!arr[i])//에라토스 테네스의 체에서 걸러진 부분을 제외한 나머지 부분을 prime_arr에 넣어준다.(재현)
			continue;
		prime_arr[j++]=arr[i];//j랑 i는 따로 계산한다.(재현)
	}
	return j;
}
