#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include "LineParser.h"
using namespace std;

void printList(vector<int> nums)
{
    for(auto num: nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;
}

void findMinCost(int N, int K, vector<int> priceList)
{
    cout<<"N = "<<N<<endl; // N is number of plants
    cout<<"K = "<<K<<endl; // K is number of friends
    cout<<"Price List = ";
    printList(priceList);

    int sum = 0;
    sort(priceList.begin(), priceList.end(), [=](int x, int y){return x>y;});
    cout<<"Sorted Price List = ";
    printList(priceList);


    for(int index=0; index<K; index++)
    {
        int i = index; // starting index of each friend no
        // friend 0 start at 0, friend 1 start at 1 and with for their cycle again

        int j = 0; // price increment factor, for each friend it is 0 in the beginning
        while(i<N) // while each friend finishes himself traversing the whole sorted priceList
        {
            sum = sum + (j + 1)*priceList[i];
            j++; // j = 0,1,2...
            i=i+K;  // if friend count K=3, then friend 0 will access i = 0,3,6 index prices
        }
    }


    cout<<"cost: "<<sum<<endl;
    cout<<endl;
}


int main()
{

    while(true)
    {

        string input;
        int N,K;

        /// parsing line 1
        fflush(stdin);
        getline(cin, input);

        LineParser<int> inputParser(input,' ');
        auto nums = inputParser.parseLineToInteger();

        N = nums[0];
        K = nums[1];

        /// parsing line 2
        fflush(stdin);
        getline(cin, input);

        LineParser<int> priceParser(input,' ');
        auto priceList = priceParser.parseLineToInteger();

        findMinCost(N, K, priceList);

    }
    return 0;
}
