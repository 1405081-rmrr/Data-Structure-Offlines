#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3
using namespace std;

class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}

//****************Queue class ends here************************

//****************Dynamic ArrayList class based************************
class ArrayList
{
	int * list;
	int length ;
	int listMaxSize ;
	int listInitSize ;
public:
	ArrayList() ;
	~ArrayList() ;
	int searchItem(int item) ;
    void insertItem(int item) ;
	void removeItem(int item) ;
	void removeItemAt(int item);
	int getItem(int position) ;
	int getLength();
	bool empty();
	void printList();
} ;


ArrayList::ArrayList()
{
	listInitSize = 2 ;
	listMaxSize = listInitSize ;
	list = new int[listMaxSize] ;
	length = 0 ;
}

void ArrayList::insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = new int[listMaxSize] ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        delete[] list ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};

	list[length] = newitem ; //store new item
	length++ ;
}

int ArrayList::searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

void ArrayList::removeItemAt(int position) //do not preserve order of items
{
	if ( position < 0 || position >= length ) return ; //nothing to remove
	list[position] = list[length-1] ;
	length-- ;
}


void ArrayList::removeItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return ; //nothing to remove
	removeItemAt(position) ;
}


int ArrayList::getItem(int position)
{
	if(position < 0 || position >= length) return NULL_VALUE ;
	return list[position] ;
}

int ArrayList::getLength()
{
	return length ;
}

bool ArrayList::empty()
{
    if(length==0)return true;
    else return false;
}

void ArrayList::printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

ArrayList::~ArrayList()
{
    if(list) delete [] list;
    list = 0 ;
}

//******************ArrayList class ends here*************************

//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	ArrayList  * adjList ;
	int *color,*parent,*dist;
	int *color1,*parent1,*dist1;
	int *list1;
	int *discover,*finish;
	int time;
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	bool isEdge(int u, int v);
    int getDegree(int u);
    bool hasCommonAdjacent(int u, int v);
    int getDist(int u, int v);
    void printGraph();
	void bfs(int source); //will run bfs in the graph
	void dfs(int s); //will run dfs in the graph
	int dfs_visit(int u);
	//void init();
	int connectedComponents();
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	adjList = 0 ;
	directed = dir ;
	time=0; //set direction of the graph
	//define other variables to be initialized
}

void Graph::setnVertices(int n)
{
	nVertices = n ;
	if(adjList!=0) delete[] adjList ; //delete previous list
	adjList = new ArrayList[nVertices] ;
}

void Graph::addEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    this->nEdges++ ;
	adjList[u].insertItem(v) ;
	if(!directed) adjList[v].insertItem(u) ;
}

void Graph::removeEdge(int u, int v)
{
    //write this function
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    int x,y;
    x=adjList[u].searchItem(v);
    if(x!=NULL_VALUE)
    {
    	nEdges--;
    	adjList[u].removeItem(v);
	}
	 y=adjList[v].searchItem(u);
    if(y!=NULL_VALUE)
    {
    	//nEdges--;
    	adjList[v].removeItem(u);
	}
}


bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return false;
    int x,y;
    x=adjList[u].searchItem(v);
    if(x==NULL_VALUE)
    {
    	return false;
	}
	else return true;
}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u
	if(u<0 || u>=nVertices) return NULL_VALUE; 
	return 2*adjList[u].getLength();    

}

bool Graph::hasCommonAdjacent(int u, int v)
{
    //returns true if vertices u and v have common adjacent vertices
    int x=adjList[u].getLength();
    int y=adjList[v].getLength();
    int i,j;
    for(i=0;i<x;i++)
    {
    	for(j=0;j<y;j++)
    	{
    		if(adjList[u].getItem(i)==adjList[v].getItem(j))
    		{
    			return true;
			}
		}
	}
	return false;

}

void Graph::bfs(int source)
{
    //complete this function
    //initialize BFS variables
    if(source>nVertices) return;
    color = new int[INFINITY];
    parent = new int[INFINITY];
    dist = new int[INFINITY];
    int item;
    int i;
    int x;
    for(i=0; i<nVertices; i++)
    {
        color[i] = WHITE ;
        parent[i] = -1 ;
		dist[i] = INFINITY ;
    }
    Queue q ;
    color[source] = GREY;
    dist[source] = 0 ;
    parent[source]=0;
    q.enqueue(source) ;
    while( !q.empty() )
    {
        //complete this part'
        item=q.dequeue();
       	for(i=0;i<adjList[item].getLength();i++)
       	{
       		x=adjList[item].getItem(i);
       		if(color[x]==1)
       		{
       			color[x]=2;
       			dist[x]=dist[item]+1;
       			parent[x]=item;
       			q.enqueue(x);
			}
		}
		color[item]=3;
		cout<<item <<"->"<<endl;
		cout<<"The distance is "<<dist[item]<<endl;
		cout<<"The parent is "<<parent[item]<<endl;
		//cout<<item << "->" ;
    }
    cout<<endl;
}

