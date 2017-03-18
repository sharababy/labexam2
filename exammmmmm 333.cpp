#define MAX_POINT 2
#define ARR_SIZE 100
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
 
/* Utility function to print array arr[] */
void printArray(int arr[], int arr_size, int d[3]);
 
/* The function prints all combinations of numbers 1, 2, ...MAX_POINT
   that sum up to n.
   i is used in recursion keep track of index in arr[] where next
   element is to be added. Initital value of i must be passed as 0 */
void printCompositions(int n, int i, int d[3])
{
 
  /* array must be static as we want to keep track
   of values stored in arr[] using current calls of
   printCompositions() in function call stack*/
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
 
/* UTILITY FUNCTIONS */
/* Utility function to print array arr[] */
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
  

   printf("count size of coin is %d\n", arr_size);
   for (i = 0; i < arr_size; i++)
  {
    printf("%d-->", arr[i]);   
    printf("\n");  
  
  }
  
  
     for(j=0;j<3;j++)
     {
	printf("count of d%d  is %d", j,count[j]);
     }
}


 
/* Driver function to test above functions */
int main()
{
  int n = 10,k=3;
  int d[k];
d[0]=1;
d[1]=2;
d[2]=3;
  printf("Differnt comons formed by different denominations  of %d are\n", n);
  printCompositions(n, 0,d);
  getchar();
  return 0;
}
