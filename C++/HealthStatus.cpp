#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class HealthStatus
{
    
public:
    
    void on()
    {
        srand(time(0));
        cout << endl << "Health Status \n\n";
        
        cout << "Blood Oxygen Level \n";
        cout << rand()%10 + 90 << endl << endl;
        
        cout << "Body Temperature \n";
        cout << (rand()%10 + 360)/10.0 << endl << endl;
        
        cout << "Heart Rate \n";
        cout << rand()%30 + 60 << endl << endl << endl;
        
        cout << "Enter -1 to Return \n";
        
        int r;
        do{
            cin >> r;
            
            if (r == -1)
            {
                return;
            }
            
        }while (r != -1);
    }
    
    
};
