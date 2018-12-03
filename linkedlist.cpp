//단일연결리스트 헤드만 있는 버전 Myungsik Kim
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

typedef struct node //구조체로 노드 구성
{
	char code[max]; //연구실코드
	char num[max];  //학번
	char name[max]; //이름
	char sex[max];  //성별 1=남자 2=여자
	char id[max];   //ID
	char pw[max];   //Password
	char other[max];//기타코드
	struct node *next; //다음 노드를 가르키는 링크
}NODE;

NODE *head = NULL; //노드의 처음 부분을 가르키는 포인터, 초기값 NULL

void add_node();//노드 순차 입력
void print_node();//노드 출력
void mody_node();//노드 수정
void delete_node();//노드 삭제
void search_node();//노드 검색
void sort_node(int input);

void main(void)
{
	int input;
	while(1){
		printf("=========================================\n");
		printf("1.생성 2.출력 3.수정 4.삭제 5.검색 6.종료\n");
		printf("=========================================\n");		
		printf("번호입력:");
		scanf("%d",&input);
		fflush(stdin);
		switch(input){
			case 1: add_node(); break;
			case 2: print_node(); break;
			case 3: mody_node(); break;
			case 4: delete_node(); break;
			case 5: search_node(); break;
			case 6: exit(1); break;
			default : printf("잘못입력\n");
		}
	}
}

void add_node()
{
	NODE *go = head; //리스트를 탐색할 go 포인터, 초기값은 헤드이다.
	NODE *add = NULL; //리스트에 노드를 추가할 add 포인터, 초기값은 NULL값이다.

	if(head==NULL) // 연결된 노드가 없는 경우(처음인 경우)
	{
		head=(NODE*)malloc(sizeof(NODE));
		head->next=NULL;
		add=head;
	}
	else
	{
		add=(NODE*)malloc(sizeof(NODE)); // 노드의 끝을 찾았다.
		while(go->next!=NULL) //go 포인터가 NULL값이 나올때까지
		{
			go=go->next; //계속 지나간다.
		}
		go->next=add; //go의 다음 노드에 add를 추가한다.
		add->next=NULL; //add의 다음 노드에 NULL값을 추가한다.
	}

	printf("=========================================\n");
	printf("연구실코드:");
	scanf("%s",add->code);
	printf("학번:");
	scanf("%s",add->num);
	printf("이름:");
	scanf("%s",add->name);
	printf("성별(남자=1,여자=2):");
	scanf("%s",add->sex);
	printf("ID:");
	scanf("%s",add->id);
	printf("PW:");
	scanf("%s",add->pw);
	printf("기타코드:");
	scanf("%s",add->other);	
}

void print_node()//출력
{
	char *name[max];
	NODE *go = head; //리스트를 탐색할 go 포인터
	int input;
	
	if(go==NULL){ //헤드값이 NULL이라면
	
		printf("출력할 내용이 없습니다\n");
		return;
	}
	printf("======================================\n");
	printf("1.일반출력 2.연구실코드정렬 3.학번정렬\n");
	printf("4.이름정렬 5.성별정렬\n");
	printf("======================================\n");
	printf("출력방법을 선택하세요:");
	scanf("%d",&input);
 
	switch(input){
	
	case 1:
		while(go!=NULL){ //NULL값 나올때 까지 반복
			printf("연구실코드:%s",go->code);
			printf(" 학번:%s",go->num);
			printf(" 이름:%s",go->name);
			printf(" 성별:%s",go->sex);
			printf(" ID:%s",go->id);
			printf(" PW:%s",go->pw);
			printf(" 기타코드:%s \n",go->other);
		go=go->next; //노드 포인터를 다음 링크의 주소로 바꿔주면서 NULL값 나올때까지 이동
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
	printf("잘못 입력하셨습니다\n");
	}
}

void mody_node()//노드 수정
{
	char _name[max];
	NODE *go = head;
	
	if(go==NULL)
	{
		printf("수정할 내용이 없습니다\n");
		return;
	}

	printf("수정하실 내용 입력:");
	scanf("%s",_name);

	while(go!=NULL)
	{
		if(strcmp(go->name,_name)==0)
		{
			printf("연구실코드:");
			scanf("%s",go->code);
			printf("학번:");
			scanf("%s",go->num);
			printf("이름:");
			scanf("%s",go->name);
			printf("성별:");
			scanf("%s",go->sex);
			printf("ID:");
			scanf("%s",go->id);
			printf("PW:");
			scanf("%s",go->pw);
			printf("기타코드:");
			scanf("%s",go->other);	
		}
		go = go->next;
	}
}

void delete_node()//노드 삭제
{
	char _name[max]; //이름으로 검색하기 위해
	NODE *go = head; //리스트를 탐색할 go 포인터
	NODE *del; //리스트에서 노드를 지울 del 포인터
	
	if(go==NULL)
	{
		printf("삭제할 내용이 없습니다\n");
		return;
	}

	printf("삭제하실 이름 입력:");
	scanf("%s",_name);

	if(strcmp(go->name,_name) == 0){ //첫번째 노드
		head = go->next;
		free(go);
		printf("삭제 되었습니다\n");
		return;
	}
	while(strcmp(go->name,_name) != 0){ //두번째 노드 부터
		if((go->next) == NULL){
			printf("찾는 이름이 없습니다\n");
			return;
		}
		del=go;
		go=go->next;
	}
	del->next=go->next;
	free(go);
	printf("삭제 되었습니다\n");
}

void search_node()//노드 검색
{
	char _name[max];
	NODE *go = head;

	if(go==NULL)
	{
		printf("검색할 내용이 없습니다\n");
		return;
	}

	printf("검색하실 정보 입력:");
	scanf("%s",_name);

	while(go!=NULL){
		if(strcmp(go->name,_name) == 0){
			printf("\n연구실코드:%s",go->code);
			printf(" 학번:%s",go->num);
			printf(" 이름:%s",go->name);
			printf(" 성별:%s",go->sex);
			printf(" ID:%s",go->id);
			printf(" PW:%s",go->pw);
			printf(" 기타코드:%s \n",go->other);
		}else{printf("없는 정보입니다.");}
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
			printf(" 연구실코드:%s",go->code);
			printf(" 학번:%s",go->num);
			printf(" 이름:%s",go->name);
			printf(" 성별:%s",go->sex);
			printf(" ID:%s",go->id);
			printf(" PW:%s",go->pw);
			printf(" 기타코드:%s \n",go->other);
			go=go->next;
	}
}