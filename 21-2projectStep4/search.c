#include "my_func.h"

void searchBirth(TEL** pe, int* cnt)
{
	printf("Birth:");
	int tmp;
	scanf("%d", &tmp);//ã�� ������ �Է�
	getchar();

	for (int i = 0; i < *cnt; i++)
	{
		int month = 0;
		for (char* search = pe[i]->birth + 4; search < pe[i]->birth + 6; search++)
			month = month * 10 + (*search - '0');//������ ���� �ִ� 5,6�� ���ڸ� �̿��Ͽ� �� ���
		if (month == tmp)//������ ���� ���� ��� ���
			printf("%s %s %s\n", pe[i]->name, pe[i]->phone, pe[i]->birth);
	}
}