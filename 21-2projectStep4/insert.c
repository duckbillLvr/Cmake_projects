#include "my_func.h"

void insert(TEL** pe, int* cnt, int max_num)
{
	if (*cnt >= max_num) //�ִ����尳�� �ʰ�
		printf("OVERFLOW\n");
	else
	{
		*(pe + *cnt) = NULL;
		*(pe + *cnt) = (TEL*)malloc(sizeof(TEL)); //�Է��� ���� �Ǿ����Ƿ� �����Ҵ� ���ش�.
		//��������� �Էµ� ������ŭ �����Ҵ��� �̷�� ����. �Է°���<=max_num
		TEL* put = *(pe + *cnt);

		char name[101] = { 0 }, phone[101] = { 0 }, birth[101] = { 0 }; //�ӽ÷� �Է� ���� �迭
		printf("Name:");
		scanf("%s", name);
		getchar();
		printf("Phone_number:");
		scanf("%s", phone);
		getchar();
		printf("Birth:");
		scanf("%s", birth);
		getchar();
		//�ڷḦ �Է�
		put->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
		put->phone = (char*)malloc(sizeof(char) * (strlen(phone) + 1));
		put->birth = (char*)malloc(sizeof(char) * (strlen(birth) + 1));
		//�� �迭�� ũ�⸦ ���ϰ� �ش�ũ��+1��ŭ �����Ҵ� �Ѵ�.
		strcpy(put->name, name);
		strcpy(put->phone, phone);
		strcpy(put->birth, birth);
		//����ü�� �ڷᰪ ����
		(*cnt)++;                   //�ο��� ����
		printf("<< %d >>\n", *cnt); //�Էµ� �ο���
		sort(pe, cnt);              //�Էµ� �� ��ŭ �����Ͽ� �ش�.
	}
}