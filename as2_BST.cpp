/*/*
ASSIGNMENT NO : 2

Create a binary search tree which accepts student information such as:
- Name of student
- Address
- PRN number
- CET score marks

Based on CET score, students will get admission in IIT college. If the student scores less than 90 percent in CET, then they will be admitted to Sanjivani.

Perform the following operations:
- Display all student information
- Display only IITian student information
- Display non-IITian student information (can also use the count)
- Height of the tree
- Mirror image of the tree
- Count number of nodes
- Search student information
- Modify student information
- Display all ancestor nodes of a given node
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class SMS
{
    string name, email, address;
    int prn, cet;
    SMS *lc, *rc;

public:
    SMS() : lc(NULL), rc(NULL) {} // Constructor
    void accept();
    void insert(SMS *&root, SMS *newNode);
    void displayAll(SMS *root);
    void displayIIT(SMS *root);
    void displayNonIIT(SMS *root);
    int height(SMS *root);
    void mirror(SMS *root);
    int countNodes(SMS *root);
    void search(SMS *root, int prn);
    void update(SMS *root, int prn);
    void displayAncestors(SMS *root, int prn);
    void displayTopper(SMS *root);
    void displayLowest(SMS *root);
};

// Function to accept student details
void SMS::accept()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter address: ";
    cin >> address;
    cout << "Enter PRN: ";
    cin >> prn;
    cout << "Enter CET score: ";
    cin >> cet;
}

// Function to insert a node into BST
void SMS::insert(SMS *&root, SMS *newNode)
{
    if (!root)
    {
        root = newNode;
        return;
    }
    if (newNode->cet < root->cet)
        insert(root->lc, newNode);
    else
        insert(root->rc, newNode);
}

// Display all students (Iterative Inorder Traversal)
void SMS::displayAll(SMS *root)
{
    if (!root)
    {
        cout << "No students to display." << endl;
        return;
    }
    stack<SMS *> s;
    SMS *current = root;
    cout << "Name\tEmail\tAddress\tPRN\tCET Score" << endl;
    while (!s.empty() || current)
    {
        while (current)
        {
            s.push(current);
            current = current->lc;
        }
        current = s.top();
        s.pop();
        cout << current->name << "\t" << current->email << "\t" << current->address << "\t" << current->prn << "\t" << current->cet << endl;
        current = current->rc;
    }
}

// Display IIT students (CET > 90)
void SMS::displayIIT(SMS *root)
{
    if (!root)
        return;
    displayIIT(root->lc);
    if (root->cet > 90)
        cout << root->name << "\t" << root->email << "\t" << root->address << "\t" << root->prn << "\t" << root->cet << endl;
    displayIIT(root->rc);
}

// Display Non-IIT students (CET <= 90)
void SMS::displayNonIIT(SMS *root)
{
    if (!root)
        return;
    displayNonIIT(root->lc);
    if (root->cet <= 90)
        cout << root->name << "\t" << root->email << "\t" << root->address << "\t" << root->prn << "\t" << root->cet << endl;
    displayNonIIT(root->rc);
}

// Height of tree
int SMS::height(SMS *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->lc), height(root->rc));
}

// Mirror tree
void SMS::mirror(SMS *root)
{
    if (!root)
        return;
    mirror(root->lc);
    mirror(root->rc);
    swap(root->lc, root->rc);
}

// Count nodes
int SMS::countNodes(SMS *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->lc) + countNodes(root->rc);
}

// Search student by PRN
void SMS::search(SMS *root, int prn)
{
    if (!root)
    {
        cout << "Student not found." << endl;
        return;
    }
    if (root->prn == prn)
    {
        cout << root->name << "\t" << root->email << "\t" << root->address << "\t" << root->prn << "\t" << root->cet << endl;
        return;
    }
    if (prn < root->prn)
        search(root->lc, prn);
    else
        search(root->rc, prn);
}

// Update student details
void SMS::update(SMS *root, int prn)
{
    if (!root)
        return;
    if (root->prn == prn)
    {
        cout << "Enter new name: ";
        cin >> root->name;
        cout << "Enter new email: ";
        cin >> root->email;
        cout << "Enter new address: ";
        cin >> root->address;
        cout << "Enter new CET score: ";
        cin >> root->cet;
        return;
    }
    if (prn < root->prn)
        update(root->lc, prn);
    else
        update(root->rc, prn);
}

// Display ancestors
void SMS::displayAncestors(SMS *root, int prn)
{
    if (!root)
        return;
    if (root->prn == prn)
        return;
    cout << root->prn << " ";
    if (prn < root->prn)
        displayAncestors(root->lc, prn);
    else
        displayAncestors(root->rc, prn);
}

// Display topper
void SMS::displayTopper(SMS *root)
{
    while (root && root->rc)
        root = root->rc;
    cout << "Topper: " << root->name << " CET: " << root->cet << endl;
}

// Display lowest scorer
void SMS::displayLowest(SMS *root)
{
    while (root && root->lc)
        root = root->lc;
    cout << "Lowest Scorer: " << root->name << " CET: " << root->cet << endl;
}

int main()
{
    SMS *root = NULL;
    int choice, prn;

    do
    {
        cout << "\n1. Accept Student\n2. Display All\n3. Display IIT\n4. Display Non-IIT\n5. Height\n6. Mirror Tree\n7. Count Nodes\n8. Search\n9. Update\n10. Display Ancestors\n11. Display Topper\n12. Display Lowest\n13. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            SMS *newNode = new SMS();
            newNode->accept();
            root->insert(root, newNode);
            break;
        }
        case 2:
            root->displayAll(root);
            break;
        case 3:
            root->displayIIT(root);
            break;
        case 4:
            root->displayNonIIT(root);
            break;
        case 5:
            cout << "Height: " << root->height(root) << endl;
            break;
        case 6:
            root->mirror(root);
            cout << "Tree mirrored successfully." << endl;
            break;
        case 7:
            cout << "Total Nodes: " << root->countNodes(root) << endl;
            break;
        case 8:
            cout << "Enter PRN: ";
            cin >> prn;
            root->search(root, prn);
            break;
        case 9:
            cout << "Enter PRN to update: ";
            cin >> prn;
            root->update(root, prn);
            break;
        case 10:
            cout << "Enter PRN: ";
            cin >> prn;
            root->displayAncestors(root, prn);
            break;
        case 11:
            root->displayTopper(root);
            break;
        case 12:
            root->displayLowest(root);
            break;
        case 13:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 13);
    return 0;
}