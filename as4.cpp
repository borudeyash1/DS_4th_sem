/*You are a job seeker preparing for interviews in different locations. You have a list of cities where interviews 
are scheduled and you want to find the shortest path to visit all the interview locations starting from your current
0location. The objective is to minimize the total travel distance and time while ensuring you reach each interview
location on time. Use an appropriate data structure and algorithm to implement it.*/

#include<iostream>
using namespace std;

class Interview{
    public:
    string city;
    int distance;
    int time;
    bool isVisited;

    void accept(){
        cout<<"Enter the city name : ";
        cin>>city;
        cout<<"Enter the distance : ";
        cin>>distance;
        cout<<"Enter the time : ";
        cin>>time;
        isVisited = false;
    }
    void visit(){
        
        isVisited = true;
    
    }
};
int main{

    return 0;
}