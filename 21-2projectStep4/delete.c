#include "my_func.h"

void del(TEL **pe, int *cnt)
{
	if (*cnt == 0) //����� ������ ������
		printf("NO MEMBER\n");
	else
	{
		printf("Name:"); // ����
		char tmp[21];
		scanf("%s", tmp); //������ �̸� �Է�
		getchar();

		int found = 0;
		TEL **p;
		for (p = pe; p < pe + *cnt; p++)
		{
			if (!strcmp((*p)->name, tmp)) //������ �̸��� ���� �ι� �߰�
			{
				found = 1; //�����ι� �߽߰� found = 1
				break;
			}
		}

		if (found) //�����ι� �߽߰� ����
		{
			for (TEL **q = p; q < pe + *cnt - 1; q++) //������ ���� �ױ��� ����
			{
				(*q)->name = (char *)realloc((*q)->name, sizeof(char) * (strlen((*(q + 1))->name) + 1));
				(*q)->phone = (char *)realloc((*q)->phone, sizeof(char) * (strlen((*(q + 1))->phone) + 1));
				(*q)->birth = (char *)realloc((*q)->birth, sizeof(char) * (strlen((*(q + 1))->birth) + 1));
				//�ڷ� �Է��� ���Ͽ� ���� ���� ũ�⸸ŭ ũ�⸦ ���Ҵ� ���ش�.
				strcpy((*q)->name, (*(q + 1))->name);
				strcpy((*q)->phone, (*(q + 1))->phone);
				strcpy((*q)->birth, (*(q + 1))->birth);
				//�������� �ڷḦ ������ �´�.
			}
			(*cnt)--;
			free(pe[*cnt]->name);
			free(pe[*cnt]->phone);
			free(pe[*cnt]->birth);
			free(pe[*cnt]);
			//������ ���� ����ü�� �� ����� �����Ҵ� �����Ͽ� �ش�.
		}
	}
}