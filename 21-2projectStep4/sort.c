#include "my_func.h"
void sort(TEL** pe, int* cnt)
{
	for (int i = 0; i < *cnt - 1; i++) //버블 정렬
	{
		for (int j = 0; j < *cnt - i - 1; j++)
		{
			if (strcmp(pe[j]->name, pe[j + 1]->name) > 0) //이름순으로 정렬
			{
				TEL* tmp = pe[j];
				pe[j] = pe[j + 1];
				pe[j + 1] = tmp;
			}
		}
	}
}