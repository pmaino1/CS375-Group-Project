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
			for (auto it = adj.begin(); it != adj.end(); it++) {
				cout << (*it)->getId() << "("<< (*it)->getData() << "," << (*it)->getColor() << "), ";
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

int Node::ids = 0;

int main(int argc, char** args) {
	

	Node n(2);
	Node m(4);
	Node l(1);

	n.addAdj(&m);
	m.addAdj(&l);
	l.addAdj(&n);

	Graph g;
	g.addNode(&n);
	g.addNode(&m);
	g.addNode(&l);

	g.print();

	return 0;
}
