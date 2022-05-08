#pragma once

#include <iostream>
using namespace std;

class Camera
{
    
    
public:
    
    void on()
    {
        
        cout << endl << "360 Camera \n\n";
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
