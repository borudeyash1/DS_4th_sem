
#include<iostream>

using namespace std;

class FMS{
    int fuel;
    string city;
    FMS* next;

public:
    void accept(int);
    void insertEdge(int);
    void display(int);
    void createList(int);
};

void FMS::accept(int num_city){
    FMS* ptr = this;
    for(int i=0;i<num_city;i++){
        cout<<"Enter the city name : ";
        string city_name;
        cin>>city_name;
        FMS* temp = new FMS();
        temp->city = city_name;
        temp->fuel = 0;
        temp->next = NULL;
        if(ptr->next == NULL){
            ptr->next = temp;
        } else {
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
}

void FMS::insertEdge(int num_city){
    int cost;
    string src,dest;
    cout<<"Enter the source city : ";
    cin>>src;
    cout<<"Enter the destination city : ";
    cin>>dest;
    cout<<"Enter the cost : ";
    cin>>cost;
    FMS* ptr = this;
    while(ptr != NULL){
        if(ptr->city == src){
            FMS* temp = new FMS();
            temp->fuel = cost;
            temp->next = NULL;
            temp->city = dest;
            FMS* temp2 = ptr;
            while(temp2->next != NULL){
                temp2 = temp2->next;
            }
            temp2->next = temp;
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL){
        cout<<"Invalid source city. Please enter a valid city "<<endl;
    }
}

void FMS::display(int num_city){
    FMS* ptr = this;
    while(ptr != NULL){
        cout << "City: " << ptr->city << "\tFuel: " << ptr->fuel << endl;
        ptr = ptr->next;
    }
}

void FMS::createList(int num_city){
    accept(num_city);
    int num_edges;
    cout<<"Enter the number of edges : ";
    cin>>num_edges;
    for(int i=0;i<num_edges;i++){
        insertEdge(num_city);
    }
}

int main(){
    int num_city;
    cout<<"Enter the number of cities : ";
    cin>>num_city;
    FMS* head = new FMS();
    head->createList(num_city);
    int choice;
    while(1){
        cout<<"1. Display List\n2. Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
                head->display(num_city);
                break;
            case 2:
                exit(0);
            default:
                cout<<"Invalid choice\n";
        }
    }
    return 0;
}
