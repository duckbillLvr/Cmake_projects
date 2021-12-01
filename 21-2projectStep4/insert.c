#include "my_func.h"

void insert(TEL** pe, int* cnt, int max_num)
{
	if (*cnt >= max_num) //최대저장개수 초과
		printf("OVERFLOW\n");
	else
	{
		*(pe + *cnt) = NULL;
		*(pe + *cnt) = (TEL*)malloc(sizeof(TEL)); //입력이 예정 되었으므로 동적할당 해준다.
		//결과적으로 입력된 개수만큼 동적할당이 이루어 진다. 입력개수<=max_num
		TEL* put = *(pe + *cnt);

		char name[101] = { 0 }, phone[101] = { 0 }, birth[101] = { 0 }; //임시로 입력 받을 배열
		printf("Name:");
		scanf("%s", name);
		getchar();
		printf("Phone_number:");
		scanf("%s", phone);
		getchar();
		printf("Birth:");
		scanf("%s", birth);
		getchar();
		//자료를 입력
		put->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
		put->phone = (char*)malloc(sizeof(char) * (strlen(phone) + 1));
		put->birth = (char*)malloc(sizeof(char) * (strlen(birth) + 1));
		//각 배열의 크기를 구하고 해당크기+1만큼 동적할당 한다.
		strcpy(put->name, name);
		strcpy(put->phone, phone);
		strcpy(put->birth, birth);
		//구조체에 자료값 복사
		(*cnt)++;                   //인원수 증가
		printf("<< %d >>\n", *cnt); //입력된 인원수
		sort(pe, cnt);              //입력된 수 만큼 정렬하여 준다.
	}
}