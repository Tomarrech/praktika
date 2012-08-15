#include "stdafx.h"
#include "test_sort.h"
#include <malloc.h>

bool doTest(fun_sort func, int *ARRAY, int SIZE_ARRAY);
void fNullTest(fun_sort func, int *ARRAY);
void fSingleTest(fun_sort func, int *ARRAY);
void fTwoTest(fun_sort func, int *ARRAY);
void fmoarTest(fun_sort func, int *ARRAY);
void fClonesTest(fun_sort func, int *ARRAY);

void MyTest(fun_sort func)		//this function starts all of enable functions
{
	int *ARRAY;
	ARRAY = (int*)malloc(1000000 * sizeof(int));	// create dinamic array
	fNullTest(func, ARRAY);		
	fSingleTest(func, ARRAY);
	fTwoTest(func, ARRAY);
	fmoarTest(func, ARRAY);
	fClonesTest(func, ARRAY);
	free(ARRAY);	//make memory free =)
}

bool doTest(fun_sort func, int *ARRAY, int SIZE_ARRAY)		//fuction see, if arguments are sorted
{
	func(ARRAY, SIZE_ARRAY);
	for(int i = 1; i < SIZE_ARRAY; ++i)
	{
		if(ARRAY[i] < ARRAY[i-1])
		{
			return false;
		}
	}
	return true;
}

void fNullTest(fun_sort func, int *ARRAY)			//return false.if array is empty
{
	int SIZE_ARRAY = 1;
	bool check;

	check = doTest(func, ARRAY, SIZE_ARRAY);
	if(!check)
	{
		printf("Sort fault if the array is empty\n");
	}
}

void fSingleTest(fun_sort func, int *ARRAY)	//return false, if array consists of one element
{
	int SIZE_ARRAY = 1;
	bool check;

	ARRAY[0] = 5;

	func(ARRAY, SIZE_ARRAY);
	check = (ARRAY[0] == 5);
	if(!check)
	{
		printf("Sort fault if the array consists of only one element\n");
	}
}

void fTwoTest(fun_sort func, int *ARRAY)	//return false, if array consists of two only elements
{
	int SIZE_ARRAY = 2;
	bool check;

	ARRAY[0] = 2;
	ARRAY[1] = 1;

	check = doTest(func, ARRAY, SIZE_ARRAY);
	if(!check)
	{
		printf("Sort fault if the array consists of two element\n");
	}
}

void fmoarTest(fun_sort func, int* ARRAY)		//will return fale, if sort function wount be able to process big array
{
	int SIZE_ARRAY = 1000000;
	bool check;

	for (int i = 0; i < SIZE_ARRAY; ++i)
	{
		ARRAY[i] = SIZE_ARRAY - i;
	}

	check = doTest(func, ARRAY, SIZE_ARRAY);
	if(!check)
	{
		printf("Sort fault if the array consists of 1000000 element\n");
	}
}

void fClonesTest(fun_sort func, int *ARRAY)		//return false, if arrray don't sort identical elem
{
	int SIZE_ARRAY = 1000;
	bool check;

	for(int i = 0; i < 1000; ++i)
	{
		ARRAY[i] = 1;
	}

	check = doTest(func, ARRAY, SIZE_ARRAY);
	if(!check)
	{
		printf("Sort fault if the array consists of identical element\n");
	}
}
