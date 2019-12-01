#include <iostream>
using namespace std;
#define SIZE 1000
main()
{
        int n,i,a[SIZE];
        int k[SIZE];
        int b[SIZE];
        cout<<"Enter the number of elements : ";
        cin>>n;
        for (i=1;i<=n;i++)
        {
                cin>>a[i];
        }
        int max = a[1];
   
        for (i = 2; i <= n; i++){
        if (a[i] > max)
            max = a[i];
         }
        for(i=0;i<max+1;i++)
        {
                b[i]=0;
        }
        for (i=1;i<=n;i++)
        {
             b[a[i]]=b[a[i]]+1;    
        }
        for(i=0;i<max+1;i++)
        {
                b[i+1]=b[i]+b[i+1];
        }
        for(i=1;i<=n;i++)
        {
                k[b[a[i]]]=a[i];
                b[a[i]]=b[a[i]]-1;
                
        }
         cout<< "The sorted array is "<< " " ;
        for(i=1;i<=n;i++)
        {
                cout << k[i] << " "; 
        }
        
}
