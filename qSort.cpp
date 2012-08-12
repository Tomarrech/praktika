#include "stdafx.h"
#include "qSort.h"
#include <iostream>
#include <math.h>
#include <time.h>
#include <assert.h>
using namespace std;

const int N = 11;

int FindMiddle(int *ARRAY, int size);
void swap(int* t1, int* t2);
void partition(int* ARRAY, int *low, int *last, int mid);



int _tmain()
{
	int ARRAY[N];
	for(int i = 0; i<N; i++)
	{	srand(time(NULL)*i);
		ARRAY[i]=65 + rand() % 25;
	}
	
	qSort(ARRAY, N-1);
	system("pause");
}

void qSort(int* ARRAY, int size)
{
	assert(size >= 0);
	int low = 0;
	int high = size - 1;
	int mid = FindMiddle(ARRAY, high);
	
	partition(ARRAY, &low, &high, mid);
	
	if(low < size - 1)	qSort(ARRAY + low, size - low);
	if(high > 0)		qSort(ARRAY, high + 1);
	
}

int FindMiddle(int *ARRAY, int size)
{	
	srand(time(NULL));
	return ARRAY[rand() % size];
}

void partition(int* ARRAY, int *low, int *high, int mid)
{
	do{									
		while(ARRAY[*low] < mid)	{(*low)++ ;}
		while(ARRAY[*high] > mid)	{(*high)-- ;}	
			if(low <= high) {swap(&ARRAY[*low], &ARRAY[*high]);
								low++; high--;}
		}while(*low <= *high);
}

void swap(int* t1, int* t2)
{
		int temp = *t1;			
		*t1=*t2;				
		*t2 = temp;
}