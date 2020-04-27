#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <chrono>

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
  //currNode->print();
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

//give #numNodes, every node has numNodes/2 adjacents
Graph * generateGraphsSize(int numNodes){
  srand(time(0));
  Graph * ret = new Graph();
  for(int i=0; i<numNodes; i++){
    Node * newNode = new Node(i);
    ret->addNode(newNode);
  }
  int numEdgesPerNode = numNodes/2;
  vector<Node *> nodeList = ret->getGraph();
  for(auto it = nodeList.begin(); it != nodeList.end(); it++){
    Node * currNode = (*it);
    vector<int> selectedAdjs;
    for(int i=0; i<numEdgesPerNode; i++){
      if(selectedAdjs.size() == 0){
        int r = rand() % nodeList.size(); 
        currNode->addAdj(nodeList.at(r));
        selectedAdjs.push_back(r);
      }else{
        int r;
        bool unique = false;
        while(!unique){
          r = rand() % nodeList.size();
          for(auto selected = selectedAdjs.begin(); selected != selectedAdjs.end(); selected++){
            if(r != (*selected)){
             unique=true;
            }else if(r == (*selected)){
             unique = false;
             break;
            }
          }
        }
        currNode->addAdj(nodeList.at(r));
        selectedAdjs.push_back(r);
      }
    }
  }
  return ret;
}


void tester(){
  ofstream densityOutput("densityOutput.txt");
  for(int i=0; i<1000; i+=5){
    Graph *g = generateGraphsSize(i);
    //start time
    auto start = chrono::high_resolution_clock::now();
    DFS(*g);
    //end time
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start);
    //output
    densityOutput<<duration.count()<<"\n"<<endl;
  }
}

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

/*

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


*/

  tester();

	return 0;
}
