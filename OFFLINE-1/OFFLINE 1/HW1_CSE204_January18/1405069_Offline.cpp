#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <string.h>
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
	//list=new int(listMaxSize);
	length = 0 ;
}
void getLength()
{
     printf("Current Lenght : %d\n",length);
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

int insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		//tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		tempList = (int*) malloc (sizeof(int)*listMaxSize) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	}

	list[length] = newitem ; //store new item
	length++ ;
	return SUCCESS_VALUE ;
}
int insertItemAt(int p,int item)
{
    if(p>=length) return NULL_VALUE;
    int a = list[p];
    list[p] = item;
    insertItem(a);
}

int deleteItemAt(int position) //version 2, do not preserve order of items
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
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d\n", listMaxSize);
    getLength();
}

/*int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item at. 3. Delete item. 4. Print. 5. Insert item At. 6. Exit 7. DeleteAll 8. ClearList\n");
        cout<<"9. Deletelast"<<endl;

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int pos;
            scanf("%d", &pos);
            deleteItemAt(pos);
        }
        else if(ch==8)
        {
            clearList();
            printList();
        }
        else if(ch==9)
        {
            deleteLast();
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==4)
        {
            printList();
        }
        else if(ch==5)
        {
            int pos,item;
            cout<<"Enter the position ";
            cin>>pos;
            cout<<"Enter the item ";
            cin>>item;
            insertItemAt(pos,item);
        }
        else if(ch==7)
        {
            deleteAll();
            printList();
        }
        else if(ch==6)
        {
            break;
        }
    }

}*/
int main(void)
{
    initializeList();
    char *a;
    a=new char();
   int last,d=1,f,secondlast,temres,res,x,i,l;
  while(1){
        cout<<"Input a String ";
    gets(a);
    l=strlen(a);
    for( i=0;i<l;i++)
    {

        if(a[i]>=48 && a[i]<=57)
        {
            x=a[i]-'0';
            insertItem(x);
        }
        else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')
        {
            last=deleteLast();
            if(length==0)
            {
                break;
            }
            secondlast=deleteLast();
            if(a[i]=='+')
            {
                temres=last+secondlast;
                insertItem(temres);
            }
            else if(a[i]=='-')
            {
                temres=secondlast-last;
                insertItem(temres);
            }
            else if(a[i]=='*')
            {
                temres=last*secondlast;
                insertItem(temres);
            }
            else if(a[i]=='/')
            {
                if(last==0)
                {
                    cout<<"It is undefined";
                    break;
                }
                else
                {

                temres=secondlast/last;
                insertItem(temres);
                }
            }
        }
    }
    if(length>1)
    {
        for(i=0;i<length;i++)
        {
            if(list[i]<0)
            {
                cout<<" Invalid " <<endl;
                d=0;
                break;
            }
        }
    }
    if(d==1){
   for(i=0;i<length;i++)
   {

       cout<< list[i];
   }
    }
   if(a=="T" || a=="t") break;
   if(length==0 && f==0 && last!=0)
   {
       cout<<"Invalid"<<endl;
   }
   clearList();
   cout<<endl;
    }

}
