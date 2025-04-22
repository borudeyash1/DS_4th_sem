/* Assignment 6

Definition:
A medical record system is a software application used to manage medical records, including patient information, medical history, and treatment plans.
A hash table can be used as a data structure to efficiently store and retrieve medical records. */

#include <iostream>
using namespace std;

class MedicalRecord
{
    int id[20], c[20], n;
    string name[20], history[20], plan[20];
    int age[20];
    int loc;

public:
    void table();
    void accept();
    void display();
    void search();
    void modify();
    void deleteRecord();
};

void MedicalRecord::table()
{
    cout << "Enter number of records: ";
    cin >> n;
    for (int i = 0; i < 10; i++)
    {
        c[i] = -1;
    }
    cout << "Enter the IDs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> id[i];
    }
}

void MedicalRecord::accept()
{
    for (int i = 0; i < n; i++)
    {
        loc = id[i] % 10;
        while (c[loc] != -1)
        {
            loc = (loc + 1) % 10;
        }
        c[loc] = i;

        cout << "Enter Name: ";
        cin >> name[i];
        cout << "Enter Age: ";
        cin >> age[i];
        cout << "Enter Medical History: ";
        cin.ignore();
        getline(cin, history[i]);
        cout << "Enter Treatment Plan: ";
        getline(cin, plan[i]);
    }
}

void MedicalRecord::display()
{
    cout << "| ID | Name | Age | Medical History | Treatment Plan |\n";
    cout << "-----------------------------------------------------\n";
    for (int i = 0; i < 10; i++)
    {
        if (c[i] != -1)
        {
            int index = c[i];
            cout << "| " << id[index] << " | " << name[index] << " | " << age[index]
                 << " | " << history[index] << " | " << plan[index] << " |\n";
        }
    }
}

void MedicalRecord::search()
{
    int k;
    cout << "Enter ID to search: ";
    cin >> k;
    loc = k % 10;
    while (c[loc] != -1 && id[c[loc]] != k)
    {
        loc = (loc + 1) % 10;
        if (loc == k % 10)
        {
            cout << "Record not found.\n";
            return;
        }
    }
    if (c[loc] == -1)
    {
        cout << "Record not found.\n";
    }
    else
    {
        int index = c[loc];
        cout << "Record found:\n";
        cout << "| ID | Name | Age | Medical History | Treatment Plan |\n";
        cout << "-----------------------------------------------------\n";
        cout << "| " << id[index] << " | " << name[index] << " | " << age[index]
             << " | " << history[index] << " | " << plan[index] << " |\n";
    }
}

void MedicalRecord::modify()
{
    int k;
    cout << "Enter ID to modify: ";
    cin >> k;
    loc = k % 10;
    while (c[loc] != -1 && id[c[loc]] != k)
    {
        loc = (loc + 1) % 10;
        if (loc == k % 10)
        {
            cout << "Record not found.\n";
            return;
        }
    }
    if (c[loc] == -1)
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
        cout << "Enter new Medical History: ";
        cin.ignore();
        getline(cin, history[index]);
        cout << "Enter new Treatment Plan: ";
        getline(cin, plan[index]);
        cout << "Record modified successfully!\n";
    }
}

void MedicalRecord::deleteRecord()
{
    int k;
    cout << "Enter ID to delete: ";
    cin >> k;
    loc = k % 10;
    while (c[loc] != -1 && id[c[loc]] != k)
    {
        loc = (loc + 1) % 10;
        if (loc == k % 10)
        {
            cout << "Record not found.\n";
            return;
        }
    }
    if (c[loc] == -1)
    {
        cout << "Record not found.\n";
    }
    else
    {
        c[loc] = -1;
        cout << "Record deleted successfully!\n";
    }
}

int main()
{
    MedicalRecord m;
    int choice;
    do
    {
        cout << "\n--- Patient History ---\n";
        cout << "1. Accept Records\n2. Display Records\n3. Search Record\n4. Modify Record\n5. Delete Record\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            m.table();
            m.accept();
            break;
        case 2:
            m.display();
            break;
        case 3:
            m.search();
            break;
        case 4:
            m.modify();
            break;
        case 5:
            m.deleteRecord();
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