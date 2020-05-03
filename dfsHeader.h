#ifndef DFS_MK
#define DFS_MK

#include<vector>

using namespace std;

class Node{
	private:
		int id;//for tracking nodes
		int data;//nodes contain some number as their data
		char color; //g,w,b
		vector<Node*> adj;//each nodes adjacency list
	public:
		static int ids;//used to increment ids for nodes
		Node(int);
		//getters and setters
		int getData() { return data; }
		char getColor() { return color; }
		int getId() { return id; }
		void setColor(char c) { this->color = c; }
		vector<Node*>  getAdj() { return adj; }
		void addAdj(Node * n) {adj.push_back(n); }
    void print();
};

class Graph{
	private:
		vector<Node*> graph;//list of nodes in the graph
	public:
		//getters and setters
		void addNode(Node * n) { graph.push_back(n); }
		vector<Node*>  getGraph() { return graph; };
    void print();  
};

void DFSVisit(Graph g, Node * n);
void DFS(Graph g);

#endif 
