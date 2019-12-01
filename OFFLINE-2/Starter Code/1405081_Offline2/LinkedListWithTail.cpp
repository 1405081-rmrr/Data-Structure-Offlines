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
        newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ; //point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
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
			cout<< "After deletion the last value is " << tail->item <<endl;
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
        ListNode *temp,*newnode;
        newnode=new ListNode();
        newnode->item=item;
        newnode->next=NULL;
        temp=tail;
        temp->next=newnode;
        tail=newnode;
        length++;
        
        
    }

    ListNode * getItemAt(int pos)
    {
         //write your codes here
        
    
         //write your codes here
         ListNode *temp;
         int count=2;
         temp=list;
         if(pos>length)
         {
         	return 0;
		 }
		 while(count<=pos)
		 {
		 	temp=temp->next;
		 	count++;
		 }
		 return temp;
		

    

    }

    int deleteLast()
    {
        //write your codes here
        ListNode *temp;
        temp=list;
        int count=1;
        if(length==0)
        {
        	cout<<"Wrong!!"<<endl;
        	return 0;
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
		tail=temp;
		tail->next=NULL;
		temp=temp->next;
		delete(temp);
		length--;
		cout<<"The last item after deletion is " << tail->item <<endl;
		
    }
};

int main(void)
{
    LinkedListWithTail ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("5. Print. 6. exit. 7. DeleteLast 8.InsertLast 9.Get the position \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            cout<<"Insert an item ";
            scanf("%d", &item);
            ll.insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            cout<<"Enter the item ";
            scanf("%d", &item);
            int x=ll.deleteItem(item);
            if(x==NULL_VALUE)
            {
            	cout<<"Item not found !!" <<endl;
			}
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
        else if(ch==5)
        {
            ll.printList();
        }
        else if(ch==8)
        {
        	int item;
        	cout<<"Enter an item ";
        	cin>>item;
			ll.insertLast(item);
        	
		}
		else if(ch==9)
		{
			 
        	int pos;
        	ListNode *temp;
        	cout<<"Enter the position ";
        	cin>>pos;
        	if(pos==0)
        	{
        		cout<<"Wrong Position!!" <<endl;
			}
        	else if(!(ll.getItemAt(pos)))
        	{
        		cout<<"Error!!"<<endl;
			}
			else{
        	temp=ll.getItemAt(pos);
        	cout<< "The item is " << temp->item <<endl;
        }
		
		}
        else if(ch==7)
        {
        	ll.deleteLast();
		}
        else if(ch==6)
        {
            break;
        }
    }

}
