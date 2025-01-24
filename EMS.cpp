#include<iostream>
using namespace std;

class Employee {
  public:
  string name, department, designation;
  int Id, salary;
  Employee *next, *prev;
  void accept();
  void disp_asc();
  void disp_desc();
  void search(int Id);
  void update(int Id);
  void count();
}*start = NULL, *tail = NULL, *temp = NULL, *newnode = NULL;

void Employee::accept() {
    newnode = new Employee();
    cout << "Enter name: ";
    cin >> newnode->name;
    cout << "Enter department: ";
    cin >> newnode->department;
    cout << "Enter designation: ";
    cin >> newnode->designation;
    cout << "Enter employee ID: ";
    cin >> newnode->Id;
    cout << "Enter salary: ";
    cin >> newnode->salary;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(start == NULL) {
        start = tail = newnode;
        newnode->next = start;
        newnode->prev = start;
    }
    else {
        temp = start;
        while(temp->next != start){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = start;
        start->prev = newnode;
        tail = newnode;
    }
}

void Employee::disp_asc() {
    temp = start;
    do {
        cout << "Name: " << temp->name << endl;
        cout << "Department: " << temp->department << endl;
        cout << "Designation: " << temp->designation << endl;
        cout << "Employee ID: " << temp->Id << endl;
        cout << "Salary: " << temp->salary << endl;
        temp = temp->next;
        cout << endl;
    } while(temp != start);
}

void Employee::disp_desc() {
    temp = tail;
    do {
        cout << "Name: " << temp->name << endl;
        cout << "Department: " << temp->department << endl;
        cout << "Designation: " << temp->designation << endl;
        cout << "Employee ID: " << temp->Id << endl;
        cout << "Salary: " << temp->salary << endl;
        temp = temp->prev;
        cout << endl;
    } while(temp != tail);
}

void Employee::search(int Id) {
    temp = start;
    do {
        if(temp->Id == Id) {
            cout << "Name: " << temp->name << endl;
            cout << "Department: " << temp->department << endl;
            cout << "Designation: " << temp->designation << endl;
            cout << "Employee ID: " << temp->Id << endl;
            cout << "Salary: " << temp->salary << endl;
            return;
        }
        temp = temp->next;
    } while(temp != start);
    cout << "Employee not found." << endl;
}

void Employee::update(int Id) {
    temp = start;
    do {
        if(temp->Id == Id) {
            cout << "Enter new name: ";
            cin >> temp->name;
            cout << "Enter new department: ";
            cin >> temp->department;
            cout << "Enter new designation: ";
            cin >> temp->designation;
            cout << "Enter new employee ID: ";
            cin >> temp->Id;
            cout << "Enter new salary: ";
            cin >> temp->salary;
            return;
        }
        temp = temp->next;
    } while(temp != start);
    cout << "Employee not found." << endl;
}

void Employee::count() {
    temp = start;
    int count = 0;
    do {
        count++;
        temp = temp->next;
    } while(temp != start);
    cout << "Number of employees: " << count << endl;
}

int main() {
    Employee e;
    int choice;
    int Id;
    do {
        cout << "1. Add employee" << endl;
        cout << "2. Display employees in ascending order" << endl;
        cout << "3. Display employees in descending order" << endl;
        cout << "4. Search employee" << endl;
        cout << "5. Update employee" << endl;
        cout << "6. Count employees" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                e.accept();
                break;
            case 2:
                e.disp_asc();
                break;
            case 3:
                e.disp_desc();
                break;
            case 4:
                cout << "Enter employee ID: ";
                cin >> Id;
                e.search(Id);
                break;
            case 5:
                cout << "Enter employee ID: ";
                cin >> Id;
                e.update(Id);
                break;
            case 6:
                e.count();
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice." << endl;
        }
    } while(1);
    return 0;
}