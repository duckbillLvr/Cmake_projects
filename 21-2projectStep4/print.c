#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"
#pragma warning(disable:4996)

void searchBirth(TEL** pe, int* cnt)
{
	printf("Birth:"); // ∞Ì¡§
	int tmp;
	scanf("%d", &tmp);
	getchar();

	for (int i = 0; i < *cnt; i++)
	{
		int month = 0;
		for (char* search = pe[i]->birth + 4; search < pe[i]->birth + 6; search++)
			month = month * 10 + (*search - '0');
		if (month == tmp)
			printf("%s %s %s\n", pe[i]->name, pe[i]->phone, pe[i]->birth);
	}
}

void show(TEL** pe, int* cnt)
{
	for (TEL** p = pe; p < pe + *cnt; p++)
		printf("%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
}