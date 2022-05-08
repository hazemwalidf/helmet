#pragma once

#include <iostream>
#include "Projects.cpp"
#include "Helmet.cpp"
#include "User.cpp"
#include "Reports.cpp"
using namespace std;

class Worker : public User
{
public:
    
    void options()
    {
        int option;
        cout << "1. Projects" << endl;
        cout << "2. Smart Helmet" << endl;
        cout << "3. Emergency Report" << endl;
        cin >> option;
        
        if (option == 1)
        {
            Projects projects;
        }
        
        if (option == 2)
        {
            Helmet helmet(0);
        }
        
        if (option == 3)
        {
            Reports report;
        }
    }
    
};
