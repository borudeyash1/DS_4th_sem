/*A student record system is a software application used to manage student records, including student information and their 10th and 12th results.
Hash tables can be used as a data structure to efficiently store and retrieve student records.*/

#include <iostream>
using namespace std;

class StudentRecord
{
    int id[20], c[20], n;
    string name[20];
    int age[20], tenthMarks[20], twelfthMarks[20];
    int loc;

public:
    void table();
    void accept();
    void display();
    void search();
    void modify();
    void deleteRecord();
};

void StudentRecord::table()
{
    cout << "Enter number of records: ";
    cin >> n;
    for (int i = 0; i < 10; i++)
    {
        c[i] = -2;
    }
}

void StudentRecord::accept()
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the ID: ";
        cin >> id[i];
        loc = id[i] % 10;
        while (c[loc] != -2)
        {
            loc = (loc + 1) % 10;
        }
        c[loc] = i;

        cout << "Enter Name: ";
        cin >> name[i];
        cout << "Enter Age: ";
        cin >> age[i];
        cout << "Enter 10th Marks: ";
        cin >> tenthMarks[i];
        cout << "Enter 12th Marks: ";
        cin >> twelfthMarks[i];
    }
}

void StudentRecord::display()
{
    cout << "| ID  | Name | Age | 10th | 12th |\n";
    cout << "----------------------------------\n";
    for (int i = 0; i < 10; i++)
    {
        if (c[i] != -2)
        {
            int index = c[i];
            cout << "| " << id[index] << " | " << name[index] << " | " << age[index]
                 << " | " << tenthMarks[index] << " | " << twelfthMarks[index] << " |\n";
        }
    }
}

void StudentRecord::search()
{
    int k;
    cout << "Enter ID to search: ";
    cin >> k;
    loc = k % 10;
    while (c[loc] != -2 && id[c[loc]] != k)
    {
        loc = (loc + 1) % 10;
        if (loc == k % 10)
        {
            cout << "Record not found.\n";
            return;
        }
    }
    if (c[loc] == -2)
    {
        cout << "Record not found.\n";
    }
    else
    {
        int index = c[loc];
        cout << "Record found:\n";
        cout << "| ID | Name | Age | 10th | 12th |\n";
        cout << "----------------------------------\n";
        cout << "| " << id[index] << " | " << name[index] << " | " << age[index]
             << " | " << tenthMarks[index] << " | " << twelfthMarks[index] << " |\n";
    }
}

void StudentRecord::modify()
{
    int k;
    cout << "Enter ID to modify: ";
    cin >> k;
    loc = k % 10;
    while (c[loc] != -2 && id[c[loc]] != k)
    {
        loc = (loc + 1) % 10;
        if (loc == k % 10)
        {
            cout << "Record not found.\n";
            return;
        }
    }
    if (c[loc] == -2)
    {
        cout << "Record not found.\n";
    }
    else
    {
        int index = c[loc];
        cout << "Enter new Name: ";
        cin >> name[index];
        cout << "Enter new Age: ";
        cin >> age[index];
        cout << "Enter new 10th Marks: ";
        cin >> tenthMarks[index];
        cout << "Enter new 12th Marks: ";
        cin >> twelfthMarks[index];
        cout << "Record modified successfully!\n";
    }
}

void StudentRecord::deleteRecord()
{
    int k;
    cout << "Enter ID to delete: ";
    cin >> k;
    loc = k % 10;
    while (c[loc] != -2 && id[c[loc]] != k)
    {
        loc = (loc + 1) % 10;
        if (loc == k % 10)
        {
            cout << "Record not found.\n";
            return;
        }
    }
    if (c[loc] == -2)
    {
        cout << "Record not found.\n";
    }
    else
    {
        c[loc] = -2;
        cout << "Record deleted successfully!\n";
    }
}

int main()
{
    StudentRecord s;
    int choice;
    do
    {
        cout << "\n--- Student Scorecard ---\n";
        cout << "1. Accept Records\n2. Display Records\n3. Search Record\n4. Modify Record\n5. Delete Record\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.table();
            s.accept();
            break;
        case 2:
            s.display();
            break;
        case 3:
            s.search();
            break;
        case 4:
            s.modify();
            break;
        case 5:
            s.deleteRecord();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    } while (choice != 6);

    return 0;
}