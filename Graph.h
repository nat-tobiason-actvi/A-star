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
        vertex *search(int v);
        void printGraph();
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

vertex* Graph::search(int value){
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