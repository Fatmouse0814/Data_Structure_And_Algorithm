#include<stdio.h>
#include<stdlib.h>
#include"TestSqList.h"

int main()
{
	int opt = 1;
	SqList list;
	int pos, size,i;
	ElemType e, *data;
	Status s;
	while (opt != 6)
	{
		printf("请输入选项：\n");
		printf("1:测试建立线性表\n");
		printf("2:测试清空线性表\n");
		printf("3:测试求某位置的线性表元素值及前驱后继\n");
		printf("4:测试查询某元素的位置\n");
		printf("5:测试线性表的长度\n");
		printf("6:结束程序\n");
		scanf_s("%d", &opt);
		switch (opt)
		{
		case 1:
			printf("线性表长度:\n");
			scanf_s("%d", &size);
			data = (ElemType*)malloc(size * sizeof(ElemType));
			if (data == NULL) break;
			printf("线性表元素:\n");
			for(i = 0;i < size; i++)
				scanf_s("%d", &data[i]);
			s = Test_CreateList(&list, data, size);
			if (s != success)
				printf("建立线性表失败\n");
			free(data);
			List_Destory(&list);
			break;
		case 2:
			printf("线性表长度:\n");
			scanf_s("%d", &size);
			data = (ElemType*)malloc(size * sizeof(ElemType));
			if (data == NULL) break;
			printf("线性表元素:\n");
			for (i = 0; i < size; i++)
				scanf_s("%d", &data[i]);
			s = Test_CreateList(&list, data, size);
			if (s == success)
			{
				s = Test_ClearList(&list);
				if (s == success)
				{
					printf("已经清空线性表\n");
				}
				else printf("清空线性表失败\n");
			}
			else printf("建立线性表失败\n");
			free(data);
			List_Destory(&list);
			break;
		case 3:
			printf("线性表长度:\n");
			scanf_s("%d", &size);
			data = (ElemType*)malloc(size * sizeof(ElemType));
			if (data == NULL) break;
			printf("线性表元素:\n");
			for (i = 0; i < size; i++)
				scanf_s("%d", &data[i]);
			s = Test_CreateList(&list, data, size);
			if (s == success)
			{
				printf("线性表位置:\n");
				scanf_s("%d", &pos);
				s = Test_RetrivalPriorNext(&list, pos);
			}
			else printf("建立线性表失败\n");
			free(data);
			List_Destory(&list);
			break;
		case 4:
			printf("线性表长度:\n");
			scanf_s("%d", &size);
			data = (ElemType*)malloc(size * sizeof(ElemType));
			if (data == NULL) break;
			printf("线性表元素:\n");
			for (i = 0; i < size; i++)
				scanf_s("%d", &data[i]);
			s = Test_CreateList(&list, data, size);
			if (s == success)
			{
				printf("线性表元素:\n");
				scanf_s("%d", &e);
				s = Test_Locate(&list, e);
			}
			else printf("建立线性表失败\n");
			free(data);
			List_Destory(&list);
			break;
		case 5:
			printf("线性表长度:\n");
			scanf_s("%d", &size);
			data = (ElemType*)malloc(size * sizeof(ElemType));
			if (data == NULL) break;
			printf("线性表元素:\n");
			for (i = 0; i < size; i++)
				scanf_s("%d", &data[i]);
			s = Test_CreateList(&list, data, size);
			if (s == success)
			{
				Test_Size(&list);
			}
			else printf("建立线性表失败\n");
			free(data);
			List_Destory(&list);
			break;
		default:
			break;
		}
	}
}