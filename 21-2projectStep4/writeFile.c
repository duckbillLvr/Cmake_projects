#include "my_func.h"
void saveFile(TEL** pe, int* cnt)//����� ���Ͽ� �����ϴ� �Լ�
{
	FILE* fp = NULL;
	fp = fopen("PHONE_BOOK.txt", "w");//PHONE_BOOK.txt������ write���� ����
	if (fp != NULL)//���� ���� ������ ����
	{
		for (TEL** p = pe; p < pe + *cnt; p++)//����ü ������ ���Ͽ� �Է�
			fprintf(fp, "%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
	}
	fclose(fp);//��������� ����
}