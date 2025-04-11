/*A pizza delivery company wants to optimize its delivery process to minimize its delivery time and fuel cost.
The company has a central pizza hub where all pizzas are prepared. Multiple delivery locations exist where customers
are waiting for their orders. A road network connects the hub to all delivery locations, with each road segment
having a specific dist or travel time. The goal is to determine the shortest path from the pizza hub to each
customer location so that deliveries can be made as quickly and efficiently as possible.*/

#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

class PizzaDelivery
{
    int totalLocations;
    string locations[10]; // Names of hub and delivery locations
    float dist[10][10];             // Dist matrix
public:
    void accept();
    void bellmanFordAlgorithm();
    void display();
};

void PizzaDelivery::accept()
{
    cout << "Enter Total Locations (including the Pizza Hub): ";
    cin >> totalLocations;

    cout << "Enter Location Names:\n";
    for (int i = 0; i < totalLocations; i++)
    {
        cout << "Location " << i + 1 << ": ";
        cin >> locations[i];
    }

    cout << "Enter Dist Between Locations in km (Enter 0 if same location, and 999 if no direct connection):\n";
    for (int i = 0; i < totalLocations; i++)
    {
        for (int j = i; j < totalLocations; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;   // No dist for the same location
                continue;
            }
            cout << "Dist between " << locations[i] << " and " << locations[j] << ": ";
            cin >> dist[i][j];
            dist[j][i] = dist[i][j];              // Symmetric for undirected graph
        }
    }
}

void PizzaDelivery::bellmanFordAlgorithm()
{
    int start = 0;              // pizza hub is at index 0
    int shortest[10];           // shortest dists
    int parent[10];             //  path

    // Initialize dists
    for (int i = 0; i < totalLocations; i++)
    {
        shortest[i] = INT_MAX; 
        parent[i] = -1;        // No parent initially
    }
    shortest[start] = 0; // Dist from hub to itself is 0

    // Main Bellman-Ford loop
    for (int i = 0; i < totalLocations - 1; i++)
    {
        for (int u = 0; u < totalLocations; u++)
        {
            for (int v = 0; v < totalLocations; v++)
            {
                if (dist[u][v] && shortest[u] + dist[u][v] < shortest[v])
                {
                    shortest[v] = shortest[u] + dist[u][v];
                    parent[v] = u; // Update the parent
                }
            }
        }
    }

    // Check for negative weight cycle
    for (int u = 0; u < totalLocations; u++)
    {
        for (int v = 0; v < totalLocations; v++)
        {
            if (dist[u][v] && shortest[u] + dist[u][v] < shortest[v])
            {
                cout << "Negative weight cycle detected." << endl;
                return;
            }
        }
    }

    // Display the shortest paths
    cout << "\nShortest Paths from Pizza Hub (" << locations[start] << "):\n";
    cout << "Location\tDist\tPath\n";
    for (int i = 1; i < totalLocations; i++)
    { // Skip the hub itself
        cout << locations[i] << "\t\t" << shortest[i] << "\t\t";
        // Print the path
        int j = i;
        while (parent[j] != -1)
        {
            cout << locations[j] << " <- ";
            j = parent[j];
        }
        cout << locations[start] << endl;
    }
}

void PizzaDelivery::display()
{
    cout << "\nDist Matrix (Locations):\n";
    cout << "\t";
    for (int i = 0; i < totalLocations; i++)
    {
        cout << locations[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < totalLocations; i++)
    {
        cout << locations[i] << "\t";
        for (int j = 0; j < totalLocations; j++)
        {
            cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{

    int choice;
    PizzaDelivery system;

    do
    {
        cout << "\n1. Accept\n2. Display\n3. Bellman-Ford Algorithm\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system.accept();
            break;
        case 2:
            system.display();
            break;
        case 3:
            system.bellmanFordAlgorithm();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice. Please choose a valid option.";
        }
    } while (choice != 4);
    return 0;
}

