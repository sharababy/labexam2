#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void quicksort(int array[],long long int start,long long int end);

long long int partition(int array[],long long int start,long long int end);
 

void quicksort(int array[],long long int start,long long int end){


	int midplace;

	if (start<end)
	{
		midplace = partition(array,start,end);
		quicksort(array,start,midplace-1);
		quicksort(array,midplace+1,end);
	}
	
}



long long int partition(int array[],long long int start,long long int end){

	int pivot,temp;

	long long int pointer;

	pointer = start-1;
	pivot = array[end];

	for (int i = start; i < end; ++i)
	{
		if (array[i]<=pivot)
		{
			pointer=pointer+1;
			temp = array[pointer];
			array[pointer] = array[i];
			array[i] = temp;
		}
	}
	temp = array[pointer+1];
	array[pointer+1] = array[end];
	array[end] = temp;

	return (pointer+1);
}








