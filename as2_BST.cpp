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
    SMS() : lc(NULL), rc(NULL) {} // Constructor to initialize pointers
    void accept(SMS *&root); // Pass root by reference
    void insert(SMS *&root, SMS *next); // Pass root by reference
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
void SMS::accept(SMS *&root)
{
    SMS *newNode = new SMS();
    cout << "Enter name: ";
    cin >> newNode->name;
    cout << "Enter email: ";
    cin >> newNode->email;
    cout << "Enter address: ";
    cin >> newNode->address;
    cout << "Enter PRN: ";
    cin >> newNode->prn;
    cout << "Enter CET score: ";
    cin >> newNode->cet;
    insert(root, newNode);
}

// Function to insert a node into the BST
void SMS::insert(SMS *&root, SMS *next)
{
    if (root == NULL)
    {
        root = next; // Insert the first node
    }
    else if (next->cet < root->cet)
    {
        if (root->lc == NULL)
        {
            root->lc = next;
        }
        else
        {
            insert(root->lc, next);
        }
    }
    else
    {
        if (root->rc == NULL)
        {
            root->rc = next;
        }
        else
        {
            insert(root->rc, next);
        }
    }
}

// Function to display all students (iterative in-order traversal)
void SMS::displayAll(SMS *root)
{
    if (!root)
    {
        cout << "No students to display." << endl;
        return;
    }
    stack<SMS*> s;
    SMS* current = root;
    cout << "Name\tEmail\tAddress\tPRN\tCET Score" << endl;
    while (current != NULL || !s.empty())
    {
        while (current != NULL)
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

// Function to display IIT students (CET > 90)
void SMS::displayIIT(SMS *root)
{
    if (!root)
    {
        cout << "No students to display." << endl;
        return;
    }
    stack<SMS*> s;
    SMS* current = root;
    cout << "Name\tEmail\tAddress\tPRN\tCET Score" << endl;
    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->lc;
        }
        current = s.top();
        s.pop();
        if (current->cet > 90)
            cout << current->name << "\t" << current->email << "\t" << current->address << "\t" << current->prn << "\t" << current->cet << endl;
        current = current->rc;
    }
}

// Function to display non-IIT students (CET <= 90)
void SMS::displayNonIIT(SMS *root)
{
    if (!root)
    {
        cout << "No students to display." << endl;
        return;
    }
    stack<SMS*> s;
    SMS* current = root;
    cout << "Name\tEmail\tAddress\tPRN\tCET Score" << endl;
    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->lc;
        }
        current = s.top();
        s.pop();
        if (current->cet <= 90)
            cout << current->name << "\t" << current->email << "\t" << current->address << "\t" << current->prn << "\t" << current->cet << endl;
        current = current->rc;
    }
}

// Function to calculate the height of the tree
int SMS::height(SMS *root)
{
    if (!root)
        return 0;
    int leftHeight = height(root->lc);
    int rightHeight = height(root->rc);
    return max(leftHeight, rightHeight) + 1;
}

// Function to create a mirror image of the tree
void SMS::mirror(SMS *root)
{
    if (!root)
        return;
    mirror(root->lc);
    mirror(root->rc);
    swap(root->lc, root->rc);
}

// Function to count the number of nodes in the tree
int SMS::countNodes(SMS *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->lc) + countNodes(root->rc);
}

// Function to search for a student by PRN
void SMS::search(SMS *root, int prn)
{
    if (!root)
    {
        cout << "Student not found." << endl;
        return;
    }
    if (root->prn == prn)
    {
        cout << "Name\tEmail\tAddress\tPRN\tCET Score" << endl;
        cout << root->name << "\t" << root->email << "\t" << root->address << "\t" << root->prn << "\t" << root->cet << endl;
        return;
    }
    if (prn < root->prn)
        search(root->lc, prn);
    else
        search(root->rc, prn);
}

// Function to update student details by PRN
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

// Function to display ancestors of a given node
void SMS::displayAncestors(SMS *root, int prn)
{
    if (!root)
    {
        cout << "PRN not found in the tree." << endl;
        return;
    }
    if (root->prn == prn)
        return;
    cout << root->prn << " ";
    if (prn < root->prn)
        displayAncestors(root->lc, prn);
    else
        displayAncestors(root->rc, prn);
}
void SMS::displayTopper(SMS *root)
{
    if(root == NULL)
    {
        cout << "No students to display." << endl;
        return;
    }
    SMS *current = root;
    while(current->rc != NULL)
    {
        current = current->rc;
    }
    cout << "Name\tEmail\tAddress\tPRN\tCET Score" << endl;
    cout << current->name << "\t" << current->email << "\t" << current->address << "\t" << current->prn << "\t" << current->cet << endl;
    if(current->cet > 90)
        cout << current->name << " is the topper of the class." << endl;
    else
        cout << root->name << " is the topper of the class but not eligible for IIT." << endl;
}
void SMS::displayLowest(SMS *root){
    if(root == NULL)
    {
        cout << "No students to display." << endl;
        return;
    }
    SMS *current = root;
    while(current->rc != NULL)
    {
        current = current->rc;
    }
    cout << "Name\tEmail\tAddress\tPRN\tCET Score" << endl;
    cout << current->name << "\t" << current->email << "\t" << current->address << "\t" << current->prn << "\t" << current->cet << endl;
    if(current->cet <= 90)
        cout << current->name << " is the lowest scorer of the class." << endl;
    else
        cout << root->name << " is the lowest scorer of the class but scored more than 90." << endl;
}

int main()
{
    SMS *root = NULL;
    int choice, prn;
    do
    {
        cout << "\n1. Accept Student\n2. Display All\n3. Display IIT\n4. Display Non-IIT\n5. Height of Tree\n6. Mirror Tree\n7. Count Nodes\n8. Search\n9. Update\n10. Display Ancestors\n11. Display Topper\n12. Display Lowest\n13. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (root == NULL)
            {
                root = new SMS();
                root->accept(root);
            }
            else
            {
                SMS *newNode = new SMS();
                newNode->accept(newNode);
                root->insert(root, newNode);
            }
            break;
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
            cout << "Height of the tree: " << root->height(root) << endl;
            break;
        case 6:
            root->mirror(root);
            cout << "Tree mirrored successfully." << endl;
            break;
        case 7:
            cout << "Number of nodes: " << root->countNodes(root) << endl;
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
            cout << "Enter PRN for ancestors: ";
            cin >> prn;
            root->displayAncestors(root, prn);
            cout << endl;
            break;
        case 11:
            cout<<"Displaying the topper of the class"<<endl;
            root->displayTopper(root);
            break;
        case 12:
            cout << "Displaying the lowest of the class" << endl;
            root->displayLowest(root);
            break;
        case 13:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
            break;
        }
    } while (choice != 13);
    return 0;
}