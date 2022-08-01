#include "Graph.h"

int main(){
    
    Graph g;
    g.insertVertex('a');
    g.insertVertex('b');
    g.insertVertex('c');
    g.insertVertex('d');

    g.insertEdge('a', 'b', 5);
    g.insertEdge('b', 'c', 1);
    g.insertEdge('a', 'd', 7);
    g.insertEdge('c', 'd', 1);
    
    g.printGraph();

    return 0;
}





