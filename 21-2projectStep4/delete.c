#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"
#pragma warning(disable:4996)

void delete (TEL** pe, int* cnt)
{
    if (*cnt == 0) //저장된 정보가 없을때
        printf("NO MEMBER\n");
    else
    {
        printf("Name:"); // 고정
        char tmp[21];
        scanf("%s", tmp);
        getchar();

        int found = 0;
        TEL** p;
        for (p = pe; p < pe + *cnt; p++)
        {
            if (!strcmp((*p)->name, tmp))
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            for (TEL** q = p; q < pe + *cnt - 1; q++)
            {
                (*q)->name = (char*)realloc((*q)->name, sizeof(char) * (strlen((*(q + 1))->name) + 1));
                (*q)->phone = (char*)realloc((*q)->phone, sizeof(char) * (strlen((*(q + 1))->phone) + 1));
                (*q)->birth = (char*)realloc((*q)->birth, sizeof(char) * (strlen((*(q + 1))->birth) + 1));

                strcpy((*q)->name, (*(q + 1))->name);
                strcpy((*q)->phone, (*(q + 1))->phone);
                strcpy((*q)->birth, (*(q + 1))->birth);
            }
            (*cnt)--;
            free(pe[*cnt]->name);
            free(pe[*cnt]->phone);
            free(pe[*cnt]->birth);
            free(pe[*cnt]);
        }
    }
}