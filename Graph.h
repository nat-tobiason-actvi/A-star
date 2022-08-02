#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct adjVertex;

// defines a vertex of a graph
struct vertex{
    char key;
    bool visited;
    int distance;
    vector<adjVertex> adj; // all adjacent vertex 

    vertex(char n){ // constructor
        key = n;
        visited = false;
        distance = 0;
    }
};

// defines adjacent vertex (used in vertex struct)
struct adjVertex{
    vertex *v;
    int weight;

    adjVertex(vertex *x){
        v = x;
        weight = 1;
    }
};


class Graph{
    private:
        vector <vertex> vertices;
    public:
        void insertVertex(char);
        void insertEdge(char, char, int);
        vertex *search(char);
        void printGraph();
        void dijkstra(char, char);
        void DFS(int);
        void BFS(int, int);
};

// inserts vertex into Graph with identifying value of a char
void Graph::insertVertex(char value){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == value){
            found = true;
            break;
        }
    }
    if(!found){
        vertex *v = new vertex(value);
        vertices.push_back(*v);
    }
}

// inserts edge in Graph between to vertex that can be identifyed by their char key
void Graph::insertEdge(char v1, char v2, int weight){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].key == v2 && i != j){
                    adjVertex *a = new adjVertex(&vertices[j]);
                    vertices[i].adj.push_back(*a);
                }
            }
        }
    }
}

// searchs for vertex within the graph by is char key
vertex* Graph::search(char value){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == value) return &vertices[i];
    }
    return NULL;
}

// prints visual representation of graph to console
void Graph::printGraph(){
    for(int x = 0; x < vertices.size(); x++){
        cout << vertices[x].key << " --> ";
        for(int y = 0; y < vertices[x].adj.size(); y++){
            cout << vertices[x].adj[y].v->key << " ";
        }
        cout << endl;
    }
}



// print visual representation of vertex vector to console
void print_vector(vector <vertex> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i].key << " --> ";
    }
    cout << endl;
}

// dijkstras algorithm to find the shortest path
void Graph::dijkstra(char start, char end){
    vertex* startV = search(start);
    vertex* endV = search(end);

    startV->visited = true;
    startV->distance = 0;

    vector <vertex> visited;
    visited.push_back(*startV); // list of visited verticies

    while(!endV->visited){
        int minDistance = INT_MAX;
        vertex* visitedV = new vertex(' ');

        for(int i = 0; i < visited.size(); i++){
            vertex v = visited[i];
            for(int j = 0; j < visited[i].adj.size(); j++){
                if(!visited[i].adj[j].v->visited){
                    int dist = v.distance + v.adj[j].weight;
                    if(dist < minDistance){
                        visitedV = v.adj[j].v;
                        minDistance = dist;
                    }
                }
            }
        }
        visitedV->distance = minDistance;
        visitedV->visited = true;
        visited.push_back(*visitedV);

    }
    cout << "path: ";
    print_vector(visited);
}



// Deapth first search algorithm
void depthfirstsearch(vertex v){
    v.visited = true;
    for(int i = 0; i < v.adj.size(); i++){
        if(!v.adj[i].v->visited){
            depthfirstsearch(*v.adj[i].v);
        }
    }
}
void Graph::DFS(int value){
    vertex *v = search(value);
    depthfirstsearch(*v);
}



// breadth first search algorithm
void Graph::BFS(int start, int value){
    queue<vertex> q;
    vertex *v = search(start);
    v->visited = true;
    q.push(*v);
    while(!q.empty()){
        vertex n = q.front(); q.pop();
        for(int i = 0; i < n.adj.size(); i++){
            if(!n.adj[i].v->visited){
                if(n.adj[i].v->key == value) return *n.adj[i].v;
                else{
                    n.adj[i].v->visited = true;
                    q.push(*n.adj[i].v);
                }
            }
        }
        return;
    }
}