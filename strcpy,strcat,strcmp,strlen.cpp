/*
strcpy,strcat,strcmp,strlen 함수로 구현하기 Myungsik kim
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

char cpy(char *str2, const char *str1); 
char cat(char *str1, const char *str2);
int cmp(const char *str1, const char *str2); 
int len(const char *str1);

void main(void)
{
	char str1[MAX]; // 50까지
	char str2[MAX]; // 50까지
	int input; 
	int result;

	for(;;)
	{
		printf("1.strcpy \n2.strcat \n3.strcmp \n4.strlen \n5.프로그램 종료 \n\n선택하세요: ");
		scanf("%d",&input);
		fflush(stdin); //위에 입력받은 정수값 후 엔터까지 저장되기에 입력받은 값 제거

		switch(input)
		{
		case 1: //cpy
			printf("복사할 문자열 입력: ");
			gets(str1); 
			cpy(str2,str1);
			break;
	
		case 2: //cat
			printf("첫번째 문자열을 입력: ");
			gets(str1);
			printf("두번째 문자열을 입력: ");
			gets(str2);
			cat(str1,str2);
			break;
		
		case 3: //cmp
			printf("첫번째 문자열을 입력: ");
			gets(str1);
			printf("두번째 문자열을 입력: ");
			gets(str2);
			
			result = cmp(str1,str2);
			
			if(result>0) printf("두 입력한 값의 차이:%d \n입력한[%s]더큼\n",result, str1);
			
			else if(result<0) printf("두 입력한 값의 차이:%d \n입력한[%s]더큼\n",result, str2);
			
			else printf("두 입력한 값의 차이:%d \n두 문자의 크기는 동일하다.\n",result);
			break;
		
		case 4: //len
			printf("길이를 잴 문자열 입력: ");
			gets(str1);
			printf("문자열의 길이는 %d 입니다. \n",len(str1));
			break;

		case 5: //종료
			exit(1);
			break;

		default :
			printf("잘못입력\n");
			break;
		}
	}
}

char cpy(char *str2, const char *str1)
{

	const char *p = str1; //str1 문자열을 p에 옮긴다.
	char *q = str2; //str2 문자열을 q에 옮긴다.
 
	while(*p) // *p가 null값 나올때까지 돌아감
	{ 
		*q=*p; //p에 있는 문자열을 q에 옮긴다.
		q++;  //q의 문자열 끝(null) 까지
		p++; //p의 문자열 끝(null) 까지
	}

	*q='\0'; // *q에 null값을 넣는다.
	
	printf("%s %s\n",str2,str1);
	
	return 0;
}

char cat(char *str1, const char *str2) 
{ 
	      char *q = str1; //str1 문자열을 q에 옮긴다.
	const char *p = str2; //str2 문자열을 p에 옮긴다.

	while(*q) // *q 이면 실행
	{
		q++; // q를 null 값까지 이동시켜놓고
	}

	while(*p) // *p 이면 실행
	{
		*q=*p; //p를 q의 null 값부터 추가시킨다.
		q++;  //q 문자열의 끝까지
		p++; //p 문자열의 끝까지
		
	}

	*q='\0'; // q에 옮기는데 null값까지 실행 해야하므로 null값은 꼭 써줘야한다.

	printf("%s\n",str1);
	return 0;
}

int len(const char *str1)
{

	int count = 0; //카운트 값
	int i = 0; //배열 길이 값

	for(i=0; i<MAX; i++){ // 문자열 0~49까지 길이 계산
		if(str1[i]=='\0') //널값(문장의 끝) 나오면 종료
			break;         
		else 
			count++; //그게 아닐경우 카운트가 1씩 증가
	}

	return count; // count 값 리턴
}

int cmp(const char *str1,const char *str2)
{	
	int i,j; //for문
	int st1=0; 
	int st2=0; 

	for (i=0; i<len(str1); i++) //len 함수를 참조하여 str1의 입력된 길이만큼 참조
		st1 += str1[i]; //str1의 길이만큼 st1에 저장
	for (j=0; j<len(str2); j++) //len 함수를 참조하여 str2의 입력된 길이만큼 참조
		st2 += str2[j]; //str2의 길이만큼 st2에 저장

	return st1 - st2; //길이 비교후 st1 에서 st2 를 뺀 값을 리턴
}