/* Assignment 6

Definition:
A medical record system is a software application used to manage medical records, including patient information, medical history, and treatment plans.
A hash table can be used as a data structure to efficiently store and retrieve medical records. */

#include <iostream>
using namespace std;

class MedicalRecord {
    int id[20], c[20], n; // ID array and hash table for indexing
    string name[20], history[20], plan[20]; // Store name, history, and plan in arrays
    int age[20];
    int loc;
public:
    void table();
    void accept();
    void display();
    void search();
};

void MedicalRecord::table() {
    cout << "Enter number of records: ";
    cin >> n;
    
    for (int i = 0; i < 10; i++) {
        c[i] = -1; // Initialize hash table with -1
    }
    
    cout << "Enter the IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> id[i];
    }
}

void MedicalRecord::accept() {
    for (int i = 0; i < n; i++) {
        loc = id[i] % 10;
        while (c[loc] != -1) {
            loc = (loc + 1) % 10; // Linear probing for collision handling
        }
        c[loc] = i; // Store index of patient details

        cout << "Enter the name of the patient: ";
        cin >> name[i];
        cout << "Enter the age of the patient: ";
        cin >> age[i];
        cout << "Enter the medical history of the patient: ";
        cin.ignore();
        getline(cin, history[i]);
        cout << "Enter the treatment plan of the patient: ";
        getline(cin, plan[i]);
    }
}

void MedicalRecord::display() {
    cout << "The records are:\n";
    cout << "| ID | Index | Name | Age | Medical History | Treatment Plan |\n";
    cout << "---------------------------------------------------------------\n";
    
    for (int i = 0; i < 10; i++) {
        if (c[i] != -1) {
            int index = c[i];
            cout << "| " << id[index] << " | " << index << " | " << name[index] << " | " << age[index] << " | " << history[index] << " | " << plan[index] << " |\n";
        }
    }
    cout<<"\n";

}

void MedicalRecord::search() {
    int k;
    cout << "Enter the Patient ID to be searched: ";
    cin >> k;
    
    loc = k % 10;
    int start = loc;

    while (c[loc] != -1 && id[c[loc]] != k) {
        loc = (loc + 1) % 10;
        if (loc == start) {
            cout << "Record not found.\n";
            return;
        }
    }

    if (c[loc] == -1) {
        cout << "Record not found.\n";
    } else {
        int index = c[loc];
        cout << "The record is:\n";
        cout << "| ID | Index | Name | Age | Medical History | Treatment Plan |\n";
        cout << "---------------------------------------------------------------\n";
        cout << "| " << id[index] << " | " << index << " | " << name[index] << " | " << age[index] << " | " << history[index] << " | " << plan[index] << " |\n";
    }
    cout<<"\n";

}

int main() {
    MedicalRecord m;
    int choice;
    do {
        cout<<"---Patient History---"<<endl;
        cout << "\n1. Accept the records\n2. Display the records\n3. Search the records\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
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
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 4);

    return 0;
}