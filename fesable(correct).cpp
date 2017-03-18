
#define ARR_SIZE 100

#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


void printArray(int arr[], int arr_size, int d[],int noof);
 

void printCompositions(int n, int i, int d[],int noof )
{
 
 
  static int arr[ARR_SIZE];
 
  if (n == 0)
  {
  	

    printArray(arr, i,d,noof);

  }
  else if(n > 0)
  {
    int m,j; 
  
    for (j = 0; j < noof; j++)
    {
    
    	m=d[j];
      arr[i]= m;
      printCompositions(n-m, i+1,d,noof);
    }
  }
}
 

void printArray(int arr[], int arr_size, int d[],int noof)
{
  int i,j;
  int count[noof];
  for(j=0;j<noof;j++)
  {
  	count[j]=0;
  }
  
  
  int sum=0;
  int k=0;
    for(j=0;j<noof;j++)
    {
  	 for(i=0;i<arr_size;i++)
  	 {
            if(d[j]==arr[i])
           {
    	 count[j]=count[j]+1;
              
}
     }
     }
       
  for(k=1;k<arr_size;k++)  
  {
    if(arr[k-1]>arr[k])
       {
   break; 
                  } 
      } 
  
if(k==arr_size)
{
cout<<"no of coin is " << arr_size << endl;
   for(i=0;i<arr_size;i++)
  {
	if(count[j])
	cout << arr[i] << endl;
}
    for(j=0;j<noof;j++)
     {
     cout<<"no  of"<< " " << d[j] << "'s:" <<  count[j] << endl;
     }

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
  int n ,k;
  cin>>n;
 cin>>k;
   
  int d[k];


  for(int i=0;i<k;++i)
  cin>>d[i];
  
  cout<<"Differnt comons formed by different denominations  of "<< n <<" are"<< endl;
  printCompositions(n, 0,d,k);
  cout << "no of feasible solutions" << count(d,k,n) << endl;
 
  return 0;
}

