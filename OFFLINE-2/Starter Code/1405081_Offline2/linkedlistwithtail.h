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

class LinkedListWithTail
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListWithTail()
    {
        list = 0;  //initially set to NULL
        tail = 0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    //add required codes to set up tail pointer
    int insertItem(int item) //insert at the beginning
    {
        ListNode * newNode ,*temp;
        int p;
        newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ; //point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
        length++;
        temp=list;
        int count=1;
        if(length>1)
        {

        	while(count<length)
        	{
        		temp= temp->next;
        		count++;
			}
			tail=temp;
			p=tail->item;
			return p;
			//cout<< "The tail value is " << tail->item <<endl;
		}
		if(length==1)
		{
			p=temp->item;
			return p;
		}
        
    }

    //add required codes to set up tail pointer
    int deleteItem(int item)
    {
        ListNode *temp, *prev,*temp1 ;
        temp = list ; //start at the beginning
        int count=1;
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
            delete temp ;
            length--;
        }
        else
        {
            prev->next = temp->next ;
            delete temp;
            length--;
        }
        temp1=list;
         if(length>1)
        {

        	while(count<length)
        	{
        		temp1= temp1->next;
        		count++;
			}
			tail=temp1;
			cout<< "The value is " << tail->item <<endl;
		}
        return SUCCESS_VALUE ;
    }

    //add required codes to set up tail pointer
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
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("\n");
        printf("Length: %d\n",getLength());
    }

    //------------write code for the functions below-----------
    int insertLast(int item)
    {
        //write your codes here
    }

    ListNode * getItemAt(int pos)
    {
         //write your codes here

    }

    int deleteLast()
    {
        //write your codes here
        ListNode *temp;
        temp=list;
        int count=1;
        if(length==0)
        {
        	return NULL_VALUE;
		}
        if(count==length)
        {
        	list=0;
        	length=0;
        	tail=0;
        	return SUCCESS_VALUE;
		}
        while(count<length-1)
        {
        	temp=temp->next;
        	count++;
		}
		//tail=temp;
		//tail->next=NULL;
		temp->next=NULL;
		//temp=temp->next;
		//int x=tail->item;
		//delete(temp);
		int x=tail->item;
		tail=temp;
		length--;
		return x;
		
		//cout<<" After DeQueue the last item  is " << tail->item <<endl;
		
    }
};


