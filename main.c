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

void selectModeOne(Queue* q){
	FILE *file = fopen("playlist.txt","at");
	char music[51]; char notion[20];
	printf("�߰��ϰ��� �ϴ� �뷡�� �Է����ּ��� :");
	scanf("%s %[^\n]",&notion,&music);
	fprintf(file,"%s %s\n",notion,music);
	fclose(file);// file IO �� �ֱ�
	enqueue(q,notion,music);
	printf("�뷡�� ���������� �߰��Ǿ����ϴ�!\n");
}

void selectModeTwo(Queue* q){
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
	fclose(fp2);
	fclose(fp);

	int sum = remove(old); 
	int cnt = rename(newfile,old);
	
	if(sum == 0 && cnt == 0) {
		printf("...���Ͽ��� ���� ����\n");
	}
}

void selectModeThree(Queue* q){
	char chr[100];
	FILE *in = fopen("playlist.txt","r");
	int abc;
	printf("���Ϸ� ����(1) ť�� ����(2).....");
	scanf("%d",&abc);
	if(abc==1)
	{
		while(1){
			fgets(chr, 100, in);
			if(feof(in)!=0) break;
			printf("%s",chr);
		}
		fclose(in);	
	}
	else if(abc==2) printQ(q);
	else printf("�߸��� �Է�");
}
void selectModeFour(Queue* q){
	FILE *fp = fopen("playlist.txt", "r");
	FILE *fp2 = fopen("playlist2.txt", "w");
	
	char str[30];
	char *ptr;
	long value;
	
	char data[100];
	while(1){
		fgets(data, 100, fp);
		if(feof(fp)!=0) break;
		value = strtol(str, &ptr, 30);
		printf("%d", value);
	}
	fclose(fp);
	fclose(fp2);
}

void menu(){	
	printf("\n�޴�\n");
	printf("1. �÷��� ����Ʈ�� �뷡 �߰�\n");
	printf("2. �÷��� ����Ʈ ����\n");
	printf("3. �÷��� ����Ʈ ����\n");
	printf("4. �÷��� ����Ʈ ����\n");
	printf("5. ���α׷� ����\n");
	printf("�ϰ��� �ϴ� �۾��� ������ �ּ���(����)...");
}
void fileToQueue(Queue* q){
	FILE *fp = fopen("playlist.txt", "r");
	char data[100];
	DataType a, b;
	char *ptr;
	printf("���Ͽ� �ִ� ������ ť�� �ű�� ��...\n");
	while(1){
		fgets(data, 100, fp);
		if(feof(fp)!=0) break;
		ptr = strtok(data, " ");
		a = ptr;
		ptr = strtok(NULL, " ");
		b = ptr;
		enqueue(q,a,b);
	}
	fclose(fp);
}

int main(){
	Queue* q = createQueue();
	printf("===================================================\n");
	printf("c ������ �����ȿ� �������ּ���. \n");
	printf("===================================================\n");
	fileToQueue(q);
	while(1){
		menu();
		n=0;
		scanf("%d",&n);
		if(n==1){// �뷡 �ִ� ���
			selectModeOne(q);	
		}else if(n==2){// �뷡 ���� ���
			selectModeTwo(q);
		}else if(n==3){// �÷��� ����Ʈ ���� ���
			selectModeThree(q);
		}else if(n==4){// �÷��� ����Ʈ �����ϴ� ��� 
			selectModeFour(q);
		}else if(n==5){// ���α׷� ���� �ϴ� ��� 
			printf("���α׷��� ���� �˴ϴ�....");
			return 0;
		}
		else printf("�߸��� �Է�");
	}
	freeQueue(q); 
	return 0;
}

Node* createNode(DataType data, DataType datata){
	Node* newNode = malloc(sizeof(Node));
	newNode->data=data;
	newNode->datata=datata;
	newNode->link=NULL;
	
	return newNode;
}
DataType getData(Node* node){
	return node->data, node->datata;
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
		printf("...ť���� ���� ����\n");
		free(tempNode);
		return data;
	}
}
void printQ(Queue *q){
	Node* temp = q->front;
	if(isEmpty(q))
	{
		printf("ť�� ������ϴ�. \n");
		return ; 
	}
	printf("playlist: \n");
	while(temp){
		printf("%s %s\n", getData(temp));
		temp = getLink(temp);
	}
	printf("\n");
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
