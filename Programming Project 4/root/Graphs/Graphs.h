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
 







struct Data
{
public:
    int from;
    int to;
    int cost;
};
struct  Node
{
public:
    int id;
    
   vector <Node*> Children;
   bool visited;
    
};
struct Edge
{
public:
    Node firstPoint;
    Node secondPoint;
    int weight; 
    
};
class Graphs
{
  
public:
    Graphs();
    void createNodeList();
    void createEdgeList();
    void bfs();
    void dfs();
    Node getChild(Node B, int i);
    Node getNode(Node B);
    void djikstra();
    void prims();
    Node pickChild(Node B);
    Edge findSmallest(vector <Edge>&cost);
private:
    vector<Edge>EdgeList;
    int verts;
    vector <Node> NodeList;
    vector <Data> DataList;
};

#endif	/* GRAPHS_H */

