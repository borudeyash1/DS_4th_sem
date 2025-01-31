#include <iostream>
using namespace std;

class Emp {
    string name, id, add;
    Emp *lc, *rc; // left child and right child of node
public:
    void accept();
    void insert(Emp *root, Emp *next); // contains the joining if two nodes
    void display();
    
}*next = NULL, *root = NULL;


void Emp::accept() {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter address: ";
    cin >> add;
    insert(root, next);
}

void Emp::insert(Emp *root, Emp *next) {
    int press;
    cout << "Which side of " << root->name << " you want to join?\nif left press 1\nif right press 2" << endl;
    cin >> press;
    if (press == 1) {
        if (root->lc == NULL) {
            root->lc = next;
            next->lc = next->rc = NULL;
        }
        else {
            insert(root->lc, next);
        }
    }
    else if (press == 2) {
        if (root->rc == NULL) {
            root->rc = next;
            next->lc = next->rc = NULL;
        }
        else {
            insert(root->rc, next);
        }
    }
}

void Emp::display() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Address: " << add << endl;
}


int main() {
    int choice;
    while (choice != 3) {
        cout << "1. accept Employee" << endl;
        cout << "2. Display Employee" << endl;
        
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
        {
            if (root == NULL) {
                root = new Emp();
                root->accept();
                root->lc = root->rc = NULL;
            }
            else {
                Emp *next = new Emp();
                next->accept();
                root->insert(root, next);
            }
            break;
        }
        case 2:
        {
            if (root == NULL)
                cout << "No employees to display!" << endl;
            else
                root->display();
            break;
        }
        }
    }
    return 0;
}