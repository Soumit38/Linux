//#include<istdio>
#include<iostream>
using namespace std;

int main()
{
int n,i,arr[10],bur[10],pri[10],wait[10],a=0,total=0;
wait[0]=0;
cout<<"Enter the number of process:"<<endl;
cin>>n;
cout<<"Enter the burst time:"<<endl;
for(i=0;i<n;i++)
{
    cin>>bur[i];
}
cout<<"The sequence for fcfs is:"<<endl;
for(i=0;i<n;i++)
{
    cout<<"P"<<i<<endl;
}
//cout<<"The waiting time is:"<<endl;
for(i=1;i<n;i++)
{
   wait[i]=wait[i-1]+bur[i-1];
}
for(i=0;i<n;i++)
{
    cout<<endl<<"P"<<i<<"'s waiting time is:"<<wait[i]<<endl;
}

cout<<"Average waiting time:"<<endl;


for(i=0;i<n;i++)
{

    a=a+wait[i];
}
cout<<a/n;
return 0;
}
