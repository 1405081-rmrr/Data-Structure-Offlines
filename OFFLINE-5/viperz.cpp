#include<iostream>

#include<cstdlib>

using namespace std;


struct node{
    int value;
    node *next;
    int attribute;
};


int arr_length;

int *arr_elements;

node  *add_node(node *temporary,int x){
    node *q;




    q = (node *)malloc(sizeof(node *));

    q->value = x;
    q->next = temporary;
   // delete temporary;
    temporary = q;


    return temporary;




}

node *add_last(node *temporary,int x){
    node *q;
    q = (node *)malloc(sizeof(node *));

    node *q1;

    q1 = (node *)malloc(sizeof(node *));
    q1->value = x;
    q1->attribute = 0;
    q1->next = NULL;

    q = temporary;

    while(q->next){
        q = q->next;
    }
    q->next = q1;

    return temporary;


}

node *add_last_smaller(node *temporary,int x){
    node *q;
    q = (node *)malloc(sizeof(node *));

    node *q1;

    q1 = (node *)malloc(sizeof(node *));
    q1->value = x;
    q1->attribute = 1;
    q1->next = NULL;

    q = temporary;

    while(q->next){
        q = q->next;
    }
    q->next = q1;

    return temporary;


}



int position_arr(node *temporary[],int element,int start,int length){
    int i;

    int position=9999;
    for(i=start;i<length;i++){
        node *temp;
        temp = (node *)malloc(sizeof(node *));
        temp = temporary[i];
        while(temp){
            if(element == temp->value){
                position = i;
                break;
            }
            temp = temp->next;
        }
        //delete temp;

        if(position!=9999){
            break;
        }
    }

    return position;

}





class priority{
    public:
    int smallest_element(int *temp,int temp_length){

        int val_min = 99999;
        for(int i=0;i<temp_length;i++){

            if(temp[i]<val_min){
                val_min = temp[i];
            }
        }
        return val_min;
    }

    int second_smallest(int *temp,int temp_length){
        int value = smallest_element(temp,temp_length);

        int i;

        int second_value = 99999;

        for(i=0;i<temp_length;i++){
            if(second_value>temp[i] && temp[i]!=value){
                second_value = temp[i];

            }

        }

        return second_value;

    }

    void nullifypos(int *temp,int value,int temp_length){
        int i;

        for(i=0;i<temp_length;i++){
            if(temp[i]==value){

                temp[i] = temp[temp_length-1];
                temp_length--;
                break;
            }

        }
        arr_length = temp_length;

    }

    void replace_value(int *temp,int old_value,int new_value,int temp_length){

        int i;

        for(i=0;i<temp_length;i++){
            if(temp[i]==old_value){

                temp[i] = new_value;
                break;
            }

        }

    }


};


void arr_changer(int arr[],int length){
    //int length = sizeof(arr)/sizeof(arr[0]);

    cout<<"  <-->  ";

    for(int i = length-1;i>=0;i--){
        cout<<arr[i]<<" ";

    }

    cout<<endl;



}

int main(){

    int temp_arr[] = {5,9,12,13,16,45};

    int temp_arr2[] = {5,9,12,13,16,45};

    arr_elements = temp_arr;

    int sized = sizeof(temp_arr)/sizeof(temp_arr[0]);

    arr_length = sized;

    priority pq ;

    int smaller_element;
    int smallest_element;

    cout<<"total size:"<<sized<<endl;
    node *temporary[sized];

    //node *temporary;

    for(int i=0;i<sized;i++){

        temporary[i] = (node *)malloc(sizeof(node *));
    }


    for(int j=0;j<sized;j++){
        temporary[j]->value = temp_arr[j];

        temporary[j]->next = NULL;
    }

    int position_i;
    int position_j;
    int z;

    int after_that;

  while(arr_length>1){
        smaller_element = pq.second_smallest(arr_elements,arr_length);
        smallest_element = pq.smallest_element(arr_elements,arr_length);



        z = (smaller_element+smallest_element);


        position_j =0;

        while(position_j<sized){

            position_j = position_arr(temporary,smallest_element,position_j,sized);

            if(position_j<sized && position_j != 9999){

                temporary[position_j] = add_last(temporary[position_j],z);
            }
            position_j++;

        }


        position_i =0;

        while(position_i<sized){

            position_i = position_arr(temporary,smaller_element,position_i,sized);

            if(position_i<sized && position_i != 9999){

                temporary[position_i] = add_last_smaller(temporary[position_i],z);
            }
            position_i++;
        }



        pq.nullifypos(arr_elements,smallest_element,arr_length);
        pq.replace_value(arr_elements,smaller_element,z,arr_length);




    }




    for(int k=0;k<sized;k++){


      node *sucker;
      sucker = (node *)malloc(sizeof(node *));
      sucker = temporary[k];

      while(sucker){
        cout<<sucker->value<<" ";
        sucker = sucker->next;
     }

     cout<<endl;


    }

    cout<<"nodes'pointer:"<<endl;

     for(int k=0;k<sized;k++){


      node *sucker1;
      sucker1 = (node *)malloc(sizeof(node *));
      sucker1 = temporary[k];

      int final_arr[sized];
      int final_i = 0;

      cout<<temp_arr2[k]<<"---->> ";

      while(sucker1->next){
       // cout<<sucker1->next->attribute<<" ";

        final_arr[final_i] = sucker1->next->attribute;
        final_i++;
        sucker1 = sucker1->next;
     }


      arr_changer(final_arr,final_i);

     cout<<endl;



    }




     cout<<endl;



    return 0;
}

