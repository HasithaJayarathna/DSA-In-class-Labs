#include <iostream>
#include<list>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    int label;
    //2. a int type list called neighbours
    list<int> neighbours;
};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n = 8;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label=i;
        }
    }

    void addedge(int u, int v){
        //select node u and push v into u's neighbour
        nodes[u-1].neighbours.push_back(v);
        //select node v and push u into v's neighbour
        //To make this a directed graph where u is directed to v ;
        //Commenting this below part we will be able to get the directed graph.
        nodes[v-1].neighbours.push_back(u);
    }

    void print(){
        //lets iterate through each node and print its neighbours
        for (int i = 0 ; i<n ; i++){
            cout << nodes[i].label + 1 << " --> ";
            for(int neighbour : nodes[i].neighbours){
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.

    g->addedge(1, 2);
    g->addedge(1, 4);
    g->addedge(1, 5);
    g->addedge(1, 3);
    g->addedge(2, 3);
    g->addedge(2, 6);
    g->addedge(4, 6);
    g->addedge(4, 8);
    g->addedge(4, 7);
    g->addedge(5, 6);
    g->addedge(5, 7);
    g->addedge(5, 8);

    //print the graph adjaceny list
    g->print();
}
