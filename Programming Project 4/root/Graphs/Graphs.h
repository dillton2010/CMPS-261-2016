/* 
 * File:   graphs.h
 * Author: dillon
 *
 * Created on April 16, 2016, 7:02 PM
 */
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#ifndef GRAPHS_H
#define	GRAPHS_H
 







struct Edge
{
public:
    int firstPoint;
    int secondPoint;
    int weight; 
    
};
struct  Node
{
public:
    int id;
   vector <Node> Children;
   bool visited;
    
};

class Graphs
{
  
public:
    Graphs();
    void bfs();
    void dfs();
    Node getChild(Node B, int i);
    Node getNode(Node B);
    void djikstra();
    void prims();
    void create();
private:
    vector<Edge>edges;
    int verts;
    vector<Node> list;
 
   
};



#endif	/* GRAPHS_H */
