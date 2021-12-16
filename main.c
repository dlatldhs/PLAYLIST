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

int main(){
	Queue* q = createQueue();
	while(1){
		printf("\n�޴�\n1. �÷��� ����Ʈ�� �뷡 �߰�\n2. �÷��� ����Ʈ ����\n3. �÷��� ����Ʈ ����\n4. �÷��� ����Ʈ ����\n5. ���α׷� ����\n�ϰ����ϴ� �۾��� ������ �ּ���(����)....");
		n=0;
		scanf("%d",&n);
		if(n==1){// �뷡 �ִ� ���
			FILE *file = fopen("C:/Users/SW2127/Desktop/all/make_me/algorithm/playlist.txt","at");
			char music[51]; char notion[20];
			printf("�߰��ϰ��� �ϴ� �뷡�� �Է����ּ��� :");
			scanf("%s %[^\n]",&notion,&music);
			fprintf(file,"%s %s\n",notion,music);
			fclose(file);// file IO �� �ֱ�
		
//= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =	
			enqueue(q,notion,music);
			printf("�뷡�� ���������� �߰��Ǿ����ϴ�!\n");
		}else if(n==2){// �뷡 ���� ���
			dequeue(q);
			FILE *fp = fopen("C:/Users/SW2127/Desktop/all/make_me/algorithm/playlist.txt", "r+");
			char buf[256];
			rewind(fp);
			{
	        	long seek, start;
	        	while(1)
	        	{
	          		seek = ftell(fp);
	          		if (fgets(buf, 256, fp) == NULL) break;
	          		if (strstr(buf, "[5]") != NULL)
	         	 	{
	           		 	long len = filelength(fileno(fp))-ftell(fp);
	            		char *tmp = (char *)malloc(len);
	
	       		        len = fread(tmp, 1, len, fp);
	           
			            fseek(fp, start, SEEK_SET);
			            fwrite(tmp, 1, len, fp);
			            fflush(fp);
			            free(tmp);
			            _chsize(fileno(fp), ftell(fp));
	           			break;
	          		} 
	        	}
	      	}	
		}else if(n==3){// �÷��� ����Ʈ ���� ���
			char chr[100]={0x00,};
			FILE *in = fopen("C:/Users/SW2127/Desktop/all/make_me/algorithm/playlist.txt","r");
			while(1){
				if(feof(in)!=0) break;
				fgets(chr, sizeof(chr), in);
				printf("%s",chr);
			}
			//printQ(q);
		}else if(n==4){// �÷��� ����Ʈ �����ϴ� ��� 
			FILE *fp = fopen("C:/Users/SW2127/Desktop/all/make_me/algorithm/playlist.txt","r");
			
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
void sorted(char sort[])
{
	int i,temp;
	for(i=0;i!=sort[i]!=NULL;i++)
	{
		if(sort[i]<sort[i+1])
		{
			temp = sort[i];
			sort[i] = sort[i+1];
			sort[i+1] = temp;
		}
	}
}
