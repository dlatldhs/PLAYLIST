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
	printf("\n�޴�\n");
	printf("1. �÷��� ����Ʈ�� �뷡 �߰�\n");
	printf("2. �÷��� ����Ʈ ����\n");
	printf("3. �÷��� ����Ʈ ����\n");
	printf("4. �÷��� ����Ʈ ����\n");
	printf("5. ���α׷� ����\n");
	printf("�ϰ��� �ϴ� �۾��� ������ �ּ���(����)...");
}

int main(){
	Queue* q = createQueue();
	printf("===================================================\n");
	printf("c ������ �����ȿ� �������ּ���. \n");
	printf("===================================================\n");
	while(1){
		menu();
		n=0;
		scanf("%d",&n);
		if(n==1){// �뷡 �ִ� ���
			FILE *file = fopen("playlist.txt","at");
			char music[51]; char notion[20];
			printf("�߰��ϰ��� �ϴ� �뷡�� �Է����ּ��� :");
			scanf("%s %[^\n]",&notion,&music);
			fprintf(file,"%s %s\n",notion,music);
			fclose(file);// file IO �� �ֱ�
			enqueue(q,notion,music);
			printf("�뷡�� ���������� �߰��Ǿ����ϴ�!\n");
			
		}else if(n==2){// �뷡 ���� ���
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
				printf("���� ����\n");
			}
			
		}else if(n==3){// �÷��� ����Ʈ ���� ���
			char chr[100];
			FILE *in = fopen("playlist.txt","r");
			while(1){
				fgets(chr, 100, in);
				if(feof(in)!=0) break;
				printf("%s",chr);
			}
			fclose(in);	
		}else if(n==4){// �÷��� ����Ʈ �����ϴ� ��� 
			FILE *fp = fopen("playlist.txt","r");
			fclose(fp);
			
		}else if(n==5){// ���α׷� ���� �ϴ� ��� 
			printf("���α׷��� ���� �˴ϴ�....");
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
		printf("playlist�� ����ֽ��ϴ�. \n");
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
