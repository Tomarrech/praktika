#include "stdafx.h"
#include "bSearch.h"


bool Inside(int Begin,int End,int Key);
int findMid(int first, int last);
int search(int *ARRAY, int *min, int mid, int *max, int Key);


int bSearch(int *ARRAY, int SIZE, int Key)
{
	int min = 0;
	int max = SIZE - 1;
	int Found = -1;
	
	
	if(Inside(ARRAY[min],ARRAY[max],Key))
	{
		int mid = 0;
		while(min < max)
		{
			mid = findMid(min,max);
			if((Found = search(ARRAY,&min,mid,&max,Key) != -1))
			{
				break;
			}
		}	return Found;
	}
	else
	{
		return Found;
	}	
}	
	


bool Inside(int Begin,int End,int Key)
{
	return !(Begin > Key || End < Key);
}

int indMid(int first, int last)
{
	return first +(last - first) / 2;
}


int search(int *ARRAY, int *min, int mid, int *max, int Key)
{
	
	if(ARRAY[mid] == Key)
	{
		return mid;
	}
	
	else if (ARRAY[mid] > Key)
	{
		(*max) = mid;
	}
	
	else if (ARRAY[mid] < Key)
	{
		(*min) = mid + 1;
	}
	
	return -1;
	
}