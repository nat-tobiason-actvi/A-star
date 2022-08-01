#include "Graph.h"

int main(){
    
    Graph g;
    g.insertVertex('a');
    g.insertVertex('b');
    g.insertVertex('c');
    g.insertVertex('d');
    g.insertVertex('e');
    g.insertVertex('f');
    g.insertVertex('g');
    g.insertVertex('h');
    g.insertVertex('i');
    g.insertVertex('j');

    g.insertEdge('a', 'b', 4);
    g.insertEdge('a', 'h', 8);

    g.insertEdge('b', 'c', 8);
    g.insertEdge('b', 'h', 11);

    g.insertEdge('c', 'd', 7);
    g.insertEdge('c', 'i', 2);
    g.insertEdge('c', 'f', 4);

    g.insertEdge('d', 'e', 9);
    g.insertEdge('d', 'f', 14);

    g.insertEdge('f', 'e', 10);
    g.insertEdge('f', 'd', 14);

    g.insertEdge('g', 'f', 2);
    g.insertEdge('g', 'i', 6);

    g.insertEdge('h', 'g', 1);
    g.insertEdge('h', 'i', 7);

    g.insertEdge('i', 'c', 2);
    g.insertEdge('i', 'g', 6);
    
    
    g.printGraph();

    g.dijkstra('a', 'd');

    return 0;
}





