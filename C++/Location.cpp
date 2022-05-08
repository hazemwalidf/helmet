#pragma once

#include <iostream>
using namespace std;

class Location
{
    
public:
    void on()
    {
        int r;
        cout << endl << "Live Location \n\n";
        cout << "Enter -1 to Return \n";
        
        do{
            cin >> r;
            
            if (r == -1)
            {
                return;
            }
            
        }while (r != -1);
    }
};
