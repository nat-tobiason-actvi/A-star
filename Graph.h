#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct adjVertex;

struct vertex{
    char key;
    bool visited;
    int distance;
    vector<adjVertex> adj;

    vertex(char n){
        key = n;
        visited = false;
        distance = 0;
    }
};

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
        void insertVertex(char value);
        void insertEdge(char v1, char v2, int w);
        vertex *search(char v);
        void printGraph();
        void dijkstra(char, char);
};

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

vertex* Graph::search(char value){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == value) return &vertices[i];
    }
    return NULL;
}

void Graph::printGraph(){
    for(int x = 0; x < vertices.size(); x++){
        cout << vertices[x].key << " --> ";
        for(int y = 0; y < vertices[x].adj.size(); y++){
            cout << vertices[x].adj[y].v->key << " ";
        }
        cout << endl;
    }
}




void print_vector(vector <vertex> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i].key << " --> ";
    }
    cout << endl;
}


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