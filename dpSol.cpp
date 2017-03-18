#include <iostream>

using namespace std;

/*
	opt(x) = 1+ min( opt(x-2) , opt(x-3) , opt(x-5) , opt(x-6))
*/

int opt(int amount,int arr[], int n);

int findMin(int arr[],int n);


int main(int argc, char const *argv[])
{
	int n=2;

	int arr[] = {2,3};

	int amount = 47;
	
	cout<<endl<<opt(amount,arr,n);


	return 0;
}

int opt(int amount,int arr[], int n){

	int tempArray[n];

	if (amount == 0 )
	{
		return 0;
	}
	else if (amount < arr[0])
	{
		// BIGGEST POSSIBLE VALUE 
		// so that x is not selected

		return 2147483647;
	}
	else{

		for (int i = 0; i < n; ++i)
		{
			tempArray[i] = opt(amount-arr[i] , arr , n);

		}

		return (1 + findMin(tempArray,n) );
	}

	

}

int findMin(int arr[],int n){

	int min=arr[0];

	for (int i = 1; i < n; ++i)
	{
		if (min>arr[i])
		{
			min = arr[i];
		}
	}

	return min;
}