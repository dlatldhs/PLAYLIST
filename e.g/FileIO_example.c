#include <stdio.h>
#define MAX 10000
int main(){
	/* fputs ���Ͽ� ���� ���� 
	// ������ ���� ���ؼ��� FILE �����͸� ��������� ��
	// fopen("�ּ�","���� �� ����")
	// �ؽ�Ʈ�� �ϰų� �� 
	FILE *file = fopen("C:/Users/SW2126/Desktop/project/Play_List/e.g/test.txt","wt");
	if(file == NULL)
		printf("������ ������ �ʽ��ϴ�..");
	else
		fputs("hello wolrd!",file);
	
	// ���� �ݱ�  
	fclose(file);
	*/
	
	/* fgets()�� ���� �ҷ����� 
	// �б� ���� ���� 
	FILE *file = fopen("C:/Users/SW2126/Desktop/project/Play_List/e.g/test.txt","rt");
	char str[MAX];
	
	if(file == NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
	}
	else{
		//���Ͽ� ������ �� �ҷ�����
		while(1){
			// fgets ���� : fgets(������ ���ڿ�,�о���� �ִ� ���ڼ�,�о���� ����) 
			if(fgets(str,MAX,file) != NULL)
				printf("%s",str);
			else
				break; 
		}
	}
	fclose(file);
	*/
	
	// fprintf() ����ϱ�
	FILE *file = fopen("C:/Users/SW2126/Desktop/project/Play_List/e.g/test.txt","wt");// �ؽ�Ʈ�� �а� ����
	//int arr[4] = {1,2,3,4};
	char str[51]; char p[MAX];
	printf("������ - Frank Ocean (Feat. SOLE) (Prod. Cosmic Boy)\n���� ���� ���·� �Է����ּ���.\n");
	gets(str);
	if(file == NULL)
		printf("������ ������ �ʽ��ϴ�.\n");
	else{
		//fprintf(file,"%d %d %d",arr[0],arr[1],arr[2]);
		fprintf(file,"%s\n",str);
		printf("�뷡�� ���������� �߰��Ǿ����ϴ�!"); 
	}// fprintf(FILE *,������ ����,���Ŀ� ���� ����) 
	fclose(file);
	
}
