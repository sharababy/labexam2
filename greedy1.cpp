#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int findValue(int arr[],int n,int amount);


int main(int argc, char const *argv[])
{
	int n,success=0;
	
	srand(time(NULL));


	int arr[n];

	cout<<"Enter all denominations:"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<"D"<<i+1<<": ";
		cin>>arr[i];
	}

	int amount;


	/*cout<<"Enter amount : ";
	cin>>amount;
*/

	int samples = 100;

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