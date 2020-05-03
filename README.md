# CS375-Group-Project

Compilation:
	To compile the files, type "make". This will compile the sources file "dfsImplementation.cpp" and "tester.cpp" into the executable "tester".

Execution: 
	To run the program, type "./tester". This will run "tester" and output the demo shown during the presentation. By editing "tester.cpp" 's main function, you can instead run the same tests we did to get our experimental results. 

Files:
  1. dfsHeader.h
      This header files declares everything that is shared by dfsImplementation and tester. This includes the Node class, the Graph class, and the 2 DFS functions: DFS and DFSVisit.
      
  2. dfsImplementation.cpp
      Where the functions declared in dfsHeader are defined. Most important feature other than the definition of class functions is the actual code for DFS and DFSVisit. 
      
  3. tester.cpp
      Where our experimental test code is, and where we run DFS from. Contains the methods used for graph creation, running the tests, and a main for demo code and running the experiment. This main function is what we run after compiling with "./tester".

Data Structures:
  1. Vectors
        We are using 2 vectors in this program, all of which are implemented via the std::vector class provided by the C standard library. The first is a vector of Node pointers are declared in the Node class, and is used as an adjacency list for each node. The other vector is declared in the Graph class, and holds Node pointers as well. This is used as the Graph's node list (a list to store all nodes in the graph).
  2. Stack
      We are not explicitly using a stack, but are implementing DFSVisit recursively. Therefore, we are using the call stack to keep track of the correct order to explore nodes.
      
Running Time: 
  As shown in our presentation, the runtime of DFS increases when both the size and density of a graph increases. We also found that this order of growth matches the theoritical order of growth of O(V+E). 
      
Classes:
    1. Node
        Used to store all info we needed about a node. This includes an id, color, data, and adjacency list. It also contains a functions for getting and setting these variables, as well as a print method for testing. 
        
    2. Graph
        Used to store everything we need about a graph. This includes a node list, getters and setters for this list, and a print method for debugging.
      
