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
        for(int j = i; j < totalcities; j++){
            if(i == j){
                distance[i][j] = 0;    // No distance between the same city
                continue;
            }
            else {
                cout << "Enter Distance Between " << cities[i] << " and " << cities[j] << " : ";
                cin >> distance[i][j];
                distance[j][i] = distance[i][j]; // Make the distance symmetric
            }
        }
    }
}

void IMS::primsAlgorithm() {
    bool visited[10] = {false};
    int parent[10];
    int weight[10];
    int min, u, v;

    // Initialize weights to a high value (infinity equivalent)
    for (int i = 0; i < totalcities; i++) {
        weight[i] = 999;
        parent[i] = -1;
    }

    weight[0] = 0; // Start from the first city

    for(int count = 0; count < totalcities - 1; count++){
        min = 999;

        // Find the minimum weight edge
        for(int i = 0; i < totalcities; i++){
            if(visited[i] == false && weight[i] < min){
                min = weight[i];
                u = i;
            }
        }

        visited[u] = true; // Mark the city as visited

        // Update the weights of adjacent cities
        for(int i = 0; i < totalcities; i++){
            if(visited[i] == false && distance[u][i] != 0 && distance[u][i] < weight[i]){
                parent[i] = u;
                weight[i] = distance[u][i];
            }
        }
    }

    int minDistance = 0;
for(int i = 1; i < totalcities; i++){
    minDistance += distance[i][parent[i]];
    cout << cities[i] << " -> " << cities[parent[i]] << " : " << distance[i][parent[i]] << endl;
}
cout << "\nMinimum Distance: " << minDistance << endl;
}
void IMS::display() {
    cout << "\nAdjacency Matrix (Distances between Cities):\n";
    cout << "\t";
    for(int j = 0; j < totalcities; j++){
        cout << cities[j] << "\t";
    }
    cout << endl;
    for(int i = 0; i < totalcities; i++){
        cout << cities[i] << "\t";
        for(int j = 0; j < totalcities; j++){   
            cout << distance[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(){
    int choice;
    while(true){
        cout << "\n1. Accept\n2. Display\n3. Prims Algorithm\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                interviewer.accept();
                break;
            case 2:
                interviewer.display();
                break;
            case 3:
                interviewer.primsAlgorithm();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please choose a valid option.";
        }
    }
    return 0;
}