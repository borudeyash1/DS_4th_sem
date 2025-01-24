#include<iostream>
using namespace std;

class Employee {
  public:
  string name, department, designation;
  int employeeId, salary;
  Employee *next;
  void accept();
  void display();
  void search(int employeeId);
  void update(int employeeId);
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
    cin >> newnode->employeeId;
    cout << "Enter salary: ";
    cin >> newnode->salary;
    newnode->next = NULL;

    if(start == NULL) {
        start = tail = newnode;
        newnode->next = start;
    }
    else {
        temp = start;
        while(temp->next != start){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = start;
        tail = newnode;
    }
}

void Employee::display() {
    temp = start;
    do {
        cout << "Name: " << temp->name << endl;
        cout << "Department: " << temp->department << endl;
        cout << "Designation: " << temp->designation << endl;
        cout << "Employee ID: " << temp->employeeId << endl;
        cout << "Salary: " << temp->salary << endl;
        temp = temp->next;
        cout << endl;
    } while(temp != start);
}

void Employee::search(int employeeId) {
    temp = start;
    do {
        if(temp->employeeId == employeeId) {
            cout << "Name: " << temp->name << endl;
            cout << "Department: " << temp->department << endl;
            cout << "Designation: " << temp->designation << endl;
            cout << "Employee ID: " << temp->employeeId << endl;
            cout << "Salary: " << temp->salary << endl;
            return;
        }
        temp = temp->next;
    } while(temp != start);
    cout << "Employee not found." << endl;
}

void Employee::update(int employeeId) {
    temp = start;
    do {
        if(temp->employeeId == employeeId) {
            cout << "Enter new name: ";
            cin >> temp->name;
            cout << "Enter new department: ";
            cin >> temp->department;
            cout << "Enter new designation: ";
            cin >> temp->designation;
            cout << "Enter new employee ID: ";
            cin >> temp->employeeId;
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
    int employeeId;
    do {
        cout << "1. Add employee" << endl;
        cout << "2. Display employees" << endl;
        cout << "3. Search employee" << endl;
        cout << "4. Update employee" << endl;
        cout << "5. Count employees" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                e.accept();
                break;
            case 2:
                e.display();
                break;
            case 3:
                cout << "Enter employee ID: ";
                cin >> employeeId;
                e.search(employeeId);
                break;
            case 4:
                cout << "Enter employee ID: ";
                cin >> employeeId;
                e.update(employeeId);
                break;
            case 5:
                e.count();
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice." << endl;
        }
    } while(1);
    return 0;
}