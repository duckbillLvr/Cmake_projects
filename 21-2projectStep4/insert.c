#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"
#pragma warning(disable:4996)

void insert(TEL** pe, int* cnt, int max_num)
{
    if (*cnt >= max_num) //�ִ����尳�� �ʰ�
        printf("OVERFLOW\n");
    else
    {
        *(pe + *cnt) = NULL;
        *(pe + *cnt) = (TEL*)malloc(sizeof(TEL)); //�Է��� ���� �Ǿ����Ƿ� �����Ҵ� ���ش�.
        //��������� �Էµ� ������ŭ �����Ҵ��� �̷�� ����. �Է°���<=max_num
        TEL* put = *(pe + *cnt);

        char name[101] = { 0 }, phone[101] = { 0 }, birth[101] = { 0 }; //�ӽ÷� �Է� ���� �迭
        printf("Name:");                                          // ����
        scanf("%s", name);
        getchar();
        printf("Phone_number:"); // ����
        scanf("%s", phone);
        getchar();
        printf("Birth:"); //����
        scanf("%s", birth);
        getchar();

        put->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
        put->phone = (char*)malloc(sizeof(char) * (strlen(phone) + 1));
        put->birth = (char*)malloc(sizeof(char) * (strlen(birth) + 1));
        //�� �迭�� ũ�⸦ ���ϰ� �ش�ũ��+1��ŭ �����Ҵ� �Ѵ�.
        strcpy(put->name, name);
        strcpy(put->phone, phone);
        strcpy(put->birth, birth);

        (*cnt)++;                   //�ο��� ����
        printf("<< %d >>\n", *cnt); //�Էµ� �ο���
        sort(pe, cnt);              //�Էµ� �� ��ŭ �����Ͽ� �ش�.
    }
}

void sort(TEL** pe, int* cnt)
{
    for (int i = 0; i < *cnt - 1; i++) //���� ����
    {
        for (int j = 0; j < *cnt - i - 1; j++)
        {
            if (strcmp(pe[j]->name, pe[j + 1]->name) > 0) //�̸������� ����
            {
                TEL* tmp = pe[j];
                pe[j] = pe[j + 1];
                pe[j + 1] = tmp;
            }
        }
    }
}