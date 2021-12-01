#include "my_func.h"

void ReqFromFile(TEL** pe, int* cnt, int max_num)
{
	FILE* fp = NULL;
	fp = fopen("PHONE_BOOK.txt", "r");//PHONE_BOOK.txt�� read�Ѵ�.
	if (fp != NULL)//PHONE_BOOK.txt�� ������ ��� ����
	{
		while (1)
		{
			if (*cnt >= max_num)//�Է� ���� > max_num�� �Ƿ��ϸ� OVERFLOW ��°� �Բ� ����
			{
				printf("OVERFLOW\n");
				break;
			}
			char name[101] = { 0 }, phone[101] = { 0 }, birth[101] = { 0 };
			//�ڷḦ �ӽ÷� �Է� ���� �迭 ����
			fscanf(fp, "%s %s %s", name, phone, birth);//���Ϸ� ���� �ڷᰪ�� �о� �´�.
			if (feof(fp))//�Է� ���� �ڷᰡ ���� ��� ����
				break;

			*(pe + *cnt) = NULL;
			*(pe + *cnt) = (TEL*)malloc(sizeof(TEL)); //�Է��� ���� �Ǿ����Ƿ� �����Ҵ� ���ش�.
			//��������� �Էµ� ������ŭ �����Ҵ��� �̷�� ����. �Է°���<=max_num
			TEL* put = *(pe + *cnt);
			put->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
			put->phone = (char*)malloc(sizeof(char) * (strlen(phone) + 1));
			put->birth = (char*)malloc(sizeof(char) * (strlen(birth) + 1));
			//�� �迭�� ũ�⸦ ���ϰ� �ش�ũ��+1��ŭ �����Ҵ� �Ѵ�.
			strcpy(put->name, name);
			strcpy(put->phone, phone);
			strcpy(put->birth, birth);
			//�ڷḦ ����ü�� �����Ѵ�.
			(*cnt)++;//�Է� ���� +1
		}
		sort(pe, cnt);//�Է¹��� ��� �ڷḦ ����
		fclose(fp);//��������� ����
	}
}