#include "dfsHeader.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <chrono>

//give #numNodes, every node has numNodes/2 adjacents
Graph * generateGraphsSize(int numNodes){
  srand(time(0));//seed the random number generator
  Graph * ret = new Graph();//make a new graph 
  for(int i=0; i<numNodes; i++){//add numNodes nodes to the graph
    Node * newNode = new Node(i);
    ret->addNode(newNode);
  }
  int numEdgesPerNode = numNodes/2;//calculate numEdgesPerNode as numNodes/2
  vector<Node *> nodeList = ret->getGraph();
  for(auto it = nodeList.begin(); it != nodeList.end(); it++){//for each node we just created
    Node * currNode = (*it);
    vector<int> selectedAdjs;
    for(int i=0; i<numEdgesPerNode; i++){//add numEdgesPerNode to the currNode
      if(selectedAdjs.size() == 0){//first time adding an edge - no chance of duplicate/existing edge
        int r = rand() % nodeList.size(); //pick a random index from list of nodes
        currNode->addAdj(nodeList.at(r));//add an edge from currNode to selected node
        selectedAdjs.push_back(r);//add index of selected node to list of nodes currNode is adjacent to (used to check for unique edge later)
      }else{//adding >1st edge
        int r;
        bool unique = false;
        while(!unique){//loop until we find a unique node
          r = rand() % nodeList.size();//pick random node
          for(auto selected = selectedAdjs.begin(); selected != selectedAdjs.end(); selected++){//go though list of existing edges
            if(r != (*selected)){//if our random number isn't in the list yet, its unique
             unique=true;
            }else if(r == (*selected)){//as soon as we find that the random num is in the list, we need to pick a new random num
             unique = false;
             break;
            }
          }
        }
        currNode->addAdj(nodeList.at(r));//finally add the unique edge
        selectedAdjs.push_back(r);//and keep track of it 
      }
    }
  }
  return ret;//return the graph
}

//give #numEdgesPerNode, generate constant numNodes as 2 * numEdgesPerNode
Graph * generateGraphsEdges(int numEdgesPerNode){
  srand(time(0));//seed the random number generator
  Graph * ret = new Graph();//make a new graph
  int numNodes = 2*numEdgesPerNode;//determine numNodes as 2 * numEdgesPerNode
  for(int i=0; i<numNodes; i++){//make numNodes new nodes
    Node * newNode = new Node(i);
    ret->addNode(newNode);//and add them to the graph
  }
  vector<Node *> nodeList = ret->getGraph();
  for(auto it = nodeList.begin(); it != nodeList.end(); it++){//go through the node list
    Node * currNode = (*it);
    vector<int> selectedAdjs;
    for(int i=0; i<numEdgesPerNode; i++){//want to create numEdgesPerNode edges for the currNode
      if(selectedAdjs.size() == 0){//first edge - will always be unique
        int r = rand() % nodeList.size();//pick a random node in the list
        currNode->addAdj(nodeList.at(r));//make an edge between selected node and currNode
        selectedAdjs.push_back(r);//keep track of selectedNode's index to make sure we don't pick it again later
      }else{//>1st edge
        int r;
        bool unique = false;
        while(!unique){//loop until we find a unique edge
          r = rand() % nodeList.size();//pick a random node
          for(auto selected = selectedAdjs.begin(); selected != selectedAdjs.end(); selected++){//check the list of existing edges
            if(r != (*selected)){//random num is not the current element, so far r is unique
             unique=true;
            }else if(r == (*selected)){//we found r in the list, its not unique, so break and pick again
             unique = false;
             break;
            }
          }
        }
        currNode->addAdj(nodeList.at(r));//add edge 
        selectedAdjs.push_back(r);//keep track of edge
      }
    }
  }
  return ret;//return the graph
}



//run our experiment - increase numEdges, then increase numEdgesPerNode
void tester(){
  ofstream sizeOutput("sizeOutput.txt");//save the results of size test in sizeOutput
  for(int i=5; i<1005; i+=5){//from 5 nodes to 1005, incrementing by 5
    vector<int> results;
    for(int j=0; j<10; j++){//used to average our results - decrease influence of outliers but running DFS 10 times for each sample to get an average
    	Graph *g = generateGraphsSize(i);//make a graph with i nodes
    	//start time
    	auto start = chrono::high_resolution_clock::now();//start the timer
    	DFS(*g);//run DFS
    	//end time
    	auto end = chrono::high_resolution_clock::now();//end the timer
    	auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start);//calculate runtime in nanoseconds
    	//output
    	results.push_back(duration.count());//add the results to a results vector
    }
    int avg = 0;
    for(auto it = results.begin(); it < results.end(); it++){//calculate the average runtime for this sample
	avg+=(*it);
    }
    sizeOutput<<i<<","<<avg/results.size()<<"\n"<<endl;//print our the numNodes and the average result
  }
   ofstream densityOutput("densityOutput.txt");//save the results of the density test in densityOutput
  for(int i=5; i<1005; i+=5){//from 5 numEdgesPerNode to 1005, incrementing by 5
     vector<int> results;
     for(int j=0; j<10; j++){//average our results - run each sample 10 times on DFS	
   	Graph *g = generateGraphsEdges(i);//generate graph with i numEdgesPerNode
    	//start time
    	auto start = chrono::high_resolution_clock::now();//start the timer
    	DFS(*g);//run DFS on the graph
    	//end time
    	auto end = chrono::high_resolution_clock::now();//end the timer
    	auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start);//calculate runtime
    	//output
	results.push_back(duration.count());//add results to vector 
    }
    int avg = 0;
    for(auto it = results.begin(); it < results.end(); it++){//find the average runtime 
	avg+=(*it);
    }
    densityOutput<<i<<","<<avg/results.size()<<"\n"<<endl;//print out numEdgesPerNode, avg runtime
  }
}

//for running demo or actual experiment - currently set up for demo
int main(void){
  //demo code
  
  
  //creation of nodes
	//parameter provides data, 
	//constructor sets color to white
	//and assigns unique ID
	Node one(1);
	Node two(2);
	Node three(3);
	Node four(4);
	Node five(5);
	Node six(6);
	Node seven(7);
	Node eight(8);

	//setting up the edges
	//order matters
	one.addAdj(&two);
	one.addAdj(&four);
	one.addAdj(&five);
	two.addAdj(&three);
	five.addAdj(&six);
	six.addAdj(&seven);

	//adding nodes to graph
	//order matters
	Graph h;
	h.addNode(&one);
	h.addNode(&two);
	h.addNode(&three);
	h.addNode(&four);
	h.addNode(&five);
	h.addNode(&six);
	h.addNode(&seven);
	h.addNode(&eight);


	cout<<"\nBefore DFS"<<endl;
	h.print();
	cout<<"\nDuring DFS"<<endl;
	DFS(h);
	cout<<"\nAfter DFS"<<endl;
	h.print();
  
  
  //uncomment to run the experimental tests
  //also uncomment the print statement in DFSVisit
  //tester();
  return 0;
}
