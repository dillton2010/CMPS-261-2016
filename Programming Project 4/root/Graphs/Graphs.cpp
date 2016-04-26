#include <queue>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Graphs.h"
using namespace std;

Graphs::Graphs()
{
    int z = 0;
    int y = 0;
    
    ifstream infile;
    infile.open("graph.data");
    infile >> verts;  
        while (!infile.eof())//make the edge list
	{
           Data a;
           
            infile >> a.from;
            infile >> a.to;
            infile>> a.cost;
            DataList.push_back(a);
            z++;            
	}
    
    createNodeList();
   // createEdgeList();
}

void Graphs::createNodeList()
{
    vector<Node>List;
    for(int i =0;i<DataList.size();i++)// make the Node list
    {
        Node begin;
        begin.id = DataList[i].from;
        begin.visited = false;
        bool correct = true;
        if(List.size() == 0)
        {
            List.push_back(begin);
        }
        for(int k =0;k<List.size();k++)
        {
            if(begin.id == List[k].id)
            {
                correct = false;
            }
        }
        if(correct == true)
        {
            List.push_back(begin);
        }  
    }
    
    for(int z = 0; z<List.size();z++)// put children in correct place
    {
        Node check;
        check = List[z];
        for(int y = 0; y<DataList.size();y++)
        {
            if(DataList[y].to == check.id)
            {
                for(int i = 0;i<List.size();i++)
                {
                    if(List[i].id == DataList[y].from)
                    {
                        check.Children.push_back(&List[i]);
                    }
                }
            }
            
        }
        NodeList.push_back(check);
    }
    List.clear();
    
    
    
    
    //CreateEdgeList needs to get stuff by ref
    
    for(int i=0;i<DataList.size();i++)
    {
        Edge start;
        int s, e , w;
        s = DataList[i].from;
        e = DataList[i].to;
        w = DataList[i].cost;
      
        for(int k=0;k<NodeList.size();k++)
        {
            if(s == NodeList[k].id)
            {
                start.firstPoint = NodeList[k];
            }
            if(e == NodeList[k].id)
            {
                start.secondPoint = NodeList[k];
            }
        }
        start.weight = w;
        EdgeList.push_back(start);
    }
    
    
    
      //bsf function----- only going through one iteration;
    Node begin;
   Node child;
   
    begin = NodeList[4];
    queue <Node> Queue;
    Queue.push(begin);  
   
    if(!Queue.empty())
    {
        while(!Queue.empty())
        {
            begin = Queue.front();
            for(int i = 0;i<begin.Children.size();i++)
            {
                child = getChild(begin,i);//causes segfault but only if in its own fucntion
                
                if(child.visited == false)
                {   
                    Queue.push(child);
                }
            }
             begin.visited == true;
             cout<<begin.id<<endl;
            Queue.pop();
        }
    }
     
    
}
/*
void Graphs::createEdgeList() 
{  
    
    for(int i=0;i<DataList.size();i++)
    {
        Edge start;
        int s, e , w;
        s = DataList[i].from;
        e = DataList[i].to;
        w = DataList[i].cost;
      
        for(int k=0;k<NodeList.size();k++)
        {
            if(s == NodeList[k].id)
            {
                start.firstPoint = NodeList[k];
            }
            if(e == NodeList[k].id)
            {
                start.secondPoint = NodeList[k];
            }
        }
        start.weight = w;
        EdgeList.push_back(start);
    }
    Node B = NodeList[0];
    cout<<B.Children[0]->id;
}
*/
Node Graphs::getChild(Node B,int i)
{
    Node *A;
    Node C;
    A =  B.Children[i];
    C = *A;
    return C;
    
}
Edge Graphs:: findSmallest(vector <Edge>&cost)
{
    vector <Edge>Cost = cost;
    Edge smallest;
    smallest = Cost[0];
    for(int i =1;i<Cost.size();i++)
    {
        if(Cost[0].weight < smallest.weight)
        {
            smallest = Cost[0];
        }
    }
    
    return smallest;
}

void Graphs:: bfs() // logic seems correct 
{ 
    
   Node begin;
   Node child;
   
    begin = NodeList[0];
    queue <Node> Queue;
    Queue.push(begin);  
   
    if(!Queue.empty())
    {
        while(!Queue.empty())
        {
            begin = Queue.front();
            for(int i = 0;i<begin.Children.size();i++)
            {
                child = getChild(begin,i);//causes segfault
                
                if(child.visited == false)
                {   child.visited = true;
                    Queue.push(child);
                }
            }
             begin.visited == true;
             cout<<begin.id;
            Queue.pop();
        }
    }
     
}

Node Graphs::pickChild(Node B)
{
    Node A = B;
    int numChild = A.Children.size();
    int random = rand() % numChild;
    bool allVisited = false;
    if(numChild == 0)
    {
        exit;
    }
    for(int i =0;i<numChild;i++)
    {
        if(A.Children[i]->visited == false)
        {
            allVisited == false;
        }
        else
            allVisited = true;
    }
    if(allVisited == true)
    {
        exit;
    }
    if(A.Children[random]->visited!= false)
    {
        
        return A;
    }
    else 
        pickChild(A);
}

void Graphs:: dfs() 
{
    stack <Node> Stack;
    Node begin;
    begin = NodeList[0];
    Node *Child;
    bool allVisited;
    allVisited = false;
    begin.visited = true;
    Stack.push(begin);
    
    while(!Stack.empty())
    {
        begin = Stack.top();
        for(int i = 0;i<begin.Children.size();i++)
        {
            if(begin.Children[i]->visited == false)
            {
                allVisited = false;     
            }
            else
                allVisited = true;       
        }
        if(begin.Children.size()!=0 && allVisited == false)
        {
            *Child = pickChild(begin);// causes seg fault
            Node kid;
            kid = *Child;
            kid.visited = true;
            Stack.push(kid);
        }
        if(begin.Children.size()== 0)
        {
            cout<<Stack.top().id<<endl;;
            Stack.pop();
        }
    }
}
/*
void Graphs::prims()//FIX IT!!!!!!!
{
    vector<Edge>MST;
    vector<Edge>cost(EdgeList);
    for(int z = 0; z<cost.size();z++)
    {
        cost[z].weight = 32767; 
    }
    Node begin;
    begin = NodeList[0];
    begin.visited = true;
    for(int i = 0;i<cost.size();i++)
        {
            if(cost[i].firstPoint == begin && begin.visited)
            {
                cost[i].weight == EdgeList[i].weight;
            } 
        }
    for(int k = 0;k<NodeList.size();k++)
    {
        Edge smallest;
        smallest = findSmallest(cost);
        for(int l = 0;l<NodeList.size();l++)
        {
            if(smallest.secondPoint == NodeList[l])
            {
                begin = NodeList[l];
            }
        }
        for(int i = 0;i<cost.size();i++)
        {
            if(cost[i].firstPoint == begin && begin.visited == false)
            {
                cost[i].weight == EdgeList[i].weight;
            } 
        }
        begin.visited = true;
        
    }
}
void Graphs::djikstra()
{
    
}
  */