#include <stdio.h>
#define MAX 10000
int main(){
	/* fputs 파일에 문자 쓰기 
	// 파일을 열기 위해서는 FILE 포인터를 선언해줘야 함
	// fopen("주소","파일 열 형식")
	// 텍스트로 일거나 씀 
	FILE *file = fopen("C:/Users/SW2126/Desktop/project/Play_List/e.g/test.txt","wt");
	if(file == NULL)
		printf("파일이 열리지 않습니다..");
	else
		fputs("hello wolrd!",file);
	
	// 파일 닫기  
	fclose(file);
	*/
	
	/* fgets()로 파일 불러오기 
	// 읽기 전용 파일 
	FILE *file = fopen("C:/Users/SW2126/Desktop/project/Play_List/e.g/test.txt","rt");
	char str[MAX];
	
	if(file == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
	}
	else{
		//파일에 쓰여진 글 불러오기
		while(1){
			// fgets 형식 : fgets(저장할 문자열,읽어들일 최대 문자수,읽어들일 파일) 
			if(fgets(str,MAX,file) != NULL)
				printf("%s",str);
			else
				break; 
		}
	}
	fclose(file);
	*/
	
	// fprintf() 사용하기
	FILE *file = fopen("C:/Users/SW2126/Desktop/project/Play_List/e.g/test.txt","wt");// 텍스트로 읽고 쓰기
	//int arr[4] = {1,2,3,4};
	char str[51]; char p[MAX];
	printf("서동현 - Frank Ocean (Feat. SOLE) (Prod. Cosmic Boy)\n위와 같은 형태로 입력해주세요.\n");
	gets(str);
	if(file == NULL)
		printf("파일이 열리지 않습니다.\n");
	else{
		//fprintf(file,"%d %d %d",arr[0],arr[1],arr[2]);
		fprintf(file,"%s\n",str);
		printf("노래가 성공적으로 추가되었습니다!"); 
	}// fprintf(FILE *,지정할 서식,서식에 맞춘 변수) 
	fclose(file);
	
}
