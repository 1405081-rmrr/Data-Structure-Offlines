
#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float> &arr, int n)
{
    
    vector<float> b[10000];
 
    for (int i=0; i<n; i++)
    {
        int bi = n*arr[i]; 
        b[bi].push_back(arr[i]);
    }
 
    
    for (int i=0; i<n; i++)
        sort(b[i].begin(), b[i].end());
 
    int index = 0;
    arr.clear();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr.push_back(b[i][j]);
}
 

void sortMixed(float arr[], int n)
{
    vector<float>Neg ;
    vector<float>Pos;
 
  
    for (int i=0; i<n; i++)
    {
        if (arr[i] < 0)
 
          
            Neg.push_back (-1 * arr[i]) ;
        else
           
            Pos.push_back (arr[i]) ;
    }
 
    bucketSort(Neg, (int)Neg.size());
    bucketSort(Pos, (int)Pos.size());
 
  
    for (int i=0; i < Neg.size(); i++)
        arr[i] = -1 * Neg[ Neg.size() -1 - i];
 
   
    for(int j=Neg.size(); j < n; j++)
        arr[j] = Pos[j - Neg.size()];
}
 

int main()
{
    int n;
    cout<< "Enter the number of elements : ";
    cin>>n;
    float arr[n];
    for(int i=0;i<n;i++)
    {
            cin>> arr[i];
    }
   
    sortMixed(arr, n);
 
    cout << "Sorted array is \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
