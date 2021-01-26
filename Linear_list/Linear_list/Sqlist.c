#include<stdio.h>
#include<stdlib.h>
#include"SqList.h"

Status List_Init(SqListPtr L)
{
	Status s = fail;
	if (L == NULL)
	{
		L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
		if (L->elem)
		{
			L->list_size = LIST_INIT_SIZE;
			L->length = 0;
			s = success;
		}
	}
	return s;
}
void List_Destory(SqListPtr L)
{
	if (L)
	{
		if (L->elem)
		{
			free(L->elem);
			L->elem = NULL;
			L->length = 0;
		}
	}
}
void List_Clear(SqListPtr L)
{
	if (L)
	{
		L->length = 0;
	}
}
bool List_Empty(SqListPtr L)
{
	return (L->length == 0);
}
int List_Size(SqListPtr L)
{
	return L->length;
}

//����---��λ��
Status List_Retrival(SqListPtr L, int pos, ElemType *elem)
{
	Status s = range_error;
	if (L)
	{
		if (pos >= 1 && pos <= L->length)
		{
			*elem = L->elem[pos];
			s = success;
		}
	}
	return s;
}
//����---��ֵ
Status List_Locate(SqListPtr L, ElemType elem, int *pos)
{
	Status s = range_error;
	int i = i;
	if (L)
	{
		for (i = 1; i <= L->length; i++)
		{
			if (L->elem[i] == elem)
			{
				*pos = i;
				s = success;
				break;
			}
		}
	}
	return s;
}

//����Ԫ��
Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
	Status s = range_error;
	if (pos >= 1 && pos <= L->length + 1) 
	{
		if (L && L->length < L->list_size) 
		{
			for (int i = L->length - 1; i >= pos - 1; i--) 
			{
				L->elem[i + 1] = L->elem[i];
			}
			L->elem[pos - 1] = elem;
			L->length++;
			s = success;
		}
	}
	else s = fail;
	return s;
}

//ɾ��Ԫ��
Status List_delete(SqListPtr L, int pos)
{
	Status s = range_error;
	if (pos >= 1 && pos < L->length + 1) 
	{
		if(L && L->length > 0) 
		{
			for (int i = pos; i < L->length; i++) 
				L->elem[i - 1] = L->elem[i];
			L->length--;
			s = success;
		}
	}
	else s = fail;
	return s;
}

//����ǰ��
Status List_Prior(SqListPtr L, int pos, ElemType * elem)
{

}

//���Һ��
Status List_Next(SqListPtr L, int pos, ElemType *elem)
{

}