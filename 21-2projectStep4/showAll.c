#include "my_func.h"
void show(TEL** pe, int* cnt)
{
	for (TEL** p = pe; p < pe + *cnt; p++)//��� ����ü�� �� ���
		printf("%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
}