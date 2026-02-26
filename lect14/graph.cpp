// graph.cpp
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Graph{
    public:
        Graph(int num_vertices){
            // initialize the adjacency List
            adjList.resize(num_vertices); // vector of size num_vertices, each element is ?
        }
        void addEdge(int source, int dest){
            // add the edge (source, dest)
            adjList[source].insert(dest);
            // Done! If this was a undirected graph, you may have wanted to have a second line
            adjList[dest].insert(source);
        }
        void exploreBFS(int source){
            vector<bool> visited(adjList.size(), false);
            queue<int> q;
            visited[source] = true;
            cout << source << " ";
            q.push(source);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v : adjList[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        cout << v << " ";
                        q.push(v);
                    }
                }
            }


        }

        void display(){
            // Display the adjacency list
            for(int i = 0 ; i < adjList.size(); i++){
                cout << i << " : ";
                for (auto v : adjList[i]){
                    cout << v << ", ";
                }
                cout << endl;
            }

        }
    
    private:
        vector<unordered_set<int>> adjList; // adjacency list
};

/*
Unweighted graph
Edge List E = {  (0, 2), 
                 (2, 3), (2, 1), (2, 4), 
                 (3, 1),  
                 (1, 5), (1, 4),
                 (4, 5)
                 }

Adjacency list representation
adjList =   {    {2}, 
                 {5, 4},
                 {3, 1, 4}, 
                 {1},  
                 {5},
                 {}
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
    Graph g(6); // g is an unweighted directed graph with 6 vertices
                // Unweighted means edges don't have associated weights
                // Directed means and edge from A to B does not automatically 
                // imply that there is an edge from B to A
    g.addEdge(0, 2); // add edge from vertex 0 to vertex 2
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(1, 5);
    g.addEdge(1, 4);
    g.addEdge(4, 5);

    g.display();

    cout << "Breadth First Traversal: ";
    g.exploreBFS(0);
    cout << endl;
    return 0;
}
