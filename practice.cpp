#include<iostream>
using namespace std;

class Employee{
    public:
    string name,department,designation;
    int Id,salary;
    Employee *next, *prev;
    void accept();
    void disp_asc();
    void disp_desc(); 
    void search(int Id);
    void update(Int Id);
    void count();


}*start = NULL , *tail =NULL, *temp = NULL, *newnode = NULL ;

void Employee::accept(){
    newnode = new salary
}