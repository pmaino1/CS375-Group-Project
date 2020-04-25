#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Node {
	private:
		int id;
		int data;
		char color; //g,w,b
		vector<Node*> adj;
		//maybe include a parent node, maybe include
		//vector of nodes that point here
	public:
		static int ids;
		Node(int d) {
			id = ids+1;
			ids++; 
			data = d;
			color = 'w';		
		}
		//~Node();
		int getData() { return data; }
		char getColor() { return color; }
		int getId() { return id; }
		void setColor(char c) { this->color = c; }
		vector<Node*>  getAdj() { return adj; }
		void addAdj(Node * n) {adj.push_back(n); }

		void print() {
			cout<<"NODE "<< id << ", " << "data: "<< data <<",  color: "<< color <<endl;
			cout << "---ADJ TO: ";
			if(!adj.empty()){ 
        for (auto it = adj.begin(); it != adj.end(); it++) {
				  cout << (*it)->getId() << "("<< (*it)->getData() << "," << (*it)->getColor() << "), ";
			  }
      }
			cout << endl;
		}
};


class Graph {
	private:
		vector<Node*> graph;
	public:
		//Graph();
		void addNode(Node * n) { graph.push_back(n); }
		vector<Node*>  getGraph() { return graph; }

		void print() {
			for (auto it = graph.begin(); it != graph.end(); it++) {
				(*it)->print();
			}
		}
};

void DFSVisit(Graph g, Node * currNode){
  currNode->setColor('g');
  currNode->print();
  vector<Node *> adjList = currNode->getAdj();
  for(auto it = adjList.begin(); it != adjList.end(); it++){
    if( (*it)->getColor() == 'w' ) DFSVisit(g, *it); 
  }
  currNode->setColor('b');
}

void DFS(Graph g){
  vector<Node *> nodeList = g.getGraph();
  for(auto it = nodeList.begin(); it != nodeList.end(); it++){  
     if( (*it)->getColor() == 'w' ) DFSVisit(g, (*it)); 
  }
}


int Node::ids = 0;


//next time - generator for increasing density, size, fix one and increase the other, etc

int main(int argc, char** args) {
	
/*
	Node n(2);
	Node m(4);
	Node l(1);
  Node z(7);

	n.addAdj(&m);
	m.addAdj(&l);
	l.addAdj(&n);
  n.addAdj(&z);
  n.addAdj(&l);

	Graph g;
	g.addNode(&n);
	g.addNode(&m);
	g.addNode(&l);
  g.addNode(&z);

	//g.print();
  */
  //cout << (&n)->getColor() <<endl;


  Node one(1);
  Node two(2);
  Node three(3);
  Node four(4);
  Node five(5);
  Node six(6);
  Node seven(7);
  Node eight(8);
  Node nine(9);
  
  one.addAdj(&two);
  one.addAdj(&three);
  two.addAdj(&four);
  two.addAdj(&five);
  three.addAdj(&six);
  three.addAdj(&seven);
  four.addAdj(&eight);
  eight.addAdj(&nine);
  
  Graph h;
  h.addNode(&one);
  h.addNode(&two);
  h.addNode(&three);
  h.addNode(&four);
  h.addNode(&five);
  h.addNode(&six);
  h.addNode(&seven);
  h.addNode(&eight);
  h.addNode(&nine);
  
  DFS(h);

	return 0;
}