Methods:

  In dfsHeader.h:
      1. int getData() { return data; }:
          Purpose: a getter for a node's data.
          How it works: returns the private data of a node.
          Parameters: None.
          Variables: 
            1. data - the node's data which is returned.
      2. char getColor() { return color; }
          Purpose: a getter for a node's color.
          How it works: returns the private color of a node.
          Parameters: None.
          Variables: 
            1. color - the node's color which is returned.
      3. int getId() { return id; }
          Purpose: a getter for a node's id.
          How it works: returns the private id of a node.
          Parameters: None.
          Variables: 
            1. id - the node's id which is returned.
      4. void setColor(char c) { this->color = c; }
          Purpose: set the color of node.
          How it works: sets the private color of a node.
          Parameters: 
            1. c
              Purpose: pass in the color to update a node with (used when a node becomes traversed/explored in DFSVisit).
              Assumptions: is set to 'w', 'g', or 'b'. 
          Variables:
            1. this->color - the node's color variable.
      5. vector<Node*>  getAdj() { return adj; }
          Purpose: a getter for a node's adjacency list.
          How it works: returns the private adjacency list of a node.
          Parameters: None.
          Variables: 
            1. adj - the node's adjacency list which is returned.
      6. void addAdj(Node * n) {adj.push_back(n); }
          Purpose: add an edge to the node.
          How it works: adds a node to this node's adjacency list.
          Parameters: 
            1. n
              Purpose: the node to add to the adj list.
              Assumptions: is a valid node in the same graph as the current node. 
          Variables:
            1. adj - the node's adj list.
      7. void addNode(Node * n) { graph.push_back(n); }
          Purpose: add a node to the graph.
          How it works: adds a node to this graphs's node list.
          Parameters: 
            1. n
              Purpose: the node to add to the graph.
              Assumptions: is a valid/existing node. 
          Variables:
            1. graph - the graph's node list.
		  8. vector<Node*>  getGraph() { return graph; };
          Purpose: a getter for a graph's node list.
          How it works: returns the private node list of a graph.
          Parameters: None.
          Variables: 
            1. graph - the graph's node list which is returned.
            
  In dfsImplementation.cpp:
    1. Node::Node(int d)
        Purpose: The constructor for the Node class.
        How it works: Takes in a parameter to set as the data, then initalizes color to 'w', and id to the global id variable, then increments the global id var.
        Parameters:
          1. d
              Purpose: provide the data to set the node's data as.
              Assumptions: is an int.
        Variables:
          1. id - the node's id, used for testing.
          2. ids - the global id variable used to give each node a unique id.
          3. data - the node's data, which could be used during a search.
          4. color - the node's color - white, gray, or black (w, g, b).
    2. void Node::print()
        Purpose: Print a node's content to visualize a graph.
        How it works: prints the node's id, data, and color, then prints out the id, data, and color for each node in its adj list.
        Parameters: None.
        Variables:
          1. id, data, color - the private fields of a node to print.
          2. adj - the node's adj list to loop over.
          3. it - the iterator used to traverse the adj list and access the adj nodes to print.
    3. void Graph::print()
        Purpose: Print a graph for testing purposes.
        How it works: Iterate through a graph's node list and call print for each node.
        Parameters: none.
        Variables:
          1. it - the iterator used to loop through the node list, and used to call print() for each node.
    4. void DFS(Graph g)
        Purpose: Start our DFS search by looping through each node in the graph's node list.
        How it works: Iterate through the node list and call DFSVisit for each node which is not white. This ensures we visit all nodes, even ones with no connections.
        Parameters:
          1. g
            Purpose: provide the graph to perform the DFS on.
            Assumptions: is a valid/existing graph.
          Variables:
            1. nodeList - used to store g's list of nodes. Simplier to work with than g.getGraph().
            2. it - the iterator used to traverse nodeList.
    5. void DFSVisit(Graph g, Node * currNode)
        Purpose: the recursive function used to do most of the work required for DFS.
        How it works: Turn the incoming node 'g' to denote that it is currently being explored. Then, loop through the node's adj list, and call DFSVisit for each non-white node. Finally, color the node black once  it is fully explored.
        Parameters:
          1. g
            Purpose: Provide the graph we are searching through.
            Assumptions: is a valid/existing graph.
          2. currNode
            Purpose: Provide the node to examine.
            Assumptions: was colored white before entering the function.
        Variables:
          1. adjList - used to store currNode's adjList. Easier to work with than currNode->getAdj().
          2. it - the iterator used to traverse adjList.
        
  
  In tester.cpp:
    1. Graph * generateGraphsSize(int numNodes)
          Purpose: generate a random graph with numNodes number of nodes. Used for testing runtime vs size.
          How it works: creates numNodes nodes, and adds them to a graph. Then calculates numEdgesPerNode as numNodes/2, and adds numEdgesPerNode edges to each node in the graph. Then, for each node, loop numEdgesPerNode times. Pick a random node in the graph, and if this edge doesn't exist yet (checked by saving the indexes of added edges to a vector), add it to the adjList of the current node. Repeat until all edges created, then return the graph. 
          Parameters: 
            1. numNodes
                Purpose: provide the number of nodes to include in the graph, allowing us to compare graphs of different sizes.
                Assumptions: is an int.
          Variables: 
            1. Graph * ret - the graph we create and eventually return.
            2. int i = used to iterate and create numNode nodes.
            3. Node * newNode - used to store the newly created node on each loop.
            4. int numEdgesPerNode - used to keep track of how many edges to add for each node (numNodes/2).
            5. vector<Node *> nodeList - store the graph's node list (easier to work with than ret->getGraph()).
            6. auto it - used to loop though the nodeList.
            7. Node * currNode = used to store *it - the current node on each iteration (clearer code).
            8. vector<int> selectedAdjs - store the index of each node we create an edge to on this loop. Checked later to ensure a random number has picked a unique edge.
            9. int i - again used just to loop through a for loop.
            10. int r - store our random index in the nodeList.
            11. bool unique - flag used for checking if r represents a unique edge.
            12. auto selected - used to iterate through selectedAdj and check if r represents a unique edge. 
            
    2. Graph * generateGraphsEdges(int numEdgesPerNode) - note: works almost exactly the same as the function above, we kept them different for clarity.
          Purpose: generate a random graph with numEdgesPerNode number of edges per node. Used for testing runtime vs density.
          How it works: creates numNodes nodes, which is calculated as numEdgesPerNode * 2, and adds them to a graph. Then adds numEdgesPerNode edges to each node in the graph. Then, for each node, loop numEdgesPerNode times. Pick a random node in the graph, and if this edge doesn't exist yet (checked by saving the indexes of added edges to a vector), add it to the adjList of the current node. Repeat until all edges created, then return the graph. 
          Parameters: 
            1. numEdgesPerNode
                Purpose: provide the number of edges per node to include in the graph, allowing us to compare graphs of different densities.
                Assumptions: is an int.
          Variables: 
            1. Graph * ret - the graph we create and eventually return.
            2. int numNodes - used to see how many nodes to create this graph with (numNodesPerEdges * 2)
            3. int i = used to iterate and create numNode nodes.
            4. Node * newNode - used to store the newly created node on each loop.
            5. vector<Node *> nodeList - store the graph's node list (easier to work with than ret->getGraph()).
            6. auto it - used to loop though the nodeList.
            7. Node * currNode = used to store *it - the current node on each iteration (clearer code).
            8. vector<int> selectedAdjs - store the index of each node we create an edge to on this loop. Checked later to ensure a random number has picked a unique edge.
            9. int i - again used just to loop through a for loop.
            10. int r - store our random index in the nodeList.
            11. bool unique - flag used for checking if r represents a unique edge.
            12. auto selected - used to iterate through selectedAdj and check if r represents a unique edge. 
   
    3. void tester()
        Purpose: run our experiment by calling the above functions to create graphs, then run DFS on them.
        How it works: Create a for loop that runs from 5 to 1005 at intervals of 5, and create a graph with i numNodes. Then start a timer, and run DFS on the graph. Run DFS 10 times on this graph to take the average runtime, then print it to the file. Repeat this process with numEdgesPerNode and another file. 
        Parameters: none.
        Variables:
          1. ofstream sizeOutput - file to write the results of the size test to.
          2. int i - used to loop through the for loop. 
          3. vector<int> results - store the runtimes for graphs of size i so we can take the average runtime.
          4. int j - another looping variable (this time for the 10 cases used to calculate average runtime for this specfic size of graph).
          5. Graph * g - store the random graph created from generateGraphsSize with i numNodes.
          6. auto start - starting timestamp for runtime.
          7. auto end - ending timestamp for runtime.
          8. auto duration - runtime.
          9. int avg - sum of all runtimes for graphs of size i.
          10. ofstream densityOutput - file to write the results of the density test to.
          2. int i - used to loop through the for loop. 
          3. vector<int> results - store the runtimes for graphs with i numEdgesPerNode so we can take the average runtime.
          4. int j - another looping variable (this time for the 10 cases used to calculate average runtime for this specfic density of graph).
          5. Graph * g - store the random graph created from generateGraphsEdges with i numEdgesPerGraph.
          6. auto start - starting timestamp for runtime.
          7. auto end - ending timestamp for runtime.
          8. auto duration - runtime.
          9. int avg - sum of all runtimes for graphs with i numEdgesPerNode.
          
    4. int main()
        Purpose: run a demo/test or our experiment. 
        How it works: for a demo, creates a graph and calls print before, during, and after DFS. For running the experiment, it calls tester().
        Parameters: none.
        Variables:
          1. Node one - Node eight - sample nodes with their name and data equal (node one has data 1). Used for demo, where graph data is ordered in the same way that the graph will be traversed with DFS.