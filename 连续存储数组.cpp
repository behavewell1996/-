//c风格
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct Arr
{
	int* pBase;  //第一个元素地址
	int len;  //数组长度
	int cnt;  //当前个数
	//int increment;  //自动增长因子
};
void init_arr(struct Arr* arr, int length)
{
	arr->pBase = (int*)malloc(sizeof(int)* length);
	//是否分配成功
	if (NULL == arr->pBase)
	{
		printf("分配失败\n");
		exit(-1);
	}
	else
	{
		arr->len = length;
		arr->cnt = 0;
	}
	return;
}
bool is_full(struct Arr* arr);
bool append_arr(struct Arr* arr,int val) //追加
{
	if (is_full(arr))
		return false;
	else
	{
		arr->pBase[arr->cnt] = val;
		arr->cnt++;
		return true;
	}
}
bool insert_arr(struct Arr* arr,int pos,int val)
{
	if (is_full(arr) || pos >= arr->len || pos <= 0)
		return false;
	else
	{
		for (int i = arr->cnt - 1; i >= pos; i--)
		{
			arr->pBase[i + 1] = arr->pBase[i];
		}
		arr->pBase[pos] = val;
		arr->cnt++;
		return true;
	}

}
bool is_empty(struct Arr* arr);
bool delete_arr(struct Arr* arr,int pos,int* value)
{
	if (is_empty(arr)||pos>arr->cnt-1||pos<0)
	{
		return false;
	}
	else
	{
		*value = arr->pBase[pos];
		for (int i = pos; i < arr->cnt; i++)
		{
			arr->pBase[i] = arr->pBase[i+1];
		}
		arr->cnt--;
		
		return 1;
	}

}
bool get(struct Arr* arr,int pos,int* value)
{
	if (pos < 0 || pos >= arr->cnt)
		return false;
	else
	{
		*value = arr->pBase[pos];
	}
}
bool is_empty(struct Arr* arr)
{
	if (arr->cnt == 0)
	{
		return true;
	}
	else
		return false;

}
bool is_full(struct Arr* arr)
{
	if (arr->cnt == arr->len)
		return true;
	else
		return false;
}
void show_arr(struct Arr* arr)
{
	if (is_empty(arr))
	{
		printf("数组为空\n");
	}
	else
	{
		for (int i = 0; i < arr->cnt; i++)
		{
			printf("%d ", arr->pBase[i]);
		}
	}
}
void inverse_arr(struct Arr* arr)
{
	int i = 0;
	int j = arr->cnt - 1;
	int tmp;
	while (i < j)
	{
		tmp = arr->pBase[i];
		arr->pBase[i] = arr->pBase[j];
		arr->pBase[j] = tmp;
		i++;
		j--;
	}
	return;
}


int main(void)
{
	struct Arr arr;
	init_arr(&arr, 6);
	printf("第一次显示\n");
	show_arr(&arr);
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 4);
	append_arr(&arr, 1);
	printf("第二次显示\n");
	show_arr(&arr);
	insert_arr(&arr, 1,100);
	printf("第三次显示\n");
	show_arr(&arr);
	int value = 0;
	delete_arr(&arr, 1,&value);
	printf("第四次显示\n");
	show_arr(&arr);
	printf("删除的值\n");
	printf("%d\n", value);
	get(&arr, 2, &value);
	printf("get的值\n");
	printf("%d\n", value);
	inverse_arr(&arr);
	printf("第五次显示\n");
	show_arr(&arr);
	system("pause");
	
	return 0;
	
}