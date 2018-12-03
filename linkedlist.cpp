//���Ͽ��Ḯ��Ʈ ��常 �ִ� ���� Myungsik Kim
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

typedef struct node //����ü�� ��� ����
{
	char code[max]; //�������ڵ�
	char num[max];  //�й�
	char name[max]; //�̸�
	char sex[max];  //���� 1=���� 2=����
	char id[max];   //ID
	char pw[max];   //Password
	char other[max];//��Ÿ�ڵ�
	struct node *next; //���� ��带 ����Ű�� ��ũ
}NODE;

NODE *head = NULL; //����� ó�� �κ��� ����Ű�� ������, �ʱⰪ NULL

void add_node();//��� ���� �Է�
void print_node();//��� ���
void mody_node();//��� ����
void delete_node();//��� ����
void search_node();//��� �˻�
void sort_node(int input);

void main(void)
{
	int input;
	while(1){
		printf("=========================================\n");
		printf("1.���� 2.��� 3.���� 4.���� 5.�˻� 6.����\n");
		printf("=========================================\n");		
		printf("��ȣ�Է�:");
		scanf("%d",&input);
		fflush(stdin);
		switch(input){
			case 1: add_node(); break;
			case 2: print_node(); break;
			case 3: mody_node(); break;
			case 4: delete_node(); break;
			case 5: search_node(); break;
			case 6: exit(1); break;
			default : printf("�߸��Է�\n");
		}
	}
}

void add_node()
{
	NODE *go = head; //����Ʈ�� Ž���� go ������, �ʱⰪ�� ����̴�.
	NODE *add = NULL; //����Ʈ�� ��带 �߰��� add ������, �ʱⰪ�� NULL���̴�.

	if(head==NULL) // ����� ��尡 ���� ���(ó���� ���)
	{
		head=(NODE*)malloc(sizeof(NODE));
		head->next=NULL;
		add=head;
	}
	else
	{
		add=(NODE*)malloc(sizeof(NODE)); // ����� ���� ã�Ҵ�.
		while(go->next!=NULL) //go �����Ͱ� NULL���� ���ö�����
		{
			go=go->next; //��� ��������.
		}
		go->next=add; //go�� ���� ��忡 add�� �߰��Ѵ�.
		add->next=NULL; //add�� ���� ��忡 NULL���� �߰��Ѵ�.
	}

	printf("=========================================\n");
	printf("�������ڵ�:");
	scanf("%s",add->code);
	printf("�й�:");
	scanf("%s",add->num);
	printf("�̸�:");
	scanf("%s",add->name);
	printf("����(����=1,����=2):");
	scanf("%s",add->sex);
	printf("ID:");
	scanf("%s",add->id);
	printf("PW:");
	scanf("%s",add->pw);
	printf("��Ÿ�ڵ�:");
	scanf("%s",add->other);	
}

void print_node()//���
{
	char *name[max];
	NODE *go = head; //����Ʈ�� Ž���� go ������
	int input;
	
	if(go==NULL){ //��尪�� NULL�̶��
	
		printf("����� ������ �����ϴ�\n");
		return;
	}
	printf("======================================\n");
	printf("1.�Ϲ���� 2.�������ڵ����� 3.�й�����\n");
	printf("4.�̸����� 5.��������\n");
	printf("======================================\n");
	printf("��¹���� �����ϼ���:");
	scanf("%d",&input);
 
	switch(input){
	
	case 1:
		while(go!=NULL){ //NULL�� ���ö� ���� �ݺ�
			printf("�������ڵ�:%s",go->code);
			printf(" �й�:%s",go->num);
			printf(" �̸�:%s",go->name);
			printf(" ����:%s",go->sex);
			printf(" ID:%s",go->id);
			printf(" PW:%s",go->pw);
			printf(" ��Ÿ�ڵ�:%s \n",go->other);
		go=go->next; //��� �����͸� ���� ��ũ�� �ּҷ� �ٲ��ָ鼭 NULL�� ���ö����� �̵�
		}break;
	
	case 2:
		sort_node(2);
	break;
		
	case 3:
		sort_node(3);
	break;

	case 4:
		sort_node(4);
	break;

	case 5:
		sort_node(5);
	break;

	default:
	printf("�߸� �Է��ϼ̽��ϴ�\n");
	}
}

