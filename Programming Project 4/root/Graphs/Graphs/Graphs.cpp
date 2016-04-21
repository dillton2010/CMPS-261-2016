// Graphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

class Edge
{
public:
	Edge(int f, int t, int w)
	{
		from = f;
		to = t;
		weight = w;
	}

	int from;
	int to;
	int weight;

};
class Node
{
private:
	int id;
	std::vector<Node> children;
	std::vector<Edge> adjacents;
public:
	Node(int n)
	{
		id = n;
	}
	void Info();
	void Add(Node &n, int w);
	
};


int main()
{
	//reading from file
	//read data "0 1 187"
	//str data = "0 1 187"
	//Node n(data[0])
	//n.Add(data[2], data[4])
	//what about data[4]?
	std::string data1 = "0 1 187";
	std::string data2 = "0 2 212";
	Edge e1(data1[0], data1[2], data1[4]);
	Edge e2(data2[0], data2[2], data2[4]);
	std::vector<Edge> edgeList;
	edgeList.push_back(e1);
	edgeList.push_back(e2);
	for (int i = 0; i < edgeList.size(); i++)
	{
		int nodeid = edgeList[i].from;
	}
	
	system("Pause");
    return 0;
}

void Node::Info()
{
	std::cout << "Number of children: " << children.size() << std::endl;
	for (int i = 0; i < children.size(); i++)
	{
		std::cout << "child #" <<children.at(i).id << std::endl;
	}

}

void Node::Add(Node &n, int w)
{
	
	this->children.push_back(n);
}
