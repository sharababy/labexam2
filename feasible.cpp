
#define ARR_SIZE 100

#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;



void printArray(int arr[], int arr_size, int d[3]);
 

void printCompositions(int n, int i, int d[3])
{
 
 
  static int arr[ARR_SIZE];
 
  if (n == 0)
  {
  	

    printArray(arr, i,d);

  }
  else if(n > 0)
  {
    int m,j; 
  
    for (j = 0; j < 3; j++)
    {
    
    	m=d[j];
      arr[i]= m;
      printCompositions(n-m, i+1,d);
    }
  }
}
 

void printArray(int arr[], int arr_size, int d[3])
{
  int i,j;
  int count[3];
  for(j=0;j<3;j++)
  {
  	count[j]=0;
  }
  
  
  
    for(j=0;j<3;j++)
    {
  	for(i=0;i<arr_size;i++)
  	{
    if(d[j]==arr[i])
    {
    	count[j]=count[j]+1;
	}
    }
    }
  

    cout<<"no of coin is " << arr_size << endl;
for(i=0;i<arr_size;i++)
{
	if(count[j])
	cout << arr[i] << endl;
}
     for(j=0;j<3;j++)
     {
     cout<<"count of "<< " " << d[j] << "-->" <<  count[j] << endl;
     }
}

int count( int S[], int m, int n )
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (m <=0 && n >= 1)
        return 0;
 
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}

int main()
{
  int n = 4,k=3;
  int d[k];
d[0]=1;
d[1]=2;
d[2]=3;
  cout<<"Differnt comons formed by different denominations  of %d are"<< n << endl;
  printCompositions(n, 0,d);
  cout << "no of feasible solutions" << count(d,3,4) << endl;
  getchar();
  return 0;
}

