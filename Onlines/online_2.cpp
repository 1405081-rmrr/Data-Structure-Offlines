///CSE204_16Batch
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
        ListNode *temp;
        temp=list;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            if(count==(length)) break;
            temp=temp->next;
        }
        ListNode *newNode=new ListNode();
        newNode->item=item;
        temp->next=newNode;
        newNode->next=NULL;
        length++;

    }

    int insertAfter(int oldItem, int newItem)
    {
        ListNode *temp,*temp1;
        temp1=new ListNode();
        temp=searchItem(oldItem);
        if(temp==0)
        {
        	cout<<"Old value not found" <<endl;
        	return 0;
		}
		if(temp->next==NULL)
		{
			temp1->item=newItem;
			temp1->next=NULL;
			temp->next=temp1;
			length++;
			return 0;
		}
        
			temp1->item=newItem;
        	temp1->next=temp->next;
        	temp->next=temp1;
        	length++;
        
    }
    int countItem(int i)
    {
    	ListNode *temp1,*temp;
    	int count=0;
    	temp=searchItem(i);
    	if(temp==0)
    	{
    		cout<<"Not found";
    		return 0;
		}
		temp1=list;
		while(temp1!=NULL)
		{
			if((temp1->item)==i)
			{
				count++;
			}
			temp1=temp1->next;
			if(temp1==NULL) break;
		}
		//return count;
		cout<<count<<endl;
    	
	}

    ListNode * getItemAt(int pos)
    {
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
       length=0;
       list=0;
       delete [] list;
    }

};

int main(void)
{
    LinkedList ll;

    while(1)
    {
        printf("1. Insert new item At the beginning . 2. Delete item. 3. Search item. \n");
        printf("4. InsertLast. 5. Print. 6. exit 7.DeleteFirst 8. InsertAfter 9. GetPosition 10.CountItem \n");

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
            cout<<"Enter an item to delete ";
            scanf("%d", &item);
            ll.deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            cout<<"Enter the item ";
            scanf("%d", &item);
            ListNode * res = ll.searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==10)
        {
        	int item;
        	cout<<"Enter an item ";
        	cin>>item;
			//int x=ll.countItem(item);
			ll.countItem(item);
			//cout<<x<<endl;
        	
		}
        else if(ch==7)
        {
            ll.deleteFirst();
        }
        else if(ch==4)
        {
            int item;
            cout<<"Insert an item ";
            cin>>item;
            ll.insertLast(item);
        }
        else if(ch==8)
        {
        	int old,new1;
			cout<< "Inter the old item ";
        	cin>>old;
        	cout<<"Inter the new item ";
        	cin>>new1;
        	ll.insertAfter(old,new1);
		}
        else if(ch==5)
        {
            ll.printList();
        }
        else if(ch==9)
        {
        	int pos;
        	ListNode *temp;
        	cout<<"Enter the position ";
        	cin>>pos;
        	temp=ll.getItemAt(pos);
        	 cout<< "The item is " << temp->item <<endl;
		}
        else if(ch==6)
        {
            break;
        }
    }

}
