#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include <sstream>
#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
using namespace std;
int listMaxSize;
int * list;
int length;


void initializeList()
{
	listMaxSize = LIST_INIT_SIZE;
	list = (int*)malloc(sizeof(int)*listMaxSize) ;
	length = 0 ;
}

int searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}
void getLength()
{
     printf("Current Lenght : %d\n",length);
}
int insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		listMaxSize = 2 * listMaxSize ;
		tempList = new int[listMaxSize];
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ;
        }
        free(list) ;
        list = tempList ;
	};

	list[length] = newitem ;
	length++ ;
	return SUCCESS_VALUE ;
}
int insertItemAt(int pos,int item)
{
    if(pos>=length) return NULL_VALUE;
    int a = list[pos];
    list[pos] = item;
    insertItem(a);
}

int deleteItemAt(int position)
{
	if ( position >= length ) return NULL_VALUE;
	list[position] = list[length-1] ;

	length-- ;
	return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return NULL_VALUE;
	deleteItemAt(position) ;
	return SUCCESS_VALUE ;
}
int deleteLast(void)
{


    int p=list[length-1];
    length--;
    if(length==0)
    {
        initializeList();
    }

    return p;
}
int deleteAll()
{
    length=0;
}
void clearList()
{

    initializeList();
}
void printList()
{
    int i;
    for(i=0;i<length;i++){
        printf("%d ", list[i]);}
        cout<<"\n";
    printf("Current size: %d\n", listMaxSize);
    getLength();
}
int sortArray(int *a,int s)
{
   // a=new int();
    int i,j,temp;
    for(i=0;i<s;i++)
    {
        for(j=0;j<s-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
   // return a;
    for(i=0;i<s;i++)
    {
        cout<< a[i]<< " ";
    }
    cout<<endl;
}
int median(int*a,int s)
{
    float x;
    float y,z;
    if(s%2!=0)
    {
        x=a[s/2];
        //cout<<"Median is "<<x<<endl;
        printf("%f\n",x);
    }
    else
    {
       y=a[(s/2)-1];
       z=a[(s/2)];
       x=(y+z)/2;
       //cout<<"Median is "<<x<<endl;
       printf("%.2f\n",x);
    }
}
int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item at. 3. Delete item 5. Print. 6. exit. 7. Insert Item at . 8. DeleteLast 9. Clear 10. DeleteAll\n");
        cout<<"11. Sort"<<endl;
        cout<<"12. Median"<<endl;
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            cout<< "Insert a item"<<endl;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==10)
        {
            deleteAll();
        }
        else if(ch==7)
        {
           int pos,item;
           cout<<"Enter the position ";
           scanf("%d",&pos);
           cout<<"Enter the element ";
           cin>>item;
           insertItemAt(pos,item);
        }
        else if(ch==9)
        {
            clearList();
            printList();
        }
        else if(ch==8)
        {
            deleteLast();
            printList();
        }
        else if(ch==2)
        {
            int pos;
            cout<<"Enter the position ";
            scanf("%d", &pos);
            deleteItemAt(pos);
        }
        else if(ch==3)
        {
            int item;
            cout<<"Enter the item ";
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==11)
        {
            sortArray(list,length);
        }
        else if(ch==12)
        {
            sortArray(list,length);
            median(list,length);
        }
        else if(ch==6)
        {
            break;
        }
    }

}
/*int main(void)
{
    initializeList();
    string a;
    int x;
    int i=0;
    int y,z,r,result,f=1;
    while(a!="T"){
        cout<<"Input a String ";
    getline(cin, a);
    //cout<< a << endl;
    for( i=0;i<a.size();i++)
    {

        if(a[i]>=48 && a[i]<=57)
        {
            x=a[i]-'0';
            insertItem(x);
        }
        else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')
        {
            y=deleteLast();
             if(length==0)
            {
               f=0;
                break;

            }
            z=deleteLast();
            if(a[i]=='+')
            {
                r=y+z;
                insertItem(r);
            }
            else if(a[i]=='-')
            {
                r=z-y;
                insertItem(r);
            }
            else if(a[i]=='*')
            {
                r=y*z;
                insertItem(r);
            }
            else if(a[i]=='/')
            {
                   if(y==0)
                {
                    cout<<"It is undefined";
                    break;
                }
                r=z/y;
                insertItem(r);
            }
        }
    }

     if((length==2) && list[length-1]<0)
    {
        cout<<"Invalid character"<<endl;
    }
    else{
   for(i=0;i<length;i++)
   {
       cout<< list[i];
   }
    }
   if(a=="T") break;
   if(length==0 && f==0)
   {
       cout<<"Invalid"<<endl;
   }
   clearList();
   cout<<endl;
    }

}*/

