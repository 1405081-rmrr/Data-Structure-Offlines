#include <iostream>
using namespace std;
#define SIZE 100000
#define MINI 99999
//#define NULL_VAL -999
main()
{
        int n,i,a[SIZE],s;
        int k[SIZE];
        int b[SIZE];
        int c[SIZE];
        cout<<"Enter the number of elements : ";
        cin>>n;
        for (i=1;i<=n;i++)
        {
                cin>>a[i];
        }
        int max = a[1];
        int min= MINI;
        for (i = 2; i <= n; i++){
        if (a[i] > max)
            max = a[i];
         }
        for(i=1;i<=n;i++)
        {
        
                if(a[i]<min){
                min=a[i];
                }
        }
       for(i=1;i<=SIZE;i++)
       {
                k[i]=-99999;
       }
       
        if(min>=0){
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
                if(k[i]==-99999) continue;
               else 
                cout << k[i] << " "; 
        }
        
        }
        else if(min<=0)
        {
                min=min*(-1);
                for(i=0;i<max+1;i++)
                {
                
                      b[i]=0;  
                        
                }
           for (i=1;i<=n;i++)
        {
                if(a[i]>=0)
                b[a[i]]=b[a[i]]+1;    
        }
        for(i=0;i<max+1;i++)
        {
                b[i+1]=b[i]+b[i+1];
        }

        for(i=0;i<max+1;i++)
        {
                b[i]=b[i]+min;
        }
        /*for(i=0;i<max+1;i++)
        {
                cout << b[i] << " ";
        }*/
        for(i=0;i<min+1;i++)
        {
                c[i]=0;
        }
        for(i=1;i<=n;i++)
        {
                if(a[i]<0){
                s=a[i];
                s=s*(-1);
                c[s]=c[s]+1;
                }
                
        }
         for(i=min;i>=0;i--)
        {
                c[i]=c[i]+c[i+1];
        }
        /*for(i=0;i<min+1;i++)
        {
                cout<< c[i] << " ";
        }*/
            for(i=1;i<=n;i++)
        {
                if(a[i]>=0){
                k[b[a[i]]]=a[i];
                b[a[i]]=b[a[i]]-1;
               }
                if(a[i]<0)
               {
                 s=a[i];
                 s=s*(-1);
                 k[c[s]]=a[i];
                c[s]=c[s]-1;     
               }
                
        }
         cout<< "The sorted array is "<< " " ;
         for(i=1;i<=(max+min);i++)
        {
                if(k[i]==-99999) continue;
               else 
                cout << k[i] << " "; 
        }
        }
        
        
}
