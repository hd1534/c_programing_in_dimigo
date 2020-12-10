#include <stdio.h>
#define arr_l 10001//배열의 길이 (재현)
int prime(int *prime_arr);//에라토스 테네스의 체(재현이가 한거)
int check(int prime,int *prime_arr);//규형이가 할거
//int involution(int a);//10의 거듭제곱,  10^a
int AB(int a,int b);// A--B가 되는지 확인, 되면 1을 안되면 0을 반환(재현이가 한거)
int main()//규형이가 할거
{
    int prime_arr[arr_l];//소수 배열(재현)
	long long int sum=0;//long long int는 int보다 큰 숫자를 담을수 있다. 이변수는 총합을 담는 변수이다.(재현)
    int i,prime_num;//i,소수의 개수(재현)

    prime_num=prime(prime_arr);//prime_num배열에 에라토스 테네스의 체로 거른 소수를 받는다.(재현)
//여기까진 내가함 여기를 바꿔도 되고 쓰고 싶으면 그대로 써도 됨 ㅇㅋ? 그리고 너가 주석달거면 그부분에 (규형) 이라고 표시좀 ㅇㅋ?(재현)

    /* 규형아 이부분하고 check 함수를 니가 만들어봐 ㅇㅋ?(재현)
    for(i=0;i<prime_num;i++)
        if(!check(arr[i]))
            sum+=arr[i];
            */

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
		if (a % involution[l2] == b)//2번째 경우의 왼쪽에 한자리 수를 추가하면 같아지는 경우로 왼쪽의 한자리 수를 제외하면 같아야한다.  0제곱이 1이다. 그래서 l-1을 해준다.(재현)
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

int check(int prime,int *prime_arr)//확인을 할때 자기보다 작은 소수로만 연결해서 2 가나오면 참(1) 안나오면 거짓(0) 을 반환(재현)
{
    int l,p,tmp;//자리수, 배열에서의 소수의 위치,임시 변수(재현)
    for(p=0;prime_arr[p]!=prime;p++);//몇번째에 위치하는 알아보기(재현)

    return ;
}
int prime(int *prime_arr)
{
	int i, j;
	int arr[arr_l];
	for (i = 1; i<arr_l; i++)//1부터 차례대로 배열에 넣어준다.(재현)
		arr[i] = i;
	for (i = 2; i<arr_l; i++)
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
