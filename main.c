#include <stdio.h>
#include <stdbool.h>
#define MAX 10000
int i,j,k,l,n;
int main(){
	printf("\n�޴�\n1. �÷��� ����Ʈ�� �뷡 �߰�\n2. �÷��� ����Ʈ ����\n3. �÷��� ����Ʈ ����\n4. �÷��� ����Ʈ ����\n5. ���α׷� ����\n�ϰ����ϴ� �۾��� ������ �ּ���(����)....");
	while(1){
		n=0;
		scanf("%d",&n);
		if(n==1){// �뷡 �ִ� ��
		//(������ ���� ���ؼ��� FILE �����͸� ��������� ��) fopen("�ּ�","���� �� ����") txt write 
			FILE *file = fopen("C:/Users/SW2126/Desktop/project/Play_List/playlist.txt","at");
			char music[51];
			char notion[20];
			//printf("������ - Frank Ocean (Feat. SOLE) (Prod. Cosmic Boy)\n���� ���� ���·� �Է����ּ���.\n");
			printf("�߰��Ϸ��� �ϴ� �뷡�� �Է����ּ��� :");
			scanf("%s %[^\n]",&notion,&music);//[^\n] ���� ���� �� 
			fprintf(file,"%s %s\n",notion,music);
			printf("�뷡�� ���������� �߰��Ǿ����ϴ�!\n");
			fclose(file);
		}
		else if(n==2){// �뷡 ���� ���
		
		}
		else if(n==3){// �÷��� ����Ʈ ���� ���
			FILE *in = fopen("C:/Users/SW2126/Desktop/project/Play_List/playlist.txt","r");
			char chr = fgetc(in);
			while(!feof(in)){
				printf("%c",chr);
				chr = fgetc(in);
			}
		}
		else if(n==4){// �÷��� ����Ʈ �����ϴ� ��� 
		
		}
		else if(n==5){// ���α׷� ���� �ϴ� ��� 
			printf("���α׷��� ���� �˴ϴ�....");
			return 0;
		}
	}
	return 0;
}
