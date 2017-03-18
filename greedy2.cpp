#include<iostream>
#include<algorithm>
using namespace std;

/* Note: V is the amount in findMin function */
void findMin(int V, int denomination[], int size);
void solve(int amount, int denomination[], int size)
{
	int i;
  if(amount==0)
 		return;

for( i=size-1;i>=0;--i)
 {
    if(amount%denomination[i]==0)
   {
			cout << "Denominations are " << denomination[i] << ":" << (amount/denomination[i]) << endl;
    	break;
	}

}
	if(i==0)
		findMin(amount,denomination,size);
}

void findMin(int V, int denomination[], int size)
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
		int i=0;

      while(i<count)
			{
				cout << ans[i] << "  ";
				i++;
		}
	cout<<endl;
	cout<<count<<endl;
}
else
 	cout<<"Enter a correct denomination"<<endl;
}

int main()
{
	cout << "Enter the size of denomination array" << endl;
	int size;
	cin >> size;
	cout << "Enter the denominations" << endl;
	int denomination[size];
	for(int i=0;i<size;++i)
	{
		cin >> denomination[i];
	}
	cout << "Enter the amount" << endl;
	int amount;
	cin >> amount;
	solve(amount,denomination,size);

	return 0;
}