void Graph::dfs(int s)
{
    //write this function

    if(nEdges <=0 ){
         //printf("Invalid input.\n");
         return;
    }

    color = new int [nVertices];
    parent = new int [nVertices];
    dist = new int [nVertices];



    int i;



    discover = new int [nVertices];
    finish = new int [nVertices];

    for(i=0;i<nVertices;i++){
        color[i] = WHITE;
        parent[i] = -1;
    }
    time = 0;
    //dfs_visit(s);

    

}
int Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    /*bool *visited = new bool[V];
    for(int v = 0; v < V; v++)
        visited[v] = false;*/
        if(nEdges==0) return nVertices;
        //cin>>s;
		dfs(0);
 
    int i,count=0;
    for(i=0;i<nVertices;i++)
    {
    	if(color[i]==1)
    	{
    		dfs_visit(i);
    		cout<<"\n";
    		count++;
		}
	}
	cout<<"\n";
	return count;
}
int Graph::dfs_visit(int u)
{

    //printf("%d ",u);
    time++;
    discover[u] = time;
    color[u] = GREY;

    int a;

    for(int j=0;j<adjList[u].getLength();j++){
    	if(adjList[u].getLength()==0) return 0;
        a = adjList[u].getItem(j);
        if(color[a]==WHITE){
            parent[a] = u;
           
            dfs_visit(a);
        }
    }
    
    cout<< u<<" " ;
    color[u] = BLACK;
    time++;
    finish[u] = time;


}
int Graph::getDist(int u, int v)
{
    //returns the shortest path distance from u to v
    //must call bfs using u as the source vertex, then use distance array to find the distance
    if(v>nVertices || u>nVertices) return 0;
    bfs(u);
    return dist[v];
    //return INFINITY ;
}

void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<adjList[i].getLength();j++)
        {
            printf(" %d", adjList[i].getItem(j));
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    //write your destructor here
     nVertices=0;
    nEdges=0;
    delete[] adjList;
    delete [] color;
    delete [] parent;
    delete [] dist;
}


//**********************Graph class ends here******************************


//******main function to test your code*************************
int main(void)
{
    int n;
    Graph g;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
        printf("1. Add edge. \n");
        printf("4. (Add from homework). 5. Print Graph  6. Exit. 7.Remove Edge 8. Is Edge 9.Get Degree 10.Has Common Adjacent\n");
		printf("11.BFS 12.Get Destination 13.DFS 14.Connected Components 15.Destructor 16.Again\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.addEdge(u, v);
        }
        else if(ch==7)
        {
			int u,v;
			cin>>u;
			cin>>v;
			g.removeEdge(u,v);
        }
       else if(ch==14)
       {
       	int p=g.connectedComponents();
       	cout<< p << endl;
       	
	   }
	   else if(ch==15)
	   {
	   	g.~Graph();
	   }
        else if(ch==11)
        {
        	int s;
        	cin>>s;
        	g.bfs(s);
		}
		else if(ch==13)
		{
			int s;
			cin>>s;
			cout<<"The nodes according to finishing time is ";
			g.dfs(s);
			cout<<"\n";
		}
		else if(ch==12)
		{
			int u,v;
			cin>>u;
			cin>>v;
			int p=g.getDist(u,v);
			cout<<"The shortest path distance is "<< p << endl;
		}
        else if(ch==10)
        {
        	int u, v;
            scanf("%d%d", &u, &v);
            bool p=g.hasCommonAdjacent(u,v);
        	if(p==true) cout<<"Yes !! It has" <<endl;
        	else cout<<"No!!!" <<endl;
		}
        else if(ch==8)
        {
        	int u,v;
			cin>>u;
			cin>>v;
			bool p=g.isEdge(u,v);
        	//cout<<p<<endl;
        	if(p==true) cout<<"Edge Found!!"<<endl;
        	else cout<<"Edge Not Found !!"<<endl;
		}
		else if(ch==9)
		{
			int u;
			cin>>u;
			int x=g.getDegree(u);
			cout<<"The number of Degree is "<< x <<endl;
		}
        else if(ch==3)
        {

        }
        else if(ch==5)
        {
            g.printGraph();
        }
        else if(ch==6)
        {
            break;
        }
    }

}
