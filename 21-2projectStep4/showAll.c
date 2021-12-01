#include "my_func.h"
void show(TEL** pe, int* cnt)
{
	for (TEL** p = pe; p < pe + *cnt; p++)//모든 구조체의 항 출력
		printf("%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
}