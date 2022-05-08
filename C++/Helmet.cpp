#pragma once

#include <iostream>
#include <ctime>
#include "Camera.cpp"
#include "Location.cpp"
#include "HealthStatus.cpp"
#include "Feedback.cpp"
using namespace std;

class Helmet
{
    
public:

    Helmet(bool admin)
    {
        if (!admin)
        {
            while (true)
            {
                switch (workerOptions())
                {
                    case 1:
                        Camera camera;
                        camera.on();
                        break;
                        
                    case 2:
                        Location location;
                        location.on();
                        break;
                        
                    case 3:
                        HealthStatus health;
                        health.on();
                        break;
                        
                    case 4:
                        Feedback feedback;
                        feedback.send();
                        break;
                        
                    case 5:
                        return;
                        break;
                }
            }
        }
        else
        {
            int employeeID[5];
            int choice;
            displayWorkers(employeeID);
            cout << "6. Return to previous menu \n\n";
            cin >> choice;
            
            if (choice < 6)
            {
                cout << "Employee ID: " << employeeID[choice] << endl;
                Helmet(0);
            }
            else return;
            
        }
        
    }
    
    void displayWorkers(int array[])
    {
        srand(time(0));
        for (int i=0; i<5; i++)
        {
            array[i] = rand() % 2000 + 2000;
        }
        
        for (int i=0; i<5; i++)
        {
            cout << i+1 << ". Employee ID: " << array[i] << endl;
        }
    }
    
    
    int workerOptions()
    {
        int option;
        cout << endl << "Smart Helmet: On" << endl;
        cout << "1. Live Camera \n";
        cout << "2. Live Location \n";
        cout << "3. Health Status \n";
        cout << "4. Feedback \n";
        cout << "5. Return to previous menu \n";
        cin >> option;
        
        while ( (option > 5) || (option < 1) )
        {
            cout << "Invalid input. Please enter again. \n";
            cin >> option;
        }
        
        return option;
    }
    
    
    
    
};
