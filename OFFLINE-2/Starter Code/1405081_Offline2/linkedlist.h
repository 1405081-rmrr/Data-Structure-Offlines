#include<stdio.h>
#include<stdlib.h>
#include <iostream>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
 using namespace std;
class ListNode
{
public:
    int item;
    ListNode * next;
};

class LinkedList
{

    ListNode * list;
    int length;

public:
    LinkedList()
    {
        list=0; //initially set to NULL
        length=0;
    }

    int getLength()
    {
        return length;
    }

    int insertItem(int item) //insert at the beginning
    {
        ListNode * newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ; //point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
        length++;
        return SUCCESS_VALUE ;
    }

    int deleteItem(int item)
    {
        ListNode *temp, *prev ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) break ;
            prev = temp;
            temp = temp->next ; //move to next node
        }
        if (temp == 0) return NULL_VALUE ; //item not found to delete
        if (temp == list) //delete the first node
        {
            list = list->next ;
            delete temp;
            length--;
        }
        else
        {
            prev->next = temp->next ;
            delete temp;
            length--;
        }
        return SUCCESS_VALUE ;
    }


    ListNode * searchItem(int item)
    {
        ListNode * temp ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) return temp ;
            temp = temp->next ; //move to next node
        }
        return 0 ; //0 means invalid pointer in C, also called NULL value in C
    }

     void printList()
    {
        ListNode * temp;
        temp = list;

         if(temp==0)
         {
             cout<<"The list is empty" << endl;
             cout<<"Length is 0" << endl;
             return ;
         }
         cout<<"The list is ";
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("\n");
        printf("Length: %d\n",length);
    }


    //------------write code for the functions below-----------

    int insertLast(int item)
    {
        //write your codes here
    }

    int insertAfter(int oldItem, int newItem)
    {
        //write your codes here
    }

    ListNode * getItemAt(int pos)
    {
         //write your codes here

    }


        //write your codes here
     int deleteFirst()
    {
        //write your codes here
        int x;
        ListNode *temp;
        temp=list;
        if(temp==NULL)
        {
            cout<<"No item Found"<<endl;
            return NULL_VALUE;
        }
        x=temp->item;
        //cout<<x<<endl;
        list=temp->next;
        //delete(temp);
        free(temp);
        length--;
        return x;

    }



    ~LinkedList()
    {
        //write your codes here
    }

};

/*int main(void)
{
    LinkedList ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. (Add from homework). 5. Print. 6. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            ll.insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            ll.deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            ListNode * res = ll.searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==5)
        {
            ll.printList();
        }
        else if(ch==6)
        {
            break;
        }
    }

}*/
