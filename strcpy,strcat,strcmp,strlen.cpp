/*
strcpy,strcat,strcmp,strlen �Լ��� �����ϱ� Myungsik kim
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
	char str1[MAX]; // 50����
	char str2[MAX]; // 50����
	int input; 
	int result;

	for(;;)
	{
		printf("1.strcpy \n2.strcat \n3.strcmp \n4.strlen \n5.���α׷� ���� \n\n�����ϼ���: ");
		scanf("%d",&input);
		fflush(stdin); //���� �Է¹��� ������ �� ���ͱ��� ����Ǳ⿡ �Է¹��� �� ����

		switch(input)
		{
		case 1: //cpy
			printf("������ ���ڿ� �Է�: ");
			gets(str1); 
			cpy(str2,str1);
			break;
	
		case 2: //cat
			printf("ù��° ���ڿ��� �Է�: ");
			gets(str1);
			printf("�ι�° ���ڿ��� �Է�: ");
			gets(str2);
			cat(str1,str2);
			break;
		
		case 3: //cmp
			printf("ù��° ���ڿ��� �Է�: ");
			gets(str1);
			printf("�ι�° ���ڿ��� �Է�: ");
			gets(str2);
			
			result = cmp(str1,str2);
			
			if(result>0) printf("�� �Է��� ���� ����:%d \n�Է���[%s]��ŭ\n",result, str1);
			
			else if(result<0) printf("�� �Է��� ���� ����:%d \n�Է���[%s]��ŭ\n",result, str2);
			
			else printf("�� �Է��� ���� ����:%d \n�� ������ ũ��� �����ϴ�.\n",result);
			break;
		
		case 4: //len
			printf("���̸� �� ���ڿ� �Է�: ");
			gets(str1);
			printf("���ڿ��� ���̴� %d �Դϴ�. \n",len(str1));
			break;

		case 5: //����
			exit(1);
			break;

		default :
			printf("�߸��Է�\n");
			break;
		}
	}
}

char cpy(char *str2, const char *str1)
{

	const char *p = str1; //str1 ���ڿ��� p�� �ű��.
	char *q = str2; //str2 ���ڿ��� q�� �ű��.
 
	while(*p) // *p�� null�� ���ö����� ���ư�
	{ 
		*q=*p; //p�� �ִ� ���ڿ��� q�� �ű��.
		q++;  //q�� ���ڿ� ��(null) ����
		p++; //p�� ���ڿ� ��(null) ����
	}

	*q='\0'; // *q�� null���� �ִ´�.
	
	printf("%s %s\n",str2,str1);
	
	return 0;
}

char cat(char *str1, const char *str2) 
{ 
	      char *q = str1; //str1 ���ڿ��� q�� �ű��.
	const char *p = str2; //str2 ���ڿ��� p�� �ű��.

	while(*q) // *q �̸� ����
	{
		q++; // q�� null ������ �̵����ѳ���
	}

	while(*p) // *p �̸� ����
	{
		*q=*p; //p�� q�� null ������ �߰���Ų��.
		q++;  //q ���ڿ��� ������
		p++; //p ���ڿ��� ������
		
	}

	*q='\0'; // q�� �ű�µ� null������ ���� �ؾ��ϹǷ� null���� �� ������Ѵ�.

	printf("%s\n",str1);
	return 0;
}

int len(const char *str1)
{

	int count = 0; //ī��Ʈ ��
	int i = 0; //�迭 ���� ��

	for(i=0; i<MAX; i++){ // ���ڿ� 0~49���� ���� ���
		if(str1[i]=='\0') //�ΰ�(������ ��) ������ ����
			break;         
		else 
			count++; //�װ� �ƴҰ�� ī��Ʈ�� 1�� ����
	}

	return count; // count �� ����
}

int cmp(const char *str1,const char *str2)
{	
	int i,j; //for��
	int st1=0; 
	int st2=0; 

	for (i=0; i<len(str1); i++) //len �Լ��� �����Ͽ� str1�� �Էµ� ���̸�ŭ ����
		st1 += str1[i]; //str1�� ���̸�ŭ st1�� ����
	for (j=0; j<len(str2); j++) //len �Լ��� �����Ͽ� str2�� �Էµ� ���̸�ŭ ����
		st2 += str2[j]; //str2�� ���̸�ŭ st2�� ����

	return st1 - st2; //���� ���� st1 ���� st2 �� �� ���� ����
}