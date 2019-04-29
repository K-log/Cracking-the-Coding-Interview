/**
 *
 * CCI Ch4
 *
 * Noah
 *
 * Given a directed graph, design an algorithm to find a route between two nodes.
 */



#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class node {
    private:
        vector<node> neighbors;
        string id;
    public:
        node(string identifier) { id = identifier; }
        
        vector<node> getNeighbors() { return neighbors; }

        string getId() { return id; }

        void addConnection(node n) {
            if(n.getId() != id) {
                neighbors.push_back(n); 
            }
        }

        void addConnections(vector<node> ns) {
            for(int i = 0; i < ns.size(); i++) {
                if(ns[i].getId() != id) {
                    neighbors.push_back(ns[i]); 
                }
            }
        }
};


class Graph {
    public:
        Graph() { } 
        vector<node> nodes;
        void addNode(node n) {
            nodes.push_back(n);
        }
};


bool findConnection(node n1, node n2, vector<node> ns) {
    node curr = n1;
    for(int i = 0; i < curr.getNeighbors().size(); i++) {
         
    } 
    return false;
}


int main() {
    printf("Testing route between nodes.\n");

    Graph myGraph;

    node a("a");
    node b("b");
    node c("c");
    node d("d");
    node e("e");
    node f("f");
    node g("g");
    node h("h");

    a.addConnections(vector<node> {b, c}); 
    b.addConnections(vector<node> {f, e}); 
    c.addConnections(vector<node> {d, g}); 
    d.addConnections(vector<node> {c, f}); 
    e.addConnections(vector<node> {b, f, h}); 
    f.addConnections(vector<node> {a, g}); 
    g.addConnections(vector<node> {c, f}); 
    h.addConnections(vector<node> {e}); 

    vector<node> allNodes = {a, b, c, d, e, f, g, h};
    
    /** 
     *     h       a ---- f
     *     |     /   \    |
     *     e -- b     c - g 
     *      \  /      |   
     *       f  ----- d 
     */

    for(int i = 0; i < allNodes.size(); i++) {
        myGraph.addNode(allNodes[i]);
    }

    for(int i = 0; i < myGraph.nodes.size(); i++) {
        vector<node> n = myGraph.nodes[i].getNeighbors();
        for(int j =0; j < n.size(); j++){
            cout << n[j].getId(); 
        } 
        cout << '\n';
    }


    cout << findConnection(a, g, myGraph.nodes) << '\n';

    return 1;
}

