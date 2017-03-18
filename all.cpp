#include <iostream>
#include <cstdlib>
#include <ctime>

#include "quicksort.cpp" // reused code written by us in lab sessions

using namespace std;


#define SAMPLES 20      /* number of test samples */
#define MAX_DENOM 6     /* max value of any denomination */
#define MIN_DENOM 2     /* min value of any denomination */
#define MAX_DENOM_NUM 4 /* max number of denominations */
#define MIN_DENOM_NUM 2 /* min number of denominations */
#define MAX_AMOUNT 50   /* max value of any sample */


int findMin(int V, int denomination[], int size);

int solve(int amount, int denomination[], int size);

int findValue(int arr[],int n,int amount);

void allDistinct(int arr[],int n,int maxDenom,int minDenom);

int opt(int amount,int arr[], int n);

int findMin(int arr[],int n);


int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int n,
		g1success=0,
		dpsuccess=0,
		g2success=0,
		maxDenom = MAX_DENOM,
		minDenom = MIN_DENOM,
		mindenomNum = MIN_DENOM_NUM,
		maxdenomNum = MAX_DENOM_NUM;
	

	n = rand() % (maxdenomNum +1 -mindenomNum) + mindenomNum;

	int arr[n];

	allDistinct(arr,n,maxDenom,minDenom); // check of randomly generated denominations are distinct

	quicksort(arr,0,n-1);   // sort the array of denominations

	int amount,g1result,dpresult,g2result;

	int samples = SAMPLES;


	cout<<"Denominations: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}

	cout<<endl<<endl;
	cout<<"Key : if amount is 0 , then there is no answer."<<endl<<endl;
	cout<<"Amount\t"<<"Greedy 1\t"<<"Greedy 2\t"<<"Dynmc Prgming\t"<<"Optimal\t"<<endl;

	for (int i = 0; i < samples; ++i)
	{
		amount = rand()%MAX_AMOUNT;

		g1result = findValue(arr,n,amount);

		g2result = solve(amount,arr,n);

		dpresult = opt(amount,arr,n);

		if (g1result == -1)
		{
			g1result = 0;
		}
		if (g2result == -1)
		{
			g2result = 0;
		}
		if (dpresult >= 2147483600 || dpresult<=0)
		{
			dpresult =0;
		}

		cout<<amount<<"\t"<<g1result<<"\t\t"<<g2result<<"\t\t"<<dpresult<<"\t\t"<<dpresult<<endl;

		if( g1result != 0){
			g1success++;

		}
		if( g2result != 0){
			g2success++;

		}
		if( dpresult != 0){
			dpsuccess++;
			
		}
	}

	cout<<endl<<"Success rate of greedy 1 : "<<g1success<<"/"<<samples<<endl;
	cout<<"Success rate of greedy 2 : "<<g2success<<"/"<<samples<<endl;
	cout<<"Success rate of Dynmc Prgming : "<<dpsuccess<<"/"<<samples<<endl;

	return 0;
}


int findValue(int arr[],int n,int amount)
{


	int remind[n+1],val[n+1],result=-1;

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

	int sum=0,count=0;

	for (int i = 0; i < n; ++i)
	{
		sum = sum + val[i]*arr[i];
		count = count + val[i];
	}



	if (sum==amount)
	{
		result = count;
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

int opt(int amount,int arr[], int n){

	int tempArray[n];

	if (amount == 0 )
	{
		return 0;
	}
	else if (amount < arr[0] || amount < 0 )
	{
		// BIGGEST POSSIBLE VALUE 
		// so that x is not selected

		return 2147483600;
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
		if (min>=arr[i])
		{
			min = arr[i];
		}
	}

	return min;
}


int solve(int amount, int denomination[], int size)
{
	int i;
	if(amount==0)
 		return -1;

	for( i=size-1;i>=0;--i)
 	{
    	if(amount%denomination[i]==0)
		{
			return (amount/denomination[i]);
		}
	}
	
	if(i==0)
		return findMin(amount,denomination,size);
	else{
		return -1;
	}
}

int findMin(int V, int denomination[], int size)
{

	int ans[50];
	int l=0;
	int count=0;
	int sum=0;
	int v=V;
	int k;

    for (int i =size-1;i>=0 ; i--)
    {
        while (V >= denomination[i])
        {
        	
         V -= denomination[i];
         count++;
         ans[k]=denomination[i];
         l++;
    	 sum+=denomination[i];
 	 	}
  	}

  	if(v==sum)
	{
		return count;
	}
	else
 		return -1;
}