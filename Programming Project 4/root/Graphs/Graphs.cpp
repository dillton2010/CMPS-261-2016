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
    
    create();
    
}

void Graphs::create()
{
     
    int z = 0;
    int y = 0;
    ifstream infile;
    infile.open("graph.data");
        
    infile >> verts;  
        while (!infile.eof())//make the edge list
	{
           Edge a;
           
            infile >> a.firstPoint;
            infile >> a.secondPoint;
            infile>> a.weight;
            edges.push_back(a);
            z++;            
	}
   
    
    for(int i =0;i<edges.size();i++)// make the Node list
    {
        Node begin;
        begin.id = edges[i].firstPoint;
        begin.visited = false;
        bool correct = true;
        if(list.size() == 0)
        {
            list.push_back(begin);
        }
        for(int k =0;k<list.size();k++)
        {
            if(begin.id == list[k].id)
            {
                correct = false;
            }
        }
        if(correct == true)
        {
            list.push_back(begin);
        }  
    }
    
    int l =0;
    for(int z = 0; z<list.size();z++)// put children
    {
        Node check;
        check = list[z];
        for(int y = 0; y<edges.size();y++)
        {
            if(edges[y].secondPoint == check.id)
            {
                l = edges[y].firstPoint;
            }
            for(int i = 0;i<list.size();i++)
            {
                if(list[i].id == l)
                { 
                    check.Children.push_back(list[i]);
                }
            }
        }
    }
}






Node Graphs::getChild(Node B,int i)
{
    Node A;
    A =  B.Children[i];
    return A;
    
}

Node Graphs::getNode(Node B)
{
    return B;
}
//void Graphs::prims()
//{
    
    
//}



void Graphs:: bfs() // logic seems correct 
{ 
    
    
    Node A;
    Node child;
    
    Node begin;
    begin = list[0];
    queue <Node> Queue;
    Queue.push(begin);    
    if(!Queue.empty())
    {
        while(!Queue.empty())
        {
            begin = Queue.front();
            for(int i = 0;i<begin.Children.size();i++)
            {
                child = getChild(begin,i);
                if(child.visited == false)
                {
                    Queue.push(child);
                }
            }
             cout<<Queue.front().id<<endl;
             begin.visited == true;
            Queue.pop();
        }
    }
     
}


/* 
void Graphs:: dfs() 
{
    stack<Node> Stack;
    Node begin;
    begin = list[0];
    while(!Stack.empty())
    {
        Node top = Stack.top();
        cout<<top.id<<endl;
        Stack.pop();
        top.visited = true;
        for(int i = 0; i<list.size();i++)
        {
            if(list[i].visited == false)
            {
                Stack.push(list[i]);
            }
        }
        
    }
      
}
 /*
    void Graphs::prims()
    {
        Node begin;
        Node begin = list[0];
        vector<Edge>edgeList;
        vector<Node>nodeList;
        nodeList[0] = begin;
        for(int i = 0;i<edges.size();i++)
        {
            begin = nodeList[0];
            if()
        }
        
    }    

void Graphs::djikstra()
{
    
}
  */
