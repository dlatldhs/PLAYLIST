#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =//
int n;
typedef char* DataType;
typedef struct Node Node;
typedef struct Queue Queue;
Node* createNode(DataType data,DataType datata);
DataType getData(Node* node);
void setLink(Node* node, Node* nextNode);
Node* getLink(Node* node);

Queue* createQueue();
void enqueue(Queue* q, DataType data, DataType datata);
DataType dequeue(Queue* q);
DataType peek(Queue* q);
void printQ(Queue* q);
void freeQueue(Queue* q);
bool isEmpty(Queue* q);

typedef struct Node{
	DataType data;
	DataType datata;
	Node* link;
}Node;

typedef struct Queue{
	Node* front;
	Node* rear;
}Queue;

int asdf=1;

void menu()
{
	printf("\n메뉴\n");
	printf("1. 플레이 리스트에 노래 추가\n");
	printf("2. 플레이 리스트 삭제\n");
	printf("3. 플레이 리스트 보기\n");
	printf("4. 플레이 리스트 정렬\n");
	printf("5. 프로그램 종료\n");
	printf("하고자 하는 작업을 선택해 주세요(숫자)...");
}

int main(){
	Queue* q = createQueue();
	printf("===================================================\n");
	printf("c 파일은 폴더안에 저장해주세요. \n");
	printf("===================================================\n");
	while(1){
		menu();
		n=0;
		scanf("%d",&n);
		if(n==1){// 노래 넣는 기능
			FILE *file = fopen("playlist.txt","at");
			char music[51]; char notion[20];
			printf("추가하고자 하는 노래를 입력해주세요 :");
			scanf("%s %[^\n]",&notion,&music);
			fprintf(file,"%s %s\n",notion,music);
			fclose(file);// file IO 에 넣기
			enqueue(q,notion,music);
			printf("노래가 성공적으로 추가되었습니다!\n");
			
		}else if(n==2){// 노래 삭제 기능
			dequeue(q);
			FILE *fp = fopen("playlist.txt", "r");
			FILE *fp2 = fopen("playlist2.txt", "w");
			char old[20]="playlist.txt";
			char newfile[20]="playlist2.txt";
			char data[100];
			fgets(data,100,fp);
			while(1)
			{
				fgets(data,100,fp);
				if(feof(fp)!=0) break;
				fputs(data,fp2);
			}	
			fclose(fp);
			fclose(fp2);
			
			int sum = remove(old); 
			int cnt = rename(newfile,old);
			
			if(sum == 0 && cnt == 0) {
				printf("삭제 성공\n");
			}
			
		}else if(n==3){// 플레이 리스트 보는 기능
			char chr[100];
			FILE *in = fopen("playlist.txt","r");
			while(1){
				fgets(chr, 100, in);
				if(feof(in)!=0) break;
				printf("%s",chr);
			}
			fclose(in);	
		}else if(n==4){// 플레이 리스트 정렬하는 기능 
			FILE *fp = fopen("playlist.txt","r");
			fclose(fp);
			
		}else if(n==5){// 프로그램 종료 하는 기능 
			printf("프로그램이 종료 됩니다....");
			return 0;
		}
		
}freeQueue(q); return 0;}
Node* createNode(DataType data, DataType datata){
	Node* newNode = malloc(sizeof(Node));
	newNode->data=data;
	newNode->datata=datata;
	newNode->link=NULL;
	
	return newNode;
}
DataType getData(Node* node){
	return node->data,node->datata;
}

void setLink(Node* node, Node* nextNode){
	node->link = nextNode;
}

Node* getLink(Node* node){
	return node->link;
}

Queue* createQueue(){
	Queue* newQ = malloc(sizeof(Queue));
	newQ->front = NULL;
	newQ->rear = NULL;
	
	return newQ;
}
void enqueue(Queue* q,DataType data, DataType datata){
	Node* newNode = createNode(data,datata);
	if(q->front == NULL){
		q->front = newNode;
		q->rear = newNode;
	}
	else{
		setLink(q->rear,newNode);
		q->rear = newNode;
	}
}
DataType dequeue(Queue* q){
	if(isEmpty(q)){
		printf("playlist가 비어있습니다. \n");
		return 0;
	}
	else{
		Node* tempNode = q->front;
		DataType data = getData(q->front);
		DataType datata = getData(q->front);
		
		if(tempNode == q->rear){
			q->front = NULL;
			q->rear  = NULL;
		}
		else{
			q->front = getLink(tempNode);
		}
		free(tempNode);
		return data;
	}
}
void printQ(Queue *q){
	Node* temp = q->front;
	printf("playlist : ");
	while(temp != NULL){
		printf("%s %s",getData(temp));
		temp = getLink(temp);
	}
	printf("\n\n");
}
void freeQueue(Queue* q) {
    if(!isEmpty(q)) {
        Node *target = q->front;
        Node *newFront = getLink(target);

        while (target != NULL) {
            newFront = getLink(target);
            free(target);
            target = newFront;
        }
        free(newFront);
    }
    free(q);
}
bool isEmpty(Queue* q) {
    return q->front == NULL;
} 
