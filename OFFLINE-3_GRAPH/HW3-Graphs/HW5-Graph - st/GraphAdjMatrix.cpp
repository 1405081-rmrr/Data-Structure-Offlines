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


//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	int ** matrix ; //adjacency matrix to store the graph
	int *color,*parent,*dist;
	int time;
	int *discover,*finish;
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
	void dfs(int source);  //will run dfs in the graph
	void dfs_visit(int u);
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	matrix = 0 ;
	directed = dir ;
	time=0; //set direction of the graph
	//define other variables to be initialized
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;

	//allocate space for the matrix
    matrix = new int*[nVertices];
    for(int i=0;i<nVertices;i++)
    {
        matrix[i] = new int[nVertices];
        for(int j=0;j<nVertices;j++)
            matrix[i][j] = 0; //initialize the matrix cells to 0
    }

}

void Graph::addEdge(int u, int v)
{
    //write your code here
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return;
    matrix[u][v] = 1;
    nEdges++;
    if(!directed) matrix[v][u] = 1;

}

void Graph::removeEdge(int u, int v)
{
    //write this function
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return;
    if(matrix[u][v]==1) 
    {
    	matrix[u][v]=0;
	}
	if(matrix[v][u]==1) 
    {
    	matrix[v][u]=0;
	}
	nEdges--;
}

bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return false;
    if(matrix[u][v]==1)
    {
    	return true;
	}
	else return false;
}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u
    int count=0;
    int i;
    for(i=0;i<nVertices;i++)
    {
    	if(matrix[u][i]==1) count=count+2;
	}
	return count;
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    //returns true if vertices u and v have common adjacent vertices
    int i;
    for(i=0;i<nVertices;i++)
    {
    	if(matrix[u][i]==1 && matrix[v][i]==1)
    	{
    		return true;
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
    int x,y;
    for(int i=0; i<nVertices; i++)
    {
        color[i] = WHITE ;
        parent[i] = -1 ;
        dist[i] = INFINITY ;
    }
    Queue q ;
    //color[source] = GREY;
    //dist[source] = 0 ;
    color[source] = GREY;
    dist[source] = 0 ;
    parent[source]=0;
    q.enqueue(source) ;
    while( !q.empty() )
    {
        //complete this part
          item=q.dequeue();
       	for(i=0;i<nVertices;i++)
       	{
       		x=matrix[item][i];
       		if(x==1){
			   y=i;
       		if(color[y]==1)
       		{
       			color[y]=2;
       			dist[y]=dist[item]+1;
       			parent[y]=item;
       			q.enqueue(y);
			}
		}
	}
		color[item]=3;
		cout<<item <<"->"<<endl;
		cout<<"The distance is "<<dist[item]<<endl;
		cout<<"The parent is "<<parent[item]<<endl;
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
    dfs_visit(s);

    

}

void Graph::dfs_visit(int u)
{

    //printf("%d ",u);
    time++;
    discover[u] = time;
    color[u] = GREY;

    int a,p;

    for(int j=0;j<nVertices;j++){
        a = matrix[u][j];
        if(a==1){
		p=j;
        if(color[p]==WHITE){
            parent[p] = u;
           
            dfs_visit(p);
        }
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
        for(int j=0; j<nVertices;j++)
        {
            if(matrix[i][j]==1)
                printf(" %d", j);
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    //write your destructor here
    nVertices=0;
    nEdges=0;
    delete[] matrix;
    delete(color);
    delete(parent);
    delete(dist);
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
        printf("2.Remove Edge.3. Is Edge  4. Get Degree 5. Print Graph  6. Exit. 7. Has Common Adjacent 8. BFS 9. Get Destination\n");
		printf("10.DFS\n");
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
        	bool p=g.hasCommonAdjacent(u,v);
        	if(p==true)
        	{
        		cout<<"Yes!! It has !!"<<endl;
			}
			else cout<<"No!!"<<endl;
		}
			else if(ch==10)
		{
			int s;
			cin>>s;
			cout<<"The nodes according to finishing time is ";
			g.dfs(s);
			cout<<"\n";
		}
		else if(ch==9)
		{
			int u,v;
			cin>>u;
			cin>>v;
			int p=g.getDist(u,v);
			cout<<"The shortest path distance is "<< p << endl;
		}
		
		else if(ch==8)
		{
			int s;
			cin>>s;
			g.bfs(s);
		}
        else if(ch==2)
        {
        	int u,v;
        	cin>>u;
        	cin>>v;
        	g.removeEdge(u,v);
        }
        else if(ch==3)
        {
			int u,v;
        	cin>>u;
        	cin>>v;
        	bool p=g.isEdge(u,v);
        	if(p==true) cout<<"Yes!!! It has"<<endl;
        	else cout<<"No !!!!"<<endl;
        }
        else if(ch==4)
        {
        	int u;
        	cin>>u;
        	int x=g.getDegree(u);
        	cout<<"The Degree is "<<x<<endl;
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
