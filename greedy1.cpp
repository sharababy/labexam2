#include <iostream>
#include <cstdlib>
#include <ctime>

#include "quicksort.cpp" // reused code written by us in lab sessions

using namespace std;


#define SAMPLES 100		// number of test samples
#define MAX_DENOM 10    // max value of any denomination
#define MIN_DENOM 2     // min value of any denomination
#define MAX_DENOM_NUM 4 // max number of denominations
#define MIN_DENOM_NUM 2 // min number of denominations

int findValue(int arr[],int n,int amount);

void allDistinct(int arr[],int n,int maxDenom,int minDenom);

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int n,
		success=0,
		maxDenom = MAX_DENOM,
		minDenom = MIN_DENOM,
		mindenomNum = MIN_DENOM_NUM,
		maxdenomNum = MAX_DENOM_NUM;
	

	n = rand() % (maxdenomNum +1 -mindenomNum) + mindenomNum;

	int arr[n];

	allDistinct(arr,n,maxDenom,minDenom); // check of randomly generated denominations are distinct

	quicksort(arr,0,n-1);   // sort the array of denominations

	int amount;

	int samples = SAMPLES;

	for (int i = 0; i < samples; ++i)
	{
		amount = rand()%300;

		if(findValue(arr,n,amount)==1){
			success++;
		}
	}

	cout<<"Success rate : "<<success<<"/"<<samples<<endl;

	return 0;
}


int findValue(int arr[],int n,int amount)
{


	int remind[n+1],val[n+1],result=0;

	remind[n] = amount;


	for (int i = n-1; i >=0; --i)
	{
		if(remind[i+1] >= arr[i] ){
			remind[i] = remind[i+1] % arr[i];
			val[i] = remind[i+1] / arr[i];
		}
		else{
			remind[i] = remind[i+1];
			val[i] = 0;
		}
	}

	int sum=0;

	for (int i = 0; i < n; ++i)
	{
		sum = sum + val[i]*arr[i];
	}

	cout<<"\nAmount: "<<amount<<endl;

	if (sum!=amount)
	{
		cout<<"Not Solved !"<<endl;
	}
	else{
		cout<<"Solved !"<<endl;
		result=1;
	}
	
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<":"<<val[i]<<" "<<endl;
	}

	return result;
}

void allDistinct(int arr[],int n,int maxDenom,int minDenom){

	

	generate:for (int i = 0; i < n; ++i)
	{
		arr[i] = rand()%(maxDenom +1 -minDenom) + minDenom;		
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j){
			if (arr[i]==arr[j])
			{

				goto generate;
			}	
		}
	}
	

}
