#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int huffman(int n,int f[100])
{
	priority_queue <int, vector<int> ,greater<int> > p;
	for(int i=0;i<n;i++)
	{
		p.push(f[i]);
	}
	while(p.size()!=1)
	{
		int a=p.top();
		//p.pop();
		p.pop();
		int b=p.top();
		p.pop();
		p.push(a+b);
	}
	return p.top();
	
}
int main()
{
	int a[6];
	for(int i=0;i<6;i++)
	{
		cin>>a[i];
	}
	int n=6;
	int x=huffman(n,a);
	cout<<x;
}
