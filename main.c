#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
int main(){
	Queue* q = createQueue();
	printf("\n메뉴\n1. 플레이 리스트에 노래 추가\n2. 플레이 리스트 삭제\n3. 플레이 리스트 보기\n4. 플레이 리스트 정렬\n5. 프로그램 종료\n하고자하는 작업을 선택해 주세요(숫자)....");
	while(1){
		n=0;
		scanf("%d",&n);
		if(n==1){// 노래 넣는 기능
			FILE *file = fopen("C:/Users/SW2126/Desktop/project/Play_List/playlist.txt","at");
			char music[51]; char notion[20];
			printf("추가하고자 하는 노래를 입력해주세요 :");
			scanf("%s %[^\n]",&notion,&music);
			fprintf(file,"%s %s\n",notion,music);
			fclose(file);// file IO 에 넣기
		
//= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =		
			enqueue(q,notion,music);
			printf("노래가 성공적으로 추가되었습니다!\n");
		}else if(n==2){// 노래 삭제 기능
			
		}else if(n==3){// 플레이 리스트 보는 기능
			FILE *in = fopen("C:/Users/SW2126/Desktop/project/Play_List/playlist.txt","r");
			char chr = fgetc(in);
			while(!feof(in)){
				printf("%c",chr);
				chr = fgetc(in);
			}
			fclose(in);
			//printQ(q);
		}else if(n==4){// 플레이 리스트 정렬하는 기능 
		
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
		printf("Queue is Empty!\n");
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
DataType peek(Queue* q){
	if(isEmpty(q)){
		printf("Queue is Empty!\n");
		return 0;
	}
	else{
		return getData(q->front);
	}
}
void printQ(Queue *q){
	Node* temp = q->front;
	printf("QUEUE : ");
	while(temp != NULL){
		printf("%s ",getData(temp));
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
