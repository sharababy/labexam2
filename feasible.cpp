#define MAX_POINT 2
#define ARR_SIZE 100

#include<time.h>
#include<stdlib.h>
 #include<iostream>
 using namespace std;

void printArray(int arr[], int arr_size, int d[3]);
 

void printCompositions(int n, int i, int d[3])
{
 
 
  static int arr[ARR_SIZE];
 int c=0;
  if (n == 0)
  {
  	c=c+1;
  	cout <<"c is" << c <<endl;
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
  

    cout<<"coummmnt of coin is " << arr_size << endl;
   for (i = 0; i < arr_size; i++)
    {
            cout << arr[i] << endl; 
    }
  
  
     for(j=0;j<3;j++)
     {
     cout<<"count of d"<< j << "-->" <<  count[j] << endl;
     }
}



int main()
{
  int n = 10,k=3;
  int d[k];
d[0]=1;
d[1]=2;
d[2]=3;
  cout<<"Differnt comons formed by different denominations  of %d are"<< n << endl;
  printCompositions(n, 0,d);
  getchar();
  return 0;
}

