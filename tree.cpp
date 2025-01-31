#include <iostream>
using namespace std;

class Emp {
    string name, id, add;
    Emp *lc, *rc; // left child and right child of the node

public:
    Emp() : lc(NULL), rc(NULL) {}
    void accept();
    void insert(Emp *root, Emp *next);
    void display(Emp *root);
};

Emp *root = nullptr;

void Emp::accept() {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter address: ";
    cin >> add;
}

void Emp::insert(Emp *root, Emp *next) {
    int press;
    cout << "Which side of " << root->name << " do you want to join?\n";
    cout << "If left, press 1\nIf right, press 2" << endl;
    cin >> press;
    if (!root) {
        cout << " Root is null, cannot insert." << endl;
        return;
    }

    if (press == 1) {
        if (root->lc == nullptr) {
            root->lc = next;
            cout << "Inserted at the left of " << root->name << endl;
        }
        else {
            insert(root->lc, next);
        }
    }
    else if (press == 2) {
        if (root->rc == nullptr) {
            root->rc = next;
            cout << "Inserted at the right of " << root->name << endl;
        }
        else {
            insert(root->rc, next);
        }
    }
    else {
        cout << "Invalid input. Please try again." << endl;
    }
}

void Emp::display(Emp *node) {
    if (!node)
        return; // Base case: if node is null, return
    cout << "Name: " << node->name << endl;
    cout << "ID: " << node->id << endl;
    cout << "Address: " << node->add << endl;

    if (node->lc) {
        cout << "Left child of " << node->name << ":" << endl;
        display(node->lc);
    }
    if (node->rc) {
        cout << "Right child of " << node->name << ":" << endl;
        display(node->rc);
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Accept Employee" << endl;
        cout << "2. Display Employees" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            Emp *next = new Emp();
            next->accept();
            if (!root) {
                root = next;
                cout << "Root employee added." << endl;
            }
            else {
                root->insert(root, next);
            }
            break;
        }
        case 2:
        {
            if (!root) {
                cout << "No employees to display!" << endl;
            }
            else {
                cout << "Employee Details:" << endl;
                root->display(root);
            }
            break;
        }
        case 3:
            cout << "Exiting....." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}