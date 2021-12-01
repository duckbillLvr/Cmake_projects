#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"
#pragma warning(disable : 4996)

int main()
{
    int max_num;
    printf("Max_num:"); // ����
    scanf("%d", &max_num);

    TEL **pe = NULL;                              // ���� ������ ����ü
    pe = (TEL **)malloc(sizeof(TEL *) * max_num); // max_num�� ������ŭ �����Ҵ�
    if (pe == NULL)
        return -1;
    //�ȳ� �������̽�

    int select;
    int cnt = 0;      //��ü �ο��� ����
    int maintain = 1; // while�� �ݺ��� ���� ����
    while (maintain)
    {
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.ReqFromFile><6.Exit>\n");
        printf("Enter_the_menu_number:");
        scanf("%d", &select);
        getchar();

        switch (select)
        {
        case 1:
            insert(pe, &cnt, max_num); //�ڷ� �Է�
            break;
        case 2:
            show(pe, &cnt);
            break;
        case 3:
            delete (pe, &cnt);
            break;
        case 4:
            searchBirth(pe, &cnt);
            break;
        case 5:
            ReqFromFile(pe, &cnt, max_num);
            break;
        case 6:
            saveFile(pe, &cnt);
            maintain = 0;
            break;
        }
    }

    for (int i = 0; i < cnt; i++) //�� ������ ���Ͽ� �����Ҵ� ����
    {
        free(pe[i]->name);
        free(pe[i]->birth);
        free(pe[i]->phone);
        free(pe[i]);
    }
    free(pe); // max_num ������ŭ �Ҵ��� �Ϳ� ���Ͽ� �����Ҵ� ����
}