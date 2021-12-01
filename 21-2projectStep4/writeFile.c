#include "my_func.h"
void saveFile(TEL** pe, int* cnt)//종료시 파일에 저장하는 함수
{
	FILE* fp = NULL;
	fp = fopen("PHONE_BOOK.txt", "w");//PHONE_BOOK.txt파일을 write모드로 연다
	if (fp != NULL)//파일 열시 성공시 실행
	{
		for (TEL** p = pe; p < pe + *cnt; p++)//구조체 정보를 파일에 입력
			fprintf(fp, "%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
	}
	fclose(fp);//파일입출력 종료
}