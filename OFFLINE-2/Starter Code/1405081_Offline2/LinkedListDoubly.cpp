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
    ListNode * prev;
};


class LinkedListDoubly
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListDoubly()
    {
        list = 0;  //initially set to NULL
        tail = 0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    int insertFirst(int item) //insert at the beginning
    {
        ListNode * newNode,*temp ;
        newNode = new ListNode() ;
        newNode->item = item ;

        if(list==0) //inserting the first item
        {
            newNode->next = 0;
            newNode->prev = 0;
            list = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = list;
            list->prev = newNode;
            newNode->prev = 0;
            list = newNode;
        }
        length++;
        temp=list;
        int count=1;
        if(length==1)
        {
        	cout<<"The tail value is " << temp->item <<endl;
		}
        if(length>1)
        {

        	while(count<length)
        	{
        		temp= temp->next;
        		count++;
			}
			tail=temp;
			cout<< "The tail value is " << tail->item <<endl;
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

    void printListForward()
    {
        ListNode * temp;
        temp = list;
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("\n");
        cout<< "The Length is "<< getLength() <<endl;
    }

    //------------write code for the functions below-----------
    int insertLast(int item)
    {
        //write your codes here
        ListNode *temp,*newnode;
        newnode=new ListNode();
        newnode->item=item;
        newnode->next=NULL;
        temp=tail;
        temp->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        length++;

    }

    int deleteLast()
    {
        //write your codes here
        ListNode *temp;
        //temp=list;
        int count=1;
        if(count==length)
        {
        	list=0;
        	length=0;
        	tail=0;
        	return NULL_VALUE;
		}
		temp=tail->prev;
		int x = tail->item;
		temp->next=NULL;
		tail=temp;
		length--;
		//cout<<"The last item after deletion is " << tail->item <<endl;
		return x;
		

        //return NULL_VALUE;
    }

    void printListBackward()
    {
        //will print the list backward starting from the tail position
        ListNode *temp;
        temp=tail;
        while(temp->prev!=0)
        {
        	printf("%d->", temp->item);
        	temp=temp->prev;
		}
		if(temp->prev==0) printf("%d->",temp->item);
			cout<<"\n";
			cout<< "The Length is "<< getLength() <<endl;
    }

};

int main(void)
{
    LinkedListDoubly ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Print forward. 5. Print backward. 6. exit. 7. InsertLast\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            cout<<"Insert an item ";
            scanf("%d", &item);
            ll.insertFirst(item);
        }
        else if(ch==2)
        {
            int item = ll.deleteLast();
            if(item!=NULL_VALUE) printf("Deleted: %d\n", item);
        }
        else if(ch==3)
        {
            int item;
            cout<<"Enter an item to search ";
            scanf("%d", &item);
            ListNode * res = ll.searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            ll.printListForward();
        }
        else if(ch==7)
        {
        	int x;
        	cout<<"Insert an item ";
        	cin>>x;
        	ll.insertLast(x);
		}
        else if(ch==5)
        {
            ll.printListBackward();
        }
        else if(ch==6)
        {
            break;
        }
    }

}
