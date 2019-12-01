#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "linkedlist.h"
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
using namespace std;
class Stack
{
    LinkedList ll;
public:
    Stack()
    {

    }
    void push(int item)
    {
        //write your codes here
        ll.insertItem(item);
        cout<<"The item recently pushed is ";
        cout<< item<<endl;
    }
    int pop()
    {
        int p;
        p=ll.deleteFirst();
        if(p==NULL_VALUE)
        {
            cout<<"The stack is empty" <<endl;
            return 0;
        }

        cout<< "The popped item is "<< p <<endl;
    }
        void printStack()
    {
        ll.printList();
    }
};

int main(void)
{
    Stack st;

    while(1)
    {
        printf("1. Push. 2. Pop. 3. Exit. 4. Print\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            cout<<"Enter an item to push ";
            scanf("%d", &item);
            st.push(item);
        }
        else if(ch==2)
        {

            st.pop();
        }
        else if(ch==4)
        {
            st.printStack();
        }
        else if(ch==3)
        {
            break;
        }
    }

}
