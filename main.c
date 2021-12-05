#include <stdio.h>
#include <stdbool.h>
#define MAX 10000
int i,j,k,l,n;
int main(){
	printf("\n메뉴\n1. 플레이 리스트에 노래 추가\n2. 플레이 리스트 삭제\n3. 플레이 리스트 보기\n4. 플레이 리스트 정렬\n5. 프로그램 종료\n하고자하는 작업을 선택해 주세요(숫자)....");
	while(1){
		n=0;
		scanf("%d",&n);
		if(n==1){// 노래 넣는 기
		//(파일을 열기 위해서는 FILE 포인터를 선언해줘야 함) fopen("주소","파일 열 형식") txt write 
			FILE *file = fopen("C:/Users/SW2126/Desktop/project/Play_List/playlist.txt","at");
			char music[51];
			char notion[20];
			//printf("서동현 - Frank Ocean (Feat. SOLE) (Prod. Cosmic Boy)\n위와 같은 형태로 입력해주세요.\n");
			printf("추가하려고 하는 노래를 입력해주세요 :");
			scanf("%s %[^\n]",&notion,&music);//[^\n] 공백 빼고 다 
			fprintf(file,"%s %s\n",notion,music);
			printf("노래가 성공적으로 추가되었습니다!\n");
			fclose(file);
		}
		else if(n==2){// 노래 삭제 기능
		
		}
		else if(n==3){// 플레이 리스트 보는 기능
			FILE *in = fopen("C:/Users/SW2126/Desktop/project/Play_List/playlist.txt","r");
			char chr = fgetc(in);
			while(!feof(in)){
				printf("%c",chr);
				chr = fgetc(in);
			}
		}
		else if(n==4){// 플레이 리스트 정렬하는 기능 
		
		}
		else if(n==5){// 프로그램 종료 하는 기능 
			printf("프로그램이 종료 됩니다....");
			return 0;
		}
	}
	return 0;
}
