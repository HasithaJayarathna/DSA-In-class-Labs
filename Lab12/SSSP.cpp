#include <bits/stdc++.h>
using namespace std;

//Initialize matrix at all indexes to be 0.
void Initialize_Matrix (int matrix[6][6]){
    for(int i = 0; i < 6; i++){
        for (int j = 0 ; j< 6;j++){
            matrix[i][j] = 0;
        }
    }
}

//Create the adjacency matrix
void add_City (int matrix[6][6] , int cityA , int cityB, int weight){
    matrix[cityA][cityB] = weight;
    matrix[cityB][cityA] = weight;
}

//Function to display the city and the distance to the city from the start.
void Display_Distance (int distance[],int source){
    for(int i = 0 ; i < 6 ; i++){
        if(i != source){
            cout << "The shortest time between City " << source << " to City " << i << " is " << distance[i] << endl;
        }
    }
}

//Function to get the minimum time from the non visited cities.
int min_Distance (int distance[],bool isVisited[]){
    int minimum = INT_MAX;
    int minimum_index;
    for (int i = 0 ; i < 6 ; i++){
        if(isVisited[i] == false && distance[i] <= minimum){
            minimum = distance[i];
            minimum_index = i;
        }
    }
    return minimum_index;
}

//Function to get the average time of the total travel time.
float get_Average_Time (int distance[]){
    int sum = 0;
    for (int i = 0 ; i < 6 ; i ++){
        sum = sum + distance[i];
    }
    float average = float(sum)/5;
    return average;
}

void Dijkstra (int matrix[6][6], int source){
    int distance[6];
    bool isVisited[6];
    for(int i = 0 ; i < 6 ; i++){
        distance[i] = INT_MAX;
        isVisited[i] = false;
    }
    distance[source] = 0;

    for (int j = 0 ; j < 5 ; j++){
        int index = min_Distance(distance,isVisited);
        isVisited[index] = true;
        for(int k = 0 ; k<6 ; k++){
            if (!isVisited[k] && matrix[index][k] && distance[index] != INT_MAX && distance[index] + matrix[index][k] < distance[k]){
                distance[k] = distance[index] + matrix[index][k];
            }
        }
    }
    Display_Distance(distance,source);
    cout << endl;
    float average = get_Average_Time(distance);
    printf("Average time taken :- %.2f\n",average);
}


int main()
{
    int Adjacency_Matrix[6][6];

    //Initialize the matrix as all values to 0.
    Initialize_Matrix(Adjacency_Matrix);

    //Add each edge into the matrix.
    add_City(Adjacency_Matrix,0,1,10);
    add_City(Adjacency_Matrix,0,5,5);
    add_City(Adjacency_Matrix,0,4,15);
    add_City(Adjacency_Matrix,1,2,10);
    add_City(Adjacency_Matrix,1,3,30);
    add_City(Adjacency_Matrix,2,3,12);
    add_City(Adjacency_Matrix,2,4,5);
    add_City(Adjacency_Matrix,3,5,20);

    Dijkstra(Adjacency_Matrix,0);
    return 0;
}
