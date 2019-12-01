

#include<iostream>

using namespace std;

#define Null 9999
int p;
class coord{
	public:
    int x_coord;
    int y_coord;
};



 coord *xy_coord;




void merged( coord *t,int l,int m,int r);

void mergeSort( coord *t,int l,int r);

void skylineSort( coord *t,int l,int r);

void mergeSkylinesort( coord *t,int l,int m,int r);

int main(){

    int p,j;
    while(1){
	
    cin>>p;
    xy_coord = new coord[p];
	int co_x[p];
	int co_y[p];
   for(int i=0;i<p;i++){
       cin>>co_x[i];
       cin>>co_y[i];
}    for(j=0;j<p;j++){
	 
     xy_coord[j].x_coord = co_x[j];
       xy_coord[j].y_coord = co_y[j];
   }

  



    mergeSort(xy_coord,0,p-1);
    skylineSort(xy_coord,0,p-1);

    cout<<"\nSKYLINE COORD:\n"<<endl;

    for( j=0;j<p;j++){
        if(xy_coord[j].x_coord != Null && xy_coord[j].y_coord != Null){

            cout<<xy_coord[j].x_coord<<", "<<xy_coord[j].y_coord<<endl;


    }

    } 
    cout<<"----------------------"<<endl;


}
    return 0;


}

void mergeSort( coord *temp,int l,int r){

    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(temp,l,m);
        mergeSort(temp,m+1,r);

        merged(temp,l,m,r);

    }

}


void merged( coord *arr,int l,int m,int r){
    int i,j,k;

    int n1 = m-l+1;
    int n2 = r-m;

     coord *L;

     coord *R;

    L = new  coord[n1];
    R = new  coord[n2];

    for(i=0;i<n1;i++){

        L[i].x_coord = arr[l+i].x_coord;
        L[i].y_coord = arr[l+i].y_coord;
    }

    for(j=0;j<n2;j++){

        R[j].x_coord = arr[m+1+j].x_coord;
        R[j].y_coord = arr[m+1+j].y_coord;
    }

    i=0;
    j=0;
    k=l;



    while(i<n1 && j<n2){
           if(L[i].x_coord<R[j].x_coord){

               arr[k].x_coord = L[i].x_coord;
               arr[k].y_coord = L[i].y_coord;
               i++;

           }
           else if(L[i].x_coord>R[j].x_coord){

               arr[k].x_coord = R[j].x_coord;
               arr[k].y_coord = R[j].y_coord;
               j++;

           }
           else if(L[i].x_coord==R[j].x_coord){

               if(L[i].y_coord>=R[j].y_coord){
                   arr[k].x_coord = L[i].x_coord;
                   arr[k].y_coord = L[i].y_coord;
                   i++;
               }
               else{
                   arr[k].x_coord = R[j].x_coord;
                   arr[k].y_coord = R[j].y_coord;
                   j++;
               }

           }

           k++;


    }

    while(i<n1){
        arr[k].x_coord = L[i].x_coord;
        arr[k].y_coord = L[i].y_coord;
        i++;
        k++;
    }

    while(j<n2){
        arr[k].x_coord = R[j].x_coord;
        arr[k].y_coord = R[j].y_coord;
        j++;
        k++;
    }
		p=k;
		
}


void skylineSort( coord *temp,int l,int r){

    if(l<r){
        int m = l+(r-l)/2;
        skylineSort(temp,l,m);
        skylineSort(temp,m+1,r);

        mergeSkylinesort(temp,l,m,r);

    }
    return;

}

void mergeSkylinesort( coord *arr,int l,int m,int r){
     int i,j,k;

    

    int n1 = m-l+1;
    int n2 = r-m;

     coord *L;

     coord *R;

    L = new  coord[n1];
    R = new  coord[n2];

  

    for(i=0;i<n1;i++){

        L[i].x_coord = arr[l+i].x_coord;
        L[i].y_coord = arr[l+i].y_coord;
    }

    for(j=0;j<n2;j++){

        R[j].x_coord = arr[m+1+j].x_coord;
        R[j].y_coord = arr[m+1+j].y_coord;
    }

    i=0;
    j=0;
    k=l;



    while(i<n1){

      if(L[i].x_coord==R[j].x_coord){

            if(L[i].y_coord>=R[j].y_coord){

                L[i].x_coord = Null;
                L[i].y_coord = Null;
                i++;
            }
            else{

                i++;
            }
        }

        else  if(L[i].y_coord<=R[j].y_coord){
            R[j].x_coord = Null;
            R[j].y_coord = Null;
            j++;
        }
        else{

            i++;
        }

    }

     for(i=0;i<n1;i++){

        arr[l+i].x_coord = L[i].x_coord;
        arr[l+i].y_coord = L[i].y_coord;
    }

    for(j=0;j<n2;j++){

        arr[m+1+j].x_coord = R[j].x_coord;
        arr[m+1+j].y_coord = R[j].y_coord;
    }





}
