/*A pizza delivery company wants to optimize its delivery process to minimize its delivery time and fuel cost.
The company has a central pizza hub where all pizzas are prepared. Multiple delivery locations exist where customers 
are waiting for their orders. A road network connects the hub to all delivery locations, with each road segment 
having a specific distance or travel time. The goal is to determine the shortest path from the pizza hub to each 
customer location so that deliveries can be made as quickly and efficiently as possible.*/

#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

class PizzaDelivery {
    public:
    int totalLocations;
    string locations[10]; // Names of hub and delivery locations
    int distance[10][10]; // Distance matrix
    void accept();
    void dijkstraAlgorithm();
    void display();
};



void PizzaDelivery::accept() {
    cout << "Enter Total Locations (including the Pizza Hub): ";
    cin >> totalLocations;

    cout << "Enter Location Names:\n";
    for (int i = 0; i < totalLocations; i++) {
        cout << "Location " << i + 1 << ": ";
        cin >> locations[i];
    }

    cout << "Enter Distance Between Locations (Enter 0 if same location, and 999 if no direct connection):\n";
    for (int i = 0; i < totalLocations; i++) {
        for (int j = i; j < totalLocations; j++) {
            if (i == j) {
                distance[i][j] = 0; // No distance for the same location
                continue;
            }
            cout << "Distance between " << locations[i] << " and " << locations[j] << ": ";
            cin >> distance[i][j];
            distance[j][i] = distance[i][j]; // Symmetric for undirected graph
        }
    }
}

void PizzaDelivery::dijkstraAlgorithm() {
    int start = 0; // Assume the pizza hub is at index 0
    int shortest[10]; // Array to store shortest distances
    bool visited[10] = {false}; // To mark visited locations
    int parent[10]; // To store the path

    // Initialize distances
    for (int i = 0; i < totalLocations; i++) {
        shortest[i] = INT_MAX; // Set initial distances to "infinity"
        parent[i] = -1; // No parent initially
    }
    shortest[start] = 0; // Distance from hub to itself is 0

    // Main Dijkstra's loop
    for (int count = 0; count < totalLocations - 1; count++) {
        // Find the location with the minimum distance value
        int minDist = INT_MAX, u;
        for (int i = 0; i < totalLocations; i++) {
            if (!visited[i] && shortest[i] < minDist) {
                minDist = shortest[i];
                u = i;
            }
        }

        visited[u] = true; // Mark the chosen location as visited

        // Update distances for adjacent locations
        for (int v = 0; v < totalLocations; v++) {
            if (!visited[v] && distance[u][v] && distance[u][v] != 999 &&
                shortest[u] + distance[u][v] < shortest[v]) {
                shortest[v] = shortest[u] + distance[u][v];
                parent[v] = u; // Update the parent
            }
        }
    }

    // Display the shortest paths
    cout << "\nShortest Paths from Pizza Hub (" << locations[start] << "):\n";
    cout << "Location\tDistance\tPath\n";
    for (int i = 1; i < totalLocations; i++) { // Skip the hub itself
        cout << locations[i] << "\t\t" << shortest[i] << "\t\t";
        // Print the path
        int j = i;
        while (parent[j] != -1) {
            cout << locations[j] << " <- ";
            j = parent[j];
        }
        cout << locations[start] << endl;
    }
}

void PizzaDelivery::display() {
    cout << "\nDistance Matrix (Locations):\n";
    cout << "\t";
    for (int i = 0; i < totalLocations; i++) {
        cout << locations[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < totalLocations; i++) {
        cout << locations[i] << "\t";
        for (int j = 0; j < totalLocations; j++) {
            cout << distance[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    
    int choice;
    PizzaDelivery system;

    do {
        cout << "\n1. Accept\n2. Display\n3. Dijkstra's Algorithm\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                system.accept();
                break;
            case 2:
                system.display();
                break;
            case 3:
                system.dijkstraAlgorithm();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please choose a valid option.";
        }
    }while(choice != 4);
    return 0;
}
