#include "dfsHeader.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <chrono>

using namespace std;


Node::Node(int d) {//constructor
	id = ids+1;//set id
	ids++; //increment ids variable
	data = d;//set data as what was provided in parameter
	color = 'w';//set color as white
}

//a print function for testing - each node's info, then adjacency list
void Node::print() {
	cout<<"NODE "<< id << ", " << "data: "<< data <<",  color: "<< color <<endl;
	cout << "---ADJ TO: ";
	if(!adj.empty()){ 
		for (auto it = adj.begin(); it != adj.end(); it++) {
			cout << (*it)->getId() << "("<< (*it)->getData() << "," << (*it)->getColor() << "), ";
		}
	}
	cout << endl;
}

//print function that calls print for each node
void Graph::print() {
	for (auto it = graph.begin(); it != graph.end(); it++) {
		(*it)->print();
	}
}

//recursive function that does most of the work for a depth-first-search.
void DFSVisit(Graph g, Node * currNode){
	currNode->setColor('g');//set color to gray - node is being explored
	currNode->print();//for testing
	vector<Node *> adjList = currNode->getAdj();
	for(auto it = adjList.begin(); it != adjList.end(); it++){//go through the node's adjacency list
		if( (*it)->getColor() == 'w' ) DFSVisit(g, *it); //call DFSVisit for any white node
	}
	currNode->setColor('b');//done exploring - set color to black
}

//first function called for depth-first-search. go through all nodes, and call DFSVisit if it hasn't been explored yet.
void DFS(Graph g){
	vector<Node *> nodeList = g.getGraph();
	for(auto it = nodeList.begin(); it != nodeList.end(); it++){ //go though all nodes in the graph
		if( (*it)->getColor() == 'w' ) DFSVisit(g, (*it)); //call DFSVisit for any node that hasn't been explored
	}
}

int Node::ids = 0;//global variable for ID of nodes