void mody_node()//��� ����
{
	char _name[max];
	NODE *go = head;
	
	if(go==NULL)
	{
		printf("������ ������ �����ϴ�\n");
		return;
	}

	printf("�����Ͻ� ���� �Է�:");
	scanf("%s",_name);

	while(go!=NULL)
	{
		if(strcmp(go->name,_name)==0)
		{
			printf("�������ڵ�:");
			scanf("%s",go->code);
			printf("�й�:");
			scanf("%s",go->num);
			printf("�̸�:");
			scanf("%s",go->name);
			printf("����:");
			scanf("%s",go->sex);
			printf("ID:");
			scanf("%s",go->id);
			printf("PW:");
			scanf("%s",go->pw);
			printf("��Ÿ�ڵ�:");
			scanf("%s",go->other);	
		}
		go = go->next;
	}
}

void delete_node()//��� ����
{
	char _name[max]; //�̸����� �˻��ϱ� ����
	NODE *go = head; //����Ʈ�� Ž���� go ������
	NODE *del; //����Ʈ���� ��带 ���� del ������
	
	if(go==NULL)
	{
		printf("������ ������ �����ϴ�\n");
		return;
	}

	printf("�����Ͻ� �̸� �Է�:");
	scanf("%s",_name);

	if(strcmp(go->name,_name) == 0){ //ù��° ���
		head = go->next;
		free(go);
		printf("���� �Ǿ����ϴ�\n");
		return;
	}
	while(strcmp(go->name,_name) != 0){ //�ι�° ��� ����
		if((go->next) == NULL){
			printf("ã�� �̸��� �����ϴ�\n");
			return;
		}
		del=go;
		go=go->next;
	}
	del->next=go->next;
	free(go);
	printf("���� �Ǿ����ϴ�\n");
}

void search_node()//��� �˻�
{
	char _name[max];
	NODE *go = head;

	if(go==NULL)
	{
		printf("�˻��� ������ �����ϴ�\n");
		return;
	}

	printf("�˻��Ͻ� ���� �Է�:");
	scanf("%s",_name);

	while(go!=NULL){
		if(strcmp(go->name,_name) == 0){
			printf("\n�������ڵ�:%s",go->code);
			printf(" �й�:%s",go->num);
			printf(" �̸�:%s",go->name);
			printf(" ����:%s",go->sex);
			printf(" ID:%s",go->id);
			printf(" PW:%s",go->pw);
			printf(" ��Ÿ�ڵ�:%s \n",go->other);
		}else{printf("���� �����Դϴ�.");}
		go=go->next;
	}
}

void sort_node(int input)
{
	NODE *go=head;
	NODE *temp=head;
	NODE *temp2=head;
	NODE *temp3=head;
	NODE *temp4=head;
	NODE **sort;

	int len=0;
	int i,j;
	while(go!=NULL){
		go=go->next;
		len++;
	}
	go=head;
	sort=(NODE**)malloc(sizeof(NODE*)*len);
	for(i=0; i<len; i++){
		sort[i]=go;
		go=go->next;
	}
	if(i==2){
		for(i=0; i<len; i++){
			for(j=i+1; j<len; j++){
				if(strcmp(sort[i]->code,sort[j]->code)>0){
					temp=sort[i];
					sort[i]=sort[j];
					sort[j]=temp;
				}
			}
		}
	}
	else if(i==3){
		for(i=0; i<len; i++){
			for(j=i+1; j<len; j++){
				if(strcmp(sort[i]->num,sort[j]->num)>0){
					temp2=sort[i];
					sort[i]=sort[j];
					sort[j]=temp2;
				}
			}
		}
	
	}
	else if(i==4){
		for(i=1; i<len; i++){
			for(j=i+1; j<len; j++){
				if(strcmp(sort[i]->name,sort[j]->name)>0){
					temp3=sort[i];
					sort[i]=sort[j];
					sort[j]=temp3;
				}
			}
		}	
	}
	else if(i==5){
		for(i=1; i<len; i++){
			for(j=i+1; j<len; j++){
				if(strcmp(sort[i]->sex,sort[j]->sex)>0){
					temp4=sort[i];
					sort[i]=sort[j];
					sort[j]=temp4;
				}
			}
		}	
	}

	head=sort[0];
	go=head;
	for(i=1; i<len; i++){
		go->next=sort[i];
		go=sort[i];
	}
	go->next=NULL;
	go=head;

	while(go!=NULL){
			printf(" �������ڵ�:%s",go->code);
			printf(" �й�:%s",go->num);
			printf(" �̸�:%s",go->name);
			printf(" ����:%s",go->sex);
			printf(" ID:%s",go->id);
			printf(" PW:%s",go->pw);
			printf(" ��Ÿ�ڵ�:%s \n",go->other);
			go=go->next;
	}
}