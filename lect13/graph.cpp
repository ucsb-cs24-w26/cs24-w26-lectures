// graph.cpp
#include <vector>
#include <iostream>
#include <unordered_set>
#include <iomanip>
using namespace std;

/*
Unweighted graph
Edge List E = {  (0, 2), 
                 (2, 3), (2, 1), (2, 4), 
                 (3, 1),  
                 (1, 5), (1, 4),
                 (4, 5)
                 }
*/

/*
Weighted graph
Edge List E = {  (0, 2, 0.5), 
                 (2, 3, 0.1), (2, 1, 0.7), (2, 4, 0.2), 
                 (3, 1, 0.3),  
                 (1, 5, 0.1), (1, 4, 0.9),
                 (4, 5, 0.3)
                 }
*/
int main(int argc, char const *argv[])
{
    // Graph g(6); // g is an unweighted directed graph with 6 vertices
    //             // Unweighted means edges don't have associated weights
    //             // Directed means and edge from A to B does not automatically 
    //             // imply that there is an edge from B to A
    // g.addEdge(0, 2); // add edge from vertex 0 to vertex 2
    // g.addEdge(2, 3);
    // g.addEdge(2, 1);
    // g.addEdge(2, 4);
    // g.addEdge(3, 1);
    // g.addEdge(1, 5);
    // g.addEdge(1, 4);
    // g.addEdge(4, 5);

    // g.display();
    return 0;
}
