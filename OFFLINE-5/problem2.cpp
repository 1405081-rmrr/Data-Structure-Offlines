#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define NULL_VALUE -1000
using namespace std;

int main()
{

    vector<int> intVec;
    vector<int> outVec;
    int k,in,l;
    while(1){
	cout<<"The number of customers : ";
    cin>>l;
    for(k=0;k<l;k++)
    {
		cin>>in;
		intVec.push_back(in);
		outVec.push_back(in);
	}
	
    sort(intVec.begin(), intVec.end());

    /*for (vector<int>::size_type i = 0; i != intVec.size(); ++i)
        cout << intVec[i] << " ";*/

    cout << endl;
    cout<<"The order in which customers should be serviced : ";
    for(vector<int>::size_type i=0;i!=intVec.size();i++)
    {
    	for(vector<int>::size_type j=0;j!=outVec.size();j++)
    	{
    		if(intVec[i]==outVec[j])
    		{
    			cout<< j+1 << " ";
    			outVec[j]=NULL_VALUE;
			}
		}
	}
	intVec.clear();
	outVec.clear();
	cout<<endl;

   
}
    return 0;
}
