#include <bits/stdc++.h>
using namespace std;

void makeMax (int adjmatrix[6][6]){
    for(int i = 0 ; i < 6 ; i++){
        for (int j = 0; j<6 ; j++){
          adjmatrix[i][j] = INT_MAX;
        }
    }
}

void addNode (int adjmatrix[6][6],int nodeA , int nodeB , int Weight){
    adjmatrix[nodeA][nodeB] = Weight;
    adjmatrix[nodeB][nodeA] = Weight;
}

void display (int adjmatrix[6][6]){
    for(int i = 0 ; i<6 ; i++){
        for (int j = 0; j<6;j++){
            cout << adjmatrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidEdge(int u, int v, vector<bool> inMST)
{
   if (u == v)
       return false;
   if (inMST[u] == false && inMST[v] == false)
        return false;
   else if (inMST[u] == true && inMST[v] == true)
        return false;
   return true;
}

void primMST(int cost[][6])
{
    vector<bool> inMST(6, false);

    int edge_number = 1;
    // Include first vertex in MST
    inMST[0] = true;
    // Keep adding edges while number of included
    // edges does not become V-1.
    int edge_count = 0, mincost = 0;
    while (edge_count < 6 - 1) {

        // Find minimum weight valid edge.
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (cost[i][j] < min) {
                    if (isValidEdge(i, j, inMST)) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            printf("Edge %d:(%d, %d) cost: %d \n",edge_number++, a, b, min,edge_count++);
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    printf("\nMinimum cost = %d \n", mincost);
}

int main()
{
    /*vector<vector<int>> newvector ;
    newvector.resize(6);
    for (int i = 0 ; i< 6; i++){
        newvector[i].resize(6);
    }
    newvector[0][1] = INT_MAX;
    cout << newvector[0][1];*/

    int adjmatrix [6][6] = {0};
    makeMax(adjmatrix);
  
    //Add enges and weights to the adjacency matrix.
    addNode(adjmatrix,1,2,2);
    addNode(adjmatrix,1,0,3);
    addNode(adjmatrix,1,4,10);
    addNode(adjmatrix,1,3,1);
    addNode(adjmatrix,2,1,2);
    addNode(adjmatrix,2,3,3);
    addNode(adjmatrix,2,5,5);
    addNode(adjmatrix,3,1,1);
    addNode(adjmatrix,3,2,3);
    addNode(adjmatrix,3,4,5);
    addNode(adjmatrix,4,1,10);
    addNode(adjmatrix,4,3,5);
    addNode(adjmatrix,4,5,4);
    addNode(adjmatrix,5,0,1);
    addNode(adjmatrix,5,4,4);
    addNode(adjmatrix,0,1,3);
    addNode(adjmatrix,0,5,1);

    primMST(adjmatrix);
}
