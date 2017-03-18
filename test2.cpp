#include<iostream>
#include<algorithm>
using namespace std;
#define k 50
int deno[k];
int n;
void findMin(int V);
void solve(int m)
{
int i;
  if(m==0)
 return;
  
for( i=n-1;i>=0;--i)
 {
    if(m%deno[i]==0)
   {cout<<"deno's are "<<deno[i]<<":"<<(m/deno[i]);
    break;
}
 
}
if(i==0)
findMin(m);
}

void findMin(int V)
{

    int ans[50];
 int l=0;
 int count=0;
  int sum=0;
  int v=V;

    for (int i =n-1;i>=0 ; i--)
    {
        while (V >= deno[i])
        {
           V -= deno[i];
         count++;
           ans[k]=deno[i];
           l++;
    sum+=deno[i];      
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
cout<<"enter a correct denomination"<<endl;


}







int main()
{

 
 cin>>n;
for(int i=0;i<n;++i)
{

cin>>deno[i];
}

int x;
cin>>x;

 solve(x);

 


return 0;
}
