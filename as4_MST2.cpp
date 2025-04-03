#include <iostream>
#include <climits>
#include <string>

using namespace std;

#define MAX 100

class Graph {
public:
    int totalCities;
    string cities[MAX]; // Stores city names
    int fuelCost[MAX][MAX]; // Adjacency matrix for fuel cost

    void accept();
    void primsMST();
};

void Graph::accept() {
    cout << "Enter Total Cities: ";
    cin >> totalCities;

    // Accept city names
    for (int i = 0; i < totalCities; i++) {
        cout << "Enter City Name: ";
        cin >> cities[i];
    }

    // Initialize adjacency matrix
    for (int i = 0; i < totalCities; i++) {
        for (int j = 0; j < totalCities; j++) {
            fuelCost[i][j] = (i == j) ? 0 : INT_MAX;  // Diagonal set to 0, others to INT_MAX
        }
    }

    int totalRoutes;
    cout << "Enter Total Routes: ";
    cin >> totalRoutes;

    // Accept source, destination, and fuel cost
    for (int i = 0; i < totalRoutes; i++) {
        string source, destination;
        int fuel;
        cout << "Enter Route " << i + 1 << " (Source Destination Fuel_Cost): ";
        cin >> source >> destination >> fuel;

        int srcIndex = -1, destIndex = -1; // initi
        // Find indices for the source and destination cities
        for (int j = 0; j < totalCities; j++) {
            if (cities[j] == source) srcIndex = j;
            if (cities[j] == destination) destIndex = j;
        }

        // Update adjacency matrix if cities are valid
        if (srcIndex != -1 && destIndex != -1) {
            fuelCost[srcIndex][destIndex] = fuel;
            fuelCost[destIndex][srcIndex] = fuel;
        } else {
            cout << "Invalid City Name Entered. Try Again.\n";
            i--;
        }
    }
}

void Graph::primsMST() {
    int parent[MAX];  
    int key[MAX];     
    bool visited[MAX] = {false}; 
    int totalFuel = 0;

    // Initialize keys to infinity
    for (int i = 0; i < totalCities; i++) 
    {
        key[i] = INT_MAX; 
    
    }

    key[0] = 0; // Start from the first city
    parent[0] = -1; 

    for (int count = 0; count < totalCities - 1; count++) {
        int minKey = INT_MAX, minIndex = -1;

        // Find the minimum key vertex
        for (int i = 0; i < totalCities; i++) {
            if (!visited[i] && key[i] < minKey) {
                minKey = key[i];
                minIndex = i;
            }
        }

        visited[minIndex] = true; // Mark the vertex as visited

        // Update key and parent for adjacent vertices
        for (int i = 0; i < totalCities; i++) {
            if (!visited[i] && fuelCost[minIndex][i] && fuelCost[minIndex][i] < key[i]) {
                key[i] = fuelCost[minIndex][i];
                parent[i] = minIndex;
            }
        }
    }

    // Display the MST and calculate total fuel cost
    cout << "\nMinimum Spanning Tree (MST) based on Fuel Cost:\n";
    cout << "Route\tFuel Cost\n";
    for (int i = 1; i < totalCities; i++) {
        cout << cities[parent[i]] << " -> " << cities[i] << " : " << fuelCost[i][parent[i]] << endl;
        totalFuel += fuelCost[i][parent[i]];
    }
    cout << "Total Fuel Required for MST: " << totalFuel << endl;
}

int main() {
    Graph g;
    g.accept();
    g.primsMST();
    return 0;
}
