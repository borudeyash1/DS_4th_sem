
#include <iostream>
using namespace std;

class Emp {
    string name, id, add;
    Emp* lc, *rc;

public:
    void create(Emp*& root) {
        if (root == nullptr) {
            root = new Emp();
        }
        cout << "Enter the name: " << endl;
        cin >> root->name;
        cout << "Enter the id: ";
        cin >> root->id;
        cout << "Enter the address: ";
        cin >> root->add;
    }

    void insert(Emp*& root, Emp*& next) {
        if (root == nullptr) {
            root = next;
            cout << "Inserted as root." << endl;
            return;
        }

        int press;
        cout << "Which side of " << root->name << " Do you want to insert?" << endl;
        cout << "If left, press 1\nIf right, press 2" << endl;
        cin >> press;

        if (press == 1) {
            if (root->lc == nullptr) {
                root->lc = next;
                cout << "Insert at the left of " << root->name << endl;
            }
            else {
                insert(root->lc, next);
            }
        }

        else if (press == 2) {
            if (root->rc == nullptr) {
                root->rc = next;
                cout << "Insert at the right of " << root->name << endl;
            }
            else {
                insert(root->rc, next);
            }
        }
        else {
            cout << "Invalid input. Please try again. " << endl;
        }
    }

    void displayInRec(Emp* root) {
        if (root == nullptr) {
            return;
        }
        if (root->lc) {
            displayInRec(root->lc);
        }

        cout << root->name << "\t" << root->id << "\t" << root->add << endl;

        if (root->rc) {
            displayInRec(root->rc);
        }
    }

    void displayInPre(Emp* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->name << "\t" << root->id << "\t" << root->add << endl;
        if (root->lc) {
            displayInPre(root->lc);
        }
        if (root->rc) {
            displayInPre(root->rc);
        }
    }

    void displayInPost(Emp* root) {
        if (root == nullptr) {
            return;
        }
        if (root->lc) {
            displayInPost(root->lc);
        }
        if (root->rc) {
            displayInPost(root->rc);
        }
        cout << root->name << "\t" << root->id << "\t" << root->add << endl;
    }
}*temp = nullptr;

Emp* root = nullptr;

int main() {
    Emp e;
    int choice;
    cout << "-----Menu-----\n";
    cout << "1.create\n2.Display Inorder\n3.Display Preorder\n4.Display Postorder\n5.Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    do {
        switch (choice) {
        case 1:
            if (root == nullptr) {
                e.create(root);
            }
            else {
                temp = new Emp();
                e.create(temp);
                e.insert(root, temp);
            }
            break;
        case 2:
            cout << "Inorder Traversal: " << endl;
            if (root) {
                e.displayInRec(root);
            }
            else {
                cout << "Tree is empty." << endl;
            }
            break;
        case 3:
            cout << "Preorder Traversal: " << endl;
            if (root) {
                e.displayInPre(root);
            }
            else {
                cout << "Tree is empty." << endl;
            }
            break;
        case 4:
            cout << "Postorder Traversal: " << endl;
            if (root) {
                e.displayInPost(root);
            }
            else {
                cout << "Tree is empty." << endl;
            }
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
            break;
        }
        if (choice != 5) {
            cout << "Enter your choice: ";
            cin >> choice;
        }
    } while (choice != 5);

    return 0;
}
