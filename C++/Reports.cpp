#pragma once

#include <iostream>
#include <vector>
using namespace std;

struct dateTime
{
   int min;
   int hour;
   int day;
   int month;
   int year;
};

struct Emergency
{
    dateTime dt;
    string title;
    string description;
    string followup;
    string status;
    
};

class Reports
{
private:
    vector<Emergency> emergencies;
    
public:
    Reports()
    {
        for (int i=0; i<5; i++)
        {
            generateReport();
        }
        
        cout << endl << "Emergency Reports \n";
        if (emergencies.size() == 0)
        {
            cout << "No reports are available. \n\n";
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
        else
        {
            display();
        }
        
    }
    
    void display()
    {
        for (int i=0; i<emergencies.size(); i++)
        {
            cout << endl << i << ". " << emergencies[i].dt.day << "-" << emergencies[i].dt.month << "-" << emergencies[i].dt.year;
        }
        
        cout << "\n5. Return to Previous Menu. \n";
        int i;
        cin >> i;
        
        if (i == 5)
        {
            return;
        }
        else
        {
            cout << endl << emergencies[i].dt.day << "-" << emergencies[i].dt.month << "-" << emergencies[i].dt.year << endl;
            cout << emergencies[i].title << endl;
            cout << "Time of Incident: " << emergencies[i].dt.hour << ":" << emergencies[i].dt.min << endl;
            cout << "Incident Description: " << emergencies[i].description << endl;
            cout << "Required Follow Up Action: " << emergencies[i].followup << endl;
            cout << "Incident Status: " << emergencies[i].status << endl << endl;
            cout << "Enter -1 to Return to Previous Menu.\n";
            int r;
            do{
                cin >> r;
                
                if (r == -1)
                {
                    return;
                }
                
            }while (r != -1);
        }
    }
    
    void generateReport()
    {
        Emergency emergency;
        
        emergency.dt.day = rand() % 29 + 1;
        emergency.dt.month = rand() % 11 + 1;
        emergency.dt.year = rand() % 3 + 2019;
        emergency.dt.hour = rand() % 23 + 1;
        emergency.dt.min = rand() % 59 + 1;
        
        string titles[4];
        titles[0] = "Temperature Incident";
        titles[1] = "Low Oxygen Levels";
        titles[2] = "High Blood Pressure";
        titles[3] = "Collapse Hazard";
        emergency.title = titles[rand() % 4];
        
        string status[2];
        status[0] = "Pending";
        status[1] = "Resolved";
        emergency.status = status[rand() % 2];
        
        emergencies.push_back(emergency);
    }
    
    
    
};
