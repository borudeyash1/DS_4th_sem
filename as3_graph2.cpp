#include <iostream>

using namespace std;

class Node {
public:
    string city;
    int fuel;
    Node* next;
    Node* adj;

    Node( string& city)  {
        this->city = city;
        this->fuel = 0;
        this->next = nullptr;
        this->adj = nullptr;
        
    }
};

class FMS {
    Node* head;

public:
    FMS() {
        head = nullptr;
    }
    void accept(int num_city);
    void insertEdge(int edges);
    void display();
};

void FMS::accept(int num_city) {
    string city_name;
    for (int i = 0; i < num_city; i++) {
        cout << "Enter the city name: ";
        cin >> city_name;
        Node* newNode = new Node(city_name);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void FMS::insertEdge(int edges) {
    string src, dest;
    int cost;
    for (int i = 0; i < edges; i++) {
        cout << "Enter the source city: ";
        cin >> src;
        cout << "Enter the destination city: ";
        cin >> dest;
        cout << "Enter the cost: ";
        cin >> cost;

        Node* temp = head;
        while (temp) {
            if (temp->city == src) {
                Node* adjNode = new Node(dest);
                adjNode->fuel = cost;
                if (!temp->adj) {
                    temp->adj = adjNode;
                } else {
                    Node* adjTemp = temp->adj;
                    while (adjTemp->adj) {
                        adjTemp = adjTemp->adj;
                    }
                    adjTemp->adj = adjNode;
                }
                break;
            }
            temp = temp->next;
        }

        if (!temp) {
            cout << "Invalid source city. Please enter valid cities." << endl;
        }
    }
}

void FMS::display() {
    Node* temp = head;
    while (temp) {
        cout << "City: " << temp->city << " -> ";
        Node* adjTemp = temp->adj;
        while (adjTemp) {
            cout << "(" << adjTemp->city << ", " << adjTemp->fuel << ") ";
            adjTemp = adjTemp->adj;
        }
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    int num_city, edges;
    FMS fms;

    cout << "Enter the number of cities: ";
    cin >> num_city;
    fms.accept(num_city);

    cout << "Enter the number of edges: ";
    cin >> edges;
    fms.insertEdge(edges);

    int choice;
    while (true) {
        cout << "1. Display List\n2. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                fms.display();
                break;
            case 2:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
