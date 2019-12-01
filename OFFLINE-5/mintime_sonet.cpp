#include<iostream>

using namespace std;

struct customer{
    int service_time;
    int index;

};
void sort_cust(struct customer *cr,int n);
int main(){





     int total_cust;
    cout<<"Enter the total customers:";
    cin>>total_cust;

    customer *cr = new customer[total_cust];

    int temp_index = 1;


    int i=0;
    int temp_time;
    while(i<total_cust){
        cin>>temp_time;
        cr[i].service_time = temp_time;
        cr[i].index = temp_index;
        i++;
        temp_index++;
    }

    sort_cust(cr,total_cust);

    for(int j=0;j<total_cust;j++){
        cout<<cr[j].index<<" ";
    }

    cout<<endl;




    return 0;


}

void sort_cust(struct customer *cr,int n){


    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(cr[j].service_time > cr[j+1].service_time){
                struct customer temp;
                temp = cr[j];
                cr[j] = cr[j+1];
                cr[j+1] = temp;

            }

        }

    }
}
