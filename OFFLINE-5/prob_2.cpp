#include<bits/stdc++.h>
using namespace std;
 

struct Waitime
{
    int service, customer;
};

bool compareWaitime(Waitime i1, Waitime i2)
{
    return (i1.service < i2.service);
}
 
int main()
{

    int n,p;
    while(1){
    cout<<"Input the number of customers : ";
    cin>>n;
    if(n==0) break;
    int i;
    Waitime arr[n];
   // arr = new  Waitime();
    for(i=0;i<n;i++)
    {
    	cin>>p;
    	arr[i].service=p;
    	arr[i].customer=i+1;
	}

    sort(arr, arr+n, compareWaitime);
 
    cout << "The order in which customers should be serviced  : \n";
   
    for(i=0;i<n;i++)
    {
    	cout<< (arr[i].customer) <<" ";
	}
	cout<<endl;
}
    return 0;
}
