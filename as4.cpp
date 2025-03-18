#include<iostream>
using namespace std;

class IMS{
    public :
    int totalcities;
    string cities[10];
    int distance[10][10];
    void accept();
    void primsAlgorithm();
    void display();
};

IMS interviewer;

void IMS::accept(){
    cout << "Enter Total Cities : ";
    cin >> totalcities;
    for(int i = 0; i < totalcities; i++){
        cout << "Enter City Name : ";
        cin >> cities[i];
    }

    for(int i = 0; i < totalcities; i++){
        for(int j = 0; j < totalcities; j++){
            if(i == j){
                distance[i][j] = 0; // No distance between the same city
                continue;
            }
            else {
                cout << "Enter Distance Between " << cities[i] << " and " << cities[j] << " : ";
                cin >> distance[i][j];
            }
        }
    }
}

void IMS::primsAlgorithm() {
    bool visited[10] = {false};
    int parent[10];
    int weight[10];
    int min, u;

    // Initialize weights to a high value (infinity equivalent)
    for (int i = 0; i < totalcities; i++) {
        weight[i] = 999;
        parent[i] = -1;
    }

    weight[0] = 0; // Start from the first city

    for(int count = 0; count < totalcities - 1; count++){
        min = 999;

        // Find the minimum weight unvisited city
        for(int v = 0; v < totalcities; v++){
            if(!visited[v] && weight[v] < min){
                min = weight[v];
                u = v;
            }
        }

        visited[u] = true; // Mark the city as visited

        // Update the weights of adjacent cities
        for(int v = 0; v < totalcities; v++){
            if(!visited[v] && distance[u][v] && distance[u][v] < weight[v]){
                parent[v] = u;
                weight[v] = distance[u][v];
            }
        }
    }

    // Display the Minimum Spanning Tree
    cout << "\nEdge \tWeight\n";
    for(int i = 1; i < totalcities; i++){
        cout << cities[parent[i]] << " - " << cities[i] << " \t" << distance[i][parent[i]] << " \n";
    }
}

void IMS::display() {
    cout << "\nAdjacency Matrix (Distances between Cities):\n";
    for(int i = 0; i < totalcities; i++){
        for(int j = 0; j < totalcities; j++){
            cout << distance[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(){
    interviewer.accept();
    interviewer.display();
    interviewer.primsAlgorithm();
    return 0;
}