#include<stdio.h>
#include<stdlib.h>
#include "linkedlistwithtail.h"
#include <iostream>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
using namespace std;

class Queue
{
    LinkedListWithTail ll;
public:
    Queue()
    {

    }

    int enqueue(int item)
    {
        int x=ll.insertItem(item);
        return x;
        
    }

    int dequeue()
    {
       //write your codes here
       int p=ll.deleteLast();
    	return p;
    }
         void printQueue()
    {
        ll.printList();
    }
};

int main()
{
    Queue qu;

    while(1)
    {
        printf("1. Enque. 2. Deque. 3. Print 4. Exit. \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item,x;
            cout<<"Enter an item to enqueue ";
            scanf("%d", &item);
            x=qu.enqueue(item);
            cout<<"\n";
            cout<<"The first enqued item is " << x <<endl;
        }
        else if(ch==2)
        {
            int item=qu.dequeue();
            if(item==NULL_VALUE)
            {
            	cout<<"Queue is empty" <<endl;
			}
			else{
			
            cout<<"The least recently inserted  item is ";
            printf("%d\n",item);
        }
        }
        else if(ch==3)
        {
        	qu.printQueue();
		}
        else if(ch==4)
        {
            break;
        }
    }

}

