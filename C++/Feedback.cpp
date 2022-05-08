#pragma once

#include <iostream>
using namespace std;

class Feedback
{
    
public:
    
    void send()
    {
        string reply;
        cout << endl << "Feedback" << endl << endl;
        cout << "Posted by the manager" << endl;
        cout << "I will send more workers on site, because there aren't enough and this can result in a delay of work. \n\n";
        cout << "Enter your reply. \n";
        cin >> reply;
        cout << endl << "Reply Received. \n\n";
        cout << "Enter -1 to return. \n";
        
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
