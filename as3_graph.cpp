/*
Assignement No : 3
Problem Statement : There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities.
The cost of the edge can be the time that flight takes to reach city B from A or the amount of fuel used for the journey. The node can be
represented by airport name or name of the city. Use adjacency list representation of the graph and adjacency matrix representation of the graph.
Justify the storage representation used
*/
// using the advancency matrix
#include <iostream>
using namespace std;
class AMS
{
public:
    int numofcities;
    string cities[100];
    int adj[100][100];
    void accept()
    {
        cout << "Enter total Number of Cities to accept : ";
        cin >> numofcities;

        for (int i = 0; i < numofcities; i++)
        {
            cout << "Enter " << i << " Cities :";
            cin >> cities[i];
        }

        for (int j = 0; j < numofcities; j++)
        {  
            for (int k = 0; k < numofcities; k++)
            {
                if (cities[j] == cities[k])
                {
                    adj[j][k] = 0;
                }

                else
                {
                    cout << "Enter Fuel require for " << cities[j] << " to " << cities[k] << " : ";
                    cin >> adj[j][k];
                }
            }
        }
    }

    void display()
    {
        cout << "\nAdjacency Matrix (Fuel between Cities):\n";
        cout << "\t";
        for (int j = 0; j < numofcities; j++)
        {
            cout << cities[j] << "\t";
        }
        cout << endl;
        for (int i = 0; i < numofcities; i++)
        {
            cout << cities[i] << "\t";
            for (int j = 0; j < numofcities; j++)
            {
                if (cities[i] == cities[j])
                {
                    cout << "0\t";
                }
                else
                {
                    cout << adj[i][j] << "\t";
                }
            }
            cout << endl;
        }
        /*
              a b c d
            a 0 6 2 1
            b 6 0 5 3
            c 2 5 0 9
            d 1 3 9 0

            to enter
            12,13,14
            23,24
            34

            to skip - 11,22,33,44

            row = limit -1
            column = row + (j++)      //means j will be 1,2,3,4...

            for(int i =0;i<limit;i++){
              for(int j =i++;j<limit;j++){
                  if(cities[i] == cities[j]){
                      //---
                  }

              }
            }
          */
    }

} flight;

int main()
{
    flight.accept();
    flight.display();
    return 0;
}